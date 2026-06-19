/*
## Assignment 8: The Arbitrary Insertion Challenge
**Your Task:**  
Modify your existing Singly Linked List codebase by adding a highly robust insertion function.

**Requirements:**
1. **Implement the Insert Function:** Write bool insertAtPosition(Node headRef, int position, int value);.

2. **Interactive Menu:** Add a new option to your main() loop: 4) Insert at Position.

3. **Scan with Validation:** Prompt the user for both the target position (index) and the integer value. Validate both inputs using scanf safety patterns.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

// Function Declarations 
bool inserAtPosition(Node** headRef, int position, int value);
void display(Node* head);
void freeList(Node* head);

int main()
{

    return EXIT_SUCCESS;
}
