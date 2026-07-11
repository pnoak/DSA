# Assignment 14: Circular Singly Linked List Fundamentals

## Objective

Implement a **Circular Singly Linked List (CLL)** that supports insertion at the end, traversal, and complete memory deallocation.

The goal of this assignment is to understand how a Circular Linked List differs from a traditional Singly Linked List and how traversal logic changes when the last node points back to the head node.

---

## Requirements

Implement the following functions:

```c
bool appendCLL(node **headref, int val);

void displayC**(node *head);

void freeCLL(node ***eadref);
```

---

## Constraints

### Do Not Use

```c
array indexing
global variables
static storage for nodes
```

### Must Use

```c
malloc()
free()
pointer traversal
dynamic memory allocation
```

---

## Expected Learning Outcomes

After completing this assignment, you should be able to:

- Understand the structure of a Circular Linked List.
- Handle self-referencing nodes.
- Traverse a circular structure safely.
- Identify the last node using circular conditions.
- Maintain circular integrity during insertion.
- Properly release dynamically allocated memory.

---

## Rule

Ensure the program compiles without warnings and runs correctly for all specified test cases.

---
