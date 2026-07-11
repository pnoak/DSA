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

## Test Cases
***# Test Case 1: Empty Display

``***xt
Input:
2

Expected:
List is E***y
```

---

### Test Case 2: First Insertion

```text
Append: 10

E***cted:
Head -> 10
10 points to it***f
```

---

### Test Case 3: Multiple Insertions

```text
Append: 1***ppend: 20
Append: 30
Display
```***xpected Output:

```text
Node 0: 10
Node 1: 20
Node 2: 30
Total Number Of Nodes: 3
```

---

### Test Case 4: Free Entire List

```text
Append 10
Append 20
Append 30
Free List
Display
```

Expected Output:

```text
Node 0 freed.
Node 1 freed.
Node 2 freed.

List is Empty
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
