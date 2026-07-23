#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *word;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node* N)
{
    if (N == NULL)
        return 0;

    return N->height;
}

Node* newNode(char *word)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->word = (char*)malloc(strlen(word) + 1);
    strcpy(node->word, word);

    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* N)
{
    if (N == NULL)
        return 0;

    return height(N->left) - height(N->right);
}

Node* insert(Node* node, char *word)
{
    if (node == NULL)
        return newNode(word);

    if (stricmp(word, node->word) < 0)
        node->left = insert(node->left, word);

    else if (stricmp(word, node->word) > 0)
        node->right = insert(node->right, word);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && stricmp(word, node->left->word) < 0)
        return rightRotate(node);

    // Right Right
    if (balance < -1 && stricmp(word, node->right->word) > 0)
        return leftRotate(node);

    // Left Right
    if (balance > 1 && stricmp(word, node->left->word) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left
    if (balance < -1 && stricmp(word, node->right->word) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%s\n", root->word);
        inorder(root->right);
    }
}

void freeTree(Node* root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);

    free(root->word);
    free(root);
}

Node* search(Node* root, char *word, Node **last)
{
    Node* current = root;
    *last = NULL;
    while (current != NULL)
    {
    *last = current;
    if (stricmp(word, current->word) == 0)
        return current;

    else if (stricmp(word, current->word) < 0)
        current = current->left;

    else
        current = current->right;
    }
    return NULL;
}

Node* findMax(Node* root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

Node* predecessor(Node* root, char *word){

Node* pred = NULL;
while (root)
{
    if (stricmp(word, root->word) > 0){
        pred = root;
        root = root->right;
    }
    else{
        root = root->left;
    }
    }
    return pred;
}

Node* findMin(Node* root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node* successor(Node* root, char *word)
{
    Node* succ = NULL;

    while (root){
if (stricmp(word, root->word) < 0){
        succ = root;
        root = root->left;
    }
    else{
        root = root->right;
    }
    }
    return succ;
}

int main()
{
    FILE *fp;
    char word[100];
    Node *root = NULL;
    int count = 0;
    char sentence[500];
    fp = fopen("Dictionary.txt", "r");

    while (fgets(word, sizeof(word), fp) != NULL)
        {
        word[strcspn(word, "\n")] = '\0';
        root = insert(root, word);
        count++;
        }
    fclose(fp);
    printf("Dictionary Loaded Successfully!!\n");
    printf("Size = %d\n",count);
    printf("height = %d\n",root->height);
    printf("enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");

while (token != NULL)
{
    Node *last = NULL;
    Node *found = search(root, token, &last);
    if (found){
        printf("%s is correct\n", token);
    }
    else{
    printf("%s is incorrect\n", token);
    printf("Suggestion A (last visited): %s\n", last ? last->word : "NULL");
    Node *pred = predecessor(root, token);
    Node *succ = successor(root, token);
    printf("Suggestion B (predecessor): %s\n", pred ? pred->word : "NULL");
    printf("Suggestion C (successor): %s\n", succ ? succ->word : "NULL");
    }
    token = strtok(NULL, " ");
    }
    freeTree(root);
    return 0;
}
