## Assignment 1: The Dynamic Integer Array (Warm-up)Objective:
 Handle basic dynamic allocation, resizing, and memory cleanup.Task: Write a program that prompts the user to enter N integers. Allocate memory dynamically for these N integers.Twist: After reading the initial N integers, ask the user for M additional integers. Resize the allocated memory block to hold N + M elements without losing the original data. Print the entire final array, and then free all allocated memory.


## Assignment 2: The String Concatenation Engine (Intermediate)
Objective: Avoid buffer overflows by calculating memory requirements dynamically at runtime.

Task: Create a function with the signature char* dynamic_concat(const char* str1, const char* str2).

Twist: Inside the function, calculate the exact length of both strings, allocate a precise amount of memory on the heap to store the combined string (plus the null-terminator \0), concatenate them, and return the pointer. In your main function, call this engine, print the result, and ensure no memory leaks occur.


## Assignment 3: Memory Layout Visualizer (Advanced)
Objective: Contrast the lifespans and addresses of static, stack, and heap memory.

→ Task:
*  Write a program that declares:
* A global initialized variable (Static/Data segment).
* A local variable inside main (Stack segment).
* A dynamically allocated variable using malloc() (Heap segment).

→ Twist: Print the hex memory addresses of all three variables. Write a secondary function that attempts to return the pointer of a local variable created inside it back to main, and observe what happens when you try to access it.

## Assignment 4: Building a Fixed-Size Array Container
Instead of moving straight to complex structures, let's write a clean, modular program that mimics how high-level languages handle arrays safely.

Your Task:
Write a C program that manages a fixed-size integer array using a structured approach. Do not use global variables.

Define a Structure: Create a struct SafeArray that holds:

A fixed integer array (e.g., size 5).

An integer tracking the current_size (how many elements are actually filled).

Implement an Append Function: Write a function int append(struct SafeArray *array, int value) that adds an element to the next available slot. If the array is full, it should reject the input and return an error code.

Implement a Safe Display Function: Write a function to print the elements cleanly.

5) Assignment 5: Building a Dynamic Vector Container
Your Task:
Write a modular C program that implements a custom integer Vector. 

Requirements:
Define the Structure: Create a struct MyVector holding int *data, int size, and int capacity.

Implement Initialization: Write a function void vector_init(struct MyVector *v, int initial_capacity) that allocates the initial heap memory using malloc.

Implement Append: Write int vector_append(struct MyVector *v, int value) that adds elements and automatically doubles the capacity using realloc if the vector fills up.

Implement Display: Write a function to print the current size, capacity, and active elements cleanly.

Implement Cleanup: Write a function to free the heap memory when done to prevent leaks

6)Assignment 6: Manual Node Assembly (The "Hard" Way)
Before we write loops or automated insertion functions, your task is to manually create three individual nodes on the heap, link them together by explicitly assigning their next pointers, and print their values.

This will force you to see exactly how pointers "chain" from one memory chunk to another.

Your Objectives:
Define the Structure: Declare the struct Node as shown above.

Allocate Nodes: Inside main(), create three distinct pointers: struct Node* first, struct Node* second, and struct Node* third. Allocate memory for each one individually using malloc().

Assign Data: Give each node a unique number (e.g., first->data = 10;, etc.).

Wire Them Together (The Core Step): * Make first->next point to the address of second.

Make second->next point to the address of third.

Make third->next point to NULL (marking the end of the line).

Print via the Chain: Print the values of all three nodes, but here is the twist: you are only allowed to use the variable first inside your print statements.

Hint: To print the second node's data using only first, you will look at first->next->data.

Clean Up: Manually free() all three nodes before exiting.

7) Assignment 7: Building a Dynamic Single Linked List Module
Following your rules, write this program out. When you upload it, I will first provide a complete
        microscopic list of all minute bugs, and then present the industry-standard improvements.

Your Objectives:
Define the Node Structure: Use the standard struct node pattern.

Implement an Append Function: Write void append(struct node head_ref, int value).

Hint: We pass a pointer-to-a-pointer (struct node) because if the list is empty, the function 
        needs to directly modify the head pointer inside main().

Implement a Traversal Display Function: Write void display(struct node* head) that uses a while (current != NULL) 
                                        loop to slide forward and print every active node's data field sequentially.

Implement a Master Cleanup Function: Write void free_list(struct node* head) that loops through the 
                            entire list and frees every node individually so you leave zero active blocks on the heap.

8) Assignment 8: The Arbitrary Insertion Challenge
Your Task:
Modify your existing Singly Linked List codebase by adding a highly robust insertion function.

Requirements:
Implement the Insert Function: Write bool insertAtPosition(Node headRef, int position, int value);.

Interactive Menu: Add a new option to your main() loop: 4) Insert at Position.

Scan with Validation: Prompt the user for both the target position (index) and the integer value. Validate both inputs using scanf safety patterns.
