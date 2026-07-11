## Assignment 1: The Dynamic Integer Array (Warm-up)Objective:
 Handle basic dynamic allocation, resizing, and memory cleanup.Task: Write a program that prompts the user to enter N integers. Allocate memory dynamically for these N integers.Twist: After reading the initial N integers, ask the user for M additional integers. Resize the allocated memory block to hold N + M elements without losing the original data. Print the entire final array, and then free all allocated memory.


## Assignment 2: The String Concatenation Engine (Intermediate)
Objective: Avoid buffer overflows by calculating memory requirements dynamically at runtime.

Task: Create a function with the signature char* dynamic_concat(const char* str1, const char* str2).

Twist: Inside the function, calculate the exact length of both strings, allocate a precise amount of memory on the heap to store the combined string (plus the null-terminator \0), concatenate them, and return the pointer. In your main function, call this engine, print the result, and ensure no memory leaks occur.


## Assignment 3: Memory Layout Visualizer (Advanced)
Objective: Contrast the lifespans and addresses of static, stack, and heap memory.

**→ Task:**
*  Write a program that declares: A global initialized variable (Static/Data segment).
* A local variable inside main (Stack segment).
* A dynamically allocated variable using malloc() (Heap segment).

**→ Twist:** 
Print the hex memory addresses of all three variables. Write a secondary function that attempts to return the pointer of a local variable created inside it back to main, and observe what happens when you try to access it.


## Assignment 4: Building a Fixed-Size Array Container
Instead of moving straight to complex structures, let's write a clean, modular program that mimics how high-level languages handle arrays safely.

**→Your Task:**
* Write a C program that manages a fixed-size integer array using a structured approach. Do not use global variables.
* Define a Structure: Create a struct SafeArray that holds:
* A fixed integer array (e.g., size 5).
* An integer tracking the current_size (how many elements are actually filled).

**Implement an Append Function:** Write a function int append(struct SafeArray *array, int value) that adds an element to the next available slot. If the array is full, it should reject the input and return an error code.

**Implement a Safe Display Function:** Write a function to print the elements cleanly.

## Assignment 5: Building a Dynamic Vector Container
Write a modular C program that implements a custom integer Vector. 

* **Requirements:**
1. **Define the Structure:** Create a struct MyVector holding int *data, int size, and int capacity.
2. **Implement Initialization:** Write a function void vector_init(struct MyVector *v, int initial_capacity) that allocates the initial heap memory using malloc.
3. **Implement Append:** Write int vector_append(struct MyVector *v, int value) that adds elements and automatically doubles the capacity using realloc if the vector fills up.
4. Implement Display: Write a function to print the current size, capacity, and active elements cleanly.
5. Implement Cleanup: Write a function to free the heap memory when done to prevent leaks

## Assignment 6: Manual Node Assembly (The "Hard" Way)
Write loops or automated insertion functions, your task is to manually create three individual nodes on the heap, link them together by explicitly assigning their next pointers, and print their values.
This will force you to see exactly how pointers "chain" from one memory chunk to another.

**Your Objectives:**
1. **Define the Structure:** Declare the struct Node as shown above.
2. **Allocate Nodes:** Inside main(), create three distinct pointers: struct Node* first, struct Node* second, and struct Node* third. Allocate memory for each one individually using malloc().
3. **Assign Data:** Give each node a unique number (e.g., first->data = 10;, etc.).
4. **Wire Them Together (The Core Step):** 
   * Make first->next point to the address of second.
   * Make second->next point to the address of third.
   * Make third->next point to NULL (marking the end of the line).
5. **Print via the Chain:** Print the values of all three nodes, but here is the twist: you are only allowed to use the variable first inside your print statements.

6. **Hint:** To print the second node's data using only first, you will look at first->next->data.
7. **Clean Up:** Manually free() all three nodes before exiting.

## Assignment 7: Building a Dynamic Single Linked List Module

**Your Objectives:**
1. **Define the Node Structure:** Use the standard struct node pattern.
2. **Implement an Append Function:** Write void append(struct node head_ref, int value).
3. **Hint:** We pass a pointer-to-a-pointer (struct node) because if the list is empty, the function needs to directly modify the head pointer inside main().
4. **Implement a Traversal Display Function:** Write void display(struct node* head) that uses a while (current != NULL) loop to slide forward and print every active node's data field sequentially.
5. **Implement a Master Cleanup Function:** Write void free_list(struct node* head) that loops through the 
                            entire list and frees every node individually so you leave zero active blocks on the heap.

## Assignment 8: The Arbitrary Insertion Challenge
**Your Task:**  
Modify your existing Singly Linked List codebase by adding a highly robust insertion function.

**Requirements:**
1. **Implement the Insert Function:** Write bool insertAtPosition(Node headRef, int position, int value);.

2. **Interactive Menu:** Add a new option to your main() loop: 4) Insert at Position.

3. **Scan with Validation:** Prompt the user for both the target position (index) and the integer value. Validate both inputs using scanf safety patterns.

## Assignment 9: The Node Deletion Challenge
Incorporate a robust node deletion function into your current working Singly Linked List codebase.

**Requirements:**
   1. **Implement the Delete Function:** Write bool deleteAtPosition(Node headRef, int position);. It should return 
true on successful deletion and false if the position is out of bounds or the list is completely empty.

   2. **Interactive Menu Expansion:** Add a new option to your main() loop: 
    4) Delete at Position .

   3. **Scan Validation:** Prompt the user for the target index to delete and protect
     the entry using your standard scanf verification logic.

## Assignment 10: Manual DLL Assembly
****Your Objectives:****
1. **Define the Structure:** Create the typedef struct Node containing a prev pointer, data integer, and next pointer.

2. **Allocate 3 Nodes:** Create three local node pointers in main() (node1, node2, node3) and allocate their memory blocks individually using malloc(). Confirm they aren't NULL.

3. **Initialize the Data:** Load your payload values (e.g., 10, 20, 30) into each node's data field.

4. **Wire the Bi-directional Links explicitly:**

   1. Wire node1 forward to node2, and make its prev point to NULL.

   2. Wire node2 backward to node1 and forward to node3.

   3. Wire node3 backward to node2 and forward to NULL.

   4. Verify both Directions: * Print forward through the chain starting only from node1 (using node1->next->next->data).

   5. Print backward through the chain starting only from node3 (using node3->prev->prev->data).

5. **Clean Up safely:** free() all three nodes and defuse their pointers to NULL.

## Assignment 11: The Dynamic DLL Container Module
**Your Task:** Write a modular, interactive menu program that implements a custom dynamic integer Doubly Linked List.

**Requirements:**
1. **Define the Node Layout:** Use your established typedef struct doubleNode pattern.

2. **Implement Append:** Write bool dll_append(DLLNode headRef, int value);.

3. **Implement Dual Traversals:**

   1. void display_forward(DLLNode* head); -> Loops forward from head to tail using next.

   2. void display_reverse(DLLNode* head); -> Loops forward to find the tail first, then loops completely backward to the head using the prev pointers to print values.

4. **Implement Clean Freeing:** Write void free_dll(DLLNode headRef); that wipes all nodes safely and nullifies the main reference.

5. **Interactive Controller:** Build a while(true) terminal loop tracking options: 1) Append, 2) Display Forward, 3) Display Reverse, and 4) Exit. Validate user entry with scanf.

## Assignment 12: Dynamic Deletion from a Doubly Linked List. 
Deleting a node from a bi-directional structure requires you to detach both the forward (next) and backward (prev) links of adjacent nodes.

### The Structural Strategy
Imagine we want to delete Node B from a chain consisting of A <-> B <-> C:

1. **Isolate Head Exception:** If deleting position 0, slide head down to Node B, map head->prev = NULL, and free Node A.

2. **Target Traversal:** Run a loop to find Node B directly.

3. **Unlink the Backward Connection:** Route Node A forward past Node B to point at Node C:

      ```B->prev->next = B->next; // A's next pointer now bypasses B and points to C```

4. **Unlink the Forward Connection:** If Node C exists (i.e., Node B is not the tail), route Node C's backward link past Node B to point directly at Node A:

      ```B->next->prev = B->prev; // C's prev pointer now bypasses B and points to A```

5. **Reclaim Memory:** Safe to execute free(B).

## Assignment 13: The Complete DLL Insertion Module

1. **Your Task:** Incorporate a robust arbitrary positioning function into your Doubly Linked List code base.

2. **Requirements:**
3. **Implement the Function:** Write bool DLLInsert(node headref, int val, int pos);. It should return true on success and false if the position is out of bounds or negative.

4. **Interactive Menu Expansion:** Add a new option to your main console loop: 2) Insert Node at specified position. (Shift your subsequent display, delete, and exit menu option numbers downward accordingly).

5. **Input Validation:** Prompt the user for both the integer value and target position, protecting inputs with your standard scanf error traps

## Assignment 14: Manual Circular Assembly to practice handling loop execution paths safely.

### Assignment Specifications:
1. **Define the Layout:** Use a classic single-direction structure blueprint:
      ```
      typedef struct circleNode {
      int data;
      struct circleNode* next;
      } CircleNode_t;
      ```
2. **Manually Allocate 3 Nodes:** In a clean main() file context, allocate node1, node2, and node3 via individual malloc() calls. Load them with payloads 10, 20, and 30.
3. **Close the Loop Engine:**
   1. Wire node1->next = node2;
   2. Wire node2->next = node3;
   3. The Circular Connection: Wire node3->next = node1; (The loop boundary wrapper).
4. **Print exactly once:** Write a safe do-while loop pattern that checks when current == node1 on its second pass to stop printing before hitting an infinite loop.
5. **Break Circle Before Deallocation:** Set node3->next = NULL; explicitly right before you call your free() functions to protect the stack from trace collapse corruption errors.