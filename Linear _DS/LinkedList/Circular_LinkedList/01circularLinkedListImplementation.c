/*
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
4. **Print exactly once:**Write a safe do-while loop pattern that checks when current == node1 on its second pass to stop printing before hitting an infinite loop.
5. **Break Circle Before Deallocation:** Set node3->next = NULL; explicitly right before you call your free() functions to protect the stack from trace collapse corruption errors.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CirNode{
    int data;
    struct CirNode* next;
}node;

//Fucntion Declarations

void displayList(node* head);
void freeList(node* head);

int main()
{
    // Creation of node heads 
    node* node1= NULL;
    node* node2 = NULL;
    node* node3 = NULL;
    node* head = NULL;

    // Make a node 
    node1 = (node*)malloc(sizeof(node));
    node2 = (node*)malloc(sizeof(node));
    node3 = (node*)malloc(sizeof(node));

    // check the allocated memory for initialization status 
    if(node1 == NULL || node2 == NULL || node3 == NULL)
    {
        fprintf(stderr,"Error: Memory Allocation Failed \n");
        free(node1);
        free(node2);
        free(node3);
        return EXIT_FAILURE;
    }

    head = node1;

    // Initialize the node with data 
    node1->data = 100;
    node2->data = 200;
    node3->data = 300;

    // Wire the nodes to form a circular linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    //List Traversal and display of teh List data
    displayList(head);

    // Free-up the whole list and deallocate the heap memory
    
    freeList(head);
    
    node1= NULL;
    node2= NULL;
    node3= NULL;
    head = NULL;

    return EXIT_SUCCESS;
}

void displayList(node* head)
{
    if(head == NULL)
    {
        fprintf(stderr,"Error:List is Empty..\n");
        return;
    }

    node* current = head;
    int cnt=0;
    do
    {
        printf("Node%d: %d \n",cnt,current->data);
        cnt++;
        current = current->next;
    } while (current != head);
    
}

void freeList(node* head)
{
    if(head == NULL)
    {
        printf("There is no element in the list\n");
        return;
    }

    node* current = head;
    node*temp = NULL;
    int cnt=0;
    do
    {
        temp = current->next;
        free(current);
        current = temp;
        printf("Node %d frees..\n",cnt);
        cnt++;
    } while (current != head);

    printf("All nodes freed..\n");
}