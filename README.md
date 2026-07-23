# 📖 Dictionary Spell Checker in C

A command-line dictionary and spell checker built in **C** using an **AVL Tree (Self-Balancing Binary Search Tree)** for fast and efficient word searching.

The program loads words from a dictionary text file into an AVL tree, allowing quick lookups while keeping the tree balanced. Users can enter a sentence, and each word is checked against the dictionary. If a word is not found, the program provides three suggestions based on the tree structure: the last visited node, the predecessor, and the successor.

---

## ✨ Features

- Load words from `Dictionary.txt`
- Store words in an AVL Tree
- Fast word lookup
- Check every word in a user-entered sentence
- Detect correct and incorrect words
- Provide spelling suggestions:
  - Last visited node
  - Predecessor
  - Successor
- Automatic AVL tree balancing
- Proper dynamic memory management

---

## 🛠 Technologies Used

- C Programming Language
- AVL Tree
- File Handling
- Dynamic Memory Allocation
- String Manipulation

---

## 📚 Data Structures & Algorithms

### Data Structure
- AVL Tree (Self-Balancing Binary Search Tree)

### Algorithms
- AVL Tree Insertion
- AVL Tree Search
- Left Rotation
- Right Rotation
- Predecessor Search
- Successor Search

---

## ⚙️ How It Works

1. Read all words from `Dictionary.txt`.
2. Insert each word into an AVL Tree.
3. Display the dictionary size and tree height.
4. Ask the user to enter a sentence.
5. Search every word in the sentence.
6. Print whether each word is correct or incorrect.
7. If incorrect, display three possible suggestions.

---

## 🚀 How to Run

### Compile

```bash
gcc main.c -o dictionary
```

### Run

**Linux/macOS**

```bash
./dictionary
```

**Windows**

```bash
dictionary.exe
```

---

## 💻 Example Output

```text
Dictionary Loaded Successfully!!
Size = 97462
Height = 20

Enter a sentence:
helo world computer

helo is incorrect
Suggestion A (last visited): help
Suggestion B (predecessor): held
Suggestion C (successor): hello

world is correct
computer is correct
```

---

## 📂 Project Structure

```text
Dictionary-Spell-Checker/
│
├── main.c
├── Dictionary.txt
├── dictionary.cbp
├── .gitignore
└── README.md
```

---

## 🎯 Learning Outcomes

This project helped me practice:

- AVL Trees
- Binary Search Trees
- Searching algorithms
- Tree rotations
- Dynamic memory allocation
- File handling in C
- Building console-based applications

---

## 👨‍💻 Author

**Yassin Tarek**

Engineering Student | Computer and Communications Engineering

---
