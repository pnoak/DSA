/*
Assignment 6: Manual Node Assembly (The "Hard" Way)
Before we write loops or automated insertion functions, your task is to manually create three individual nodes on the heap, link them together by explicitly assigning their next pointers, and print their values.

This will force you to see exactly how pointers "chain" from one memory chunk to another.

Your Objectives:
Define the Structure: Declare the struct Node as shown above.

Allocate Nodes: Inside main(), create three distinct pointers: struct Node* first, struct Node* second, and struct Node* third. Allocate memory for each one 
                    individually using malloc().

Assign Data: Give each node a unique number (e.g., first->data = 10;, etc.).

Wire Them Together (The Core Step): * Make first->next point to the address of second.

Make second->next point to the address of third.

Make third->next point to NULL (marking the end of the line).

Print via the Chain: Print the values of all three nodes, but here is the twist: you are only allowed to use the variable first inside your print statements.

Hint: To print the second node's data using only first, you will look at first->next->data.

Clean Up: Manually free() all three nodes before exiting.

*/

#include <stdio.h>
#include <stdlib.h>

//Use explicit typedef definitions for clean signatures
typedef struct Node {
    int data;
    struct Node *next;
} Node_t;

//Isolated helper routine to implement clean node production logic
Node_t* create_node(int value);

int main(void)
{
    // 1. Initialize structural tracking nodes cleanly
    Node_t *node1 = create_node(10);
    if (node1 == NULL){
        return EXIT_FAILURE;
    }

    Node_t *node2 = create_node(20);
    if (node2 == NULL) {
        free(node1); 
        return EXIT_FAILURE;
    }

    Node_t *node3 = create_node(30);
    if (node3 == NULL) {
        free(node2); 
        free(node1);
        return EXIT_FAILURE;
    }

    // 2. Wiring up node linkages cleanly
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL; // Explicit termination boundary setting

    // 3. Verification through single-pointer referencing chain
    printf("--- Manual Pointer Chasing Verification ---\n");
    printf("Node 1 Value: %d\n", node1->data);
    printf("Node 2 Value: %d\n", node1->next->data);
    printf("Node 3 Value: %d\n", node1->next->next->data);
    printf("-------------------------------------------\n");

    // 4. Structured Memory Cleanup
    free(node1);
    free(node2);
    free(node3);

    // Defuse local variable tracking pointers
    node1 = NULL;
    node2 = NULL;
    node3 = NULL;

    return EXIT_SUCCESS;
}


Node_t* create_node(int value) {
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    if (new_node == NULL) {
        fprintf(stderr, "[Error]: Dynamic structural node allocation failed.\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL; // Set default termination state defensively
    return new_node;
}