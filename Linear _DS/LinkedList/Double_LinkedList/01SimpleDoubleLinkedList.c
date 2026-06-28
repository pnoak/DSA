/*
Manual DLL Assembly
Your Objectives:
Define the Structure: Create the typedef struct Node containing a prev pointer, data integer, and next pointer.

Allocate 3 Nodes: Create three local node pointers in main() (node1, node2, node3) and allocate their memory blocks individually using malloc(). Confirm they aren't NULL.

Initialize the Data: Load your payload values (e.g., 10, 20, 30) into each node's data field.

Wire the Bi-directional Links explicitly:

Wire node1 forward to node2, and make its prev point to NULL.

Wire node2 backward to node1 and forward to node3.

Wire node3 backward to node2 and forward to NULL.

Verify both Directions: * Print forward through the chain starting only from node1 (using node1->next->next->data).

Print backward through the chain starting only from node3 (using node3->prev->prev->data).

Clean Up safely: free() all three nodes and defuse their pointers to NULL.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct doubleNode{
    struct doubleNode* prev;
    int data;
    struct doubleNode* next;
}DLLnode;

int main()
{
    //Make pointers for each node 
    DLLnode* node1 = NULL;
    DLLnode* node2 = NULL;
    DLLnode* node3 = NULL;

    //Allocate Memories to the nodes 
    node1 = (DLLnode*)malloc(sizeof(DLLnode));
    node2 = (DLLnode*)malloc(sizeof(DLLnode));
    node3 = (DLLnode*)malloc(sizeof(DLLnode));

    if((node1 == NULL) || (node2 == NULL) || (node3 == NULL))
    {
        fprintf(stderr,"Error: Memory allocation Failed ..\n");
        return EXIT_FAILURE;
    }
    
    //Add data to nodes 
    // Node 1
    node1->prev = NULL;
    node1->data = 10;
    node1->next = NULL;

    // Node 2
    node2->prev = &node1;
    node2->data = 20;
    node2->next = NULL;
    node1 -> next = &node2;

    // Node 3 
    node3 ->prev = &node2;
    node3->data = 30;
    node3->next = NULL;
    node2->next = &node3;

    DLLnode * fHead = node1;
    DLLnode* rHead = node3;


    // Traversing the List 
    for(int i=0;i<3;++i)
    {
        
    }



    return EXIT_SUCCESS;
}