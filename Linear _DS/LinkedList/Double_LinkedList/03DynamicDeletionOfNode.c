/*
Assignment 12: Dynamic Deletion from a Doubly Linked List.
    Deleting a node from a bi-directional structure requires you to detach both the forward (next) and backward (prev) links of adjacent nodes.

The Structural Strategy
Imagine we want to delete Node B from a chain consisting of A <-> B <-> C:

1.Isolate Head Exception: If deleting position 0, slide head down to Node B, map head->prev = NULL, and free Node A.

2.Target Traversal: Run a loop to find Node B directly.

3.Unlink the Backward Connection: Route Node A forward past Node B to point at Node C:
    B->prev->next = B->next; // A's next pointer now bypasses B and points to C

4.Unlink the Forward Connection: If Node C exists (i.e., Node B is not the tail), route Node C's backward link past Node B to point directly at Node A:
    B->next->prev = B->prev; // C's prev pointer now bypasses B and points to A

5.Reclaim Memory: Safe to execute free(B).
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct doubleNode
{
  struct doubleNode* prev;
  int data;
  struct doubleNode* next;
}node;

bool DLLAppend(node** headref,int val);
bool DLLDelete(node** headref, int pos);
void displayForward(node* head);
void displayBackward(node* head);
void freeList(node* head);

int main()
{
    int option = 0;
    node* head = NULL;
    
}
