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

//Function Declaration 
bool DLLAppend(node** headref,int val);
bool DLLDelete(node** headref, int pos);
void displayForward(node* head);
void displayBackward(node* head);
void freeList(node* head);

int main()
{
    int option = 0;
    node* head = NULL;

    printf("\n===========================================================\n");
    printf("\tDynamic Deletation of Double LinkedList\n");
    printf("===========================================================\n");
    
    while(true)
    {
        printf("Please Select the Functionality from Following Options:\n");
        printf("1)Append the data in the list\n2)Display List from Front\n3)Display List from Back\n4)Delete Node From Specified position\n5)Exit\n");
        printf("\n-------------------------------\n");
        printf("Enter Option: ");
        if(scanf("%d",&option)!=1)
        {
            fprintf(stderr,"Error: Invalid input\n");
            return EXIT_FAILURE;
        }
        printf("\n-------------------------------\n");
        if(option == 1)
        {
            int val=0;

            printf("Append Functionality Selected.\nEnter Value to append: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user\n");
                return EXIT_FAILURE;
            }

            if(DLLAppend(&head,val))
            {
                printf("\nAppend Sucessful..\n");
            }
            else
            {
                printf("\n Append Failed..\n");
            }
        }

        else if(option == 2)
        {
            displayForward(head);
        }

        else if(option == 3)
        {
            displayBackward(head);
        }

        else if(option == 4)
        {
            int position = 0;
            printf("Node Deletion Procedure:\nEnter Position to delete node: ");
            if(scanf("%d",&position)!=1)
            {
                fprintf(stderr,"Error: Invalid input..\n");
                freeList(head);
                return EXIT_FAILURE;
            }

            if(DLLDelete(&head,position))
            {
                printf("Node Deletion Procedure Complete..\n");
                printf("\n-------------------------------\n"); 
            }
            else
            {
                printf("Procedure failed to delete node");
                printf("\n-------------------------------\n");
            }
        }

        else if(option == 5)
        {
            printf("\n-------------------------------\n"); 
            printf("\nExit Procedure Started..\n");
            freeList(head);
            printf("Exit Procedure Complete..\n");
            printf("\n===============================\n"); 
            break;
        }
        else
        {
            printf("Invalid Option Selected. Please select a valid option from the list\n");
            while(getchar() != '\n');
        }
    }
    return EXIT_SUCCESS;
}

bool DLLAppend(node** headref,int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error: Memory Allocation Failed..\n");
        return false;
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(*headref == NULL)
    {
        *headref = newNode;
        return true;
    }
    else
    {
        node*current = *headref;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        return true;
    }
}

bool DLLDelete(node** headref, int pos)
{
    node* current = *headref;
    if(current == NULL)
    {
        printf("\n-------------------------------\n");  
        printf("List is Empty.. please append some data first and try again..\n");
        printf("\n-------------------------------\n"); 
        return false;
    }
    else if(pos < 0)
    {
        printf("\n-------------------------------\n");
        printf("Negative position not allowed.. please try again with a valid position..\n");
        printf("\n-------------------------------\n"); 
        return false;
    }
    else if(pos == 0)
    {
        *headref = current->next;
        current->next->prev = NULL;
        free(current);
        printf("\n-------------------------------\n"); 
        return true;
    }
    else if( pos>0)
    {
        int cnt = 0;
        while(current != NULL && cnt < pos)
        {
            current = current->next;
            ++cnt;
        }

        if ((current != NULL) && (current ->prev != NULL) && (current->next != NULL))
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            printf("\n-------------------------------\n"); 
            return true;
        }
        else if((current != NULL) && (current->prev != NULL) && (current->next == NULL))
        {
            current->prev->next = NULL;
            free(current);
            printf("\n-------------------------------\n"); 
            return true;
        }
        else if(current == NULL)
        {
            printf("Position %d does not exist in the list.. please try again with a valid position..\n", pos);
            printf("\n-------------------------------\n"); 
            return false;
        }
    }
    else
    {
        printf("Position %d does not exist in the list.. please try again with a valid position..\n", pos);
        printf("\n-------------------------------\n"); 
        return false;
    }
}

void displayForward(node* head)
{
    printf("\n============================================================\n");
    printf("\tDisplay List from Front\n");
    printf("============================================================\n");

    node* current = head;
    if(current == NULL)
    {
        printf("List is Empty.. please append some data first and try again..\n");
        return ;
    }

    int cnt=0;
    while(current != NULL)
    {
        printf("Node %d: %d\n",cnt,current->data);
        ++cnt;
        current = current ->next;
    }
    printf("\n============================================================\n");
    printf("Total nodes: %d\n",cnt);
    printf("============================================================\n");
}

void displayBackward(node* head)
{
    printf("\n============================================================\n");
    printf("\tDisplay List from Back\n");
    printf("============================================================\n");

    node* current= head;
    if(current == NULL)
    {
        printf("List is Empty.. please append some data first and try again..\n");
        return ;
    }

    // Go to the end of the List and travers back to the head 
    while(current->next != NULL)
    {
        current = current->next;
    }
    // traversing back to the head
    int cnt=0;
    while(current != NULL)
    {
        printf("Node %d: %d\n",cnt,current->data);
        ++cnt;
        current = current->prev;
    }
    printf("\n============================================================\n");
    printf("Total nodes: %d\n",cnt);
    printf("============================================================\n");

}
void freeList(node* head)
{
    node* current = head;
    node* next = NULL;
    int cnt=0;
    printf("\n-------------------------------\n");
    while(current != NULL)
    {
        next = current->next;
        free(current);
        ++cnt;
        current = next;
        printf("Node %d freed.\n", cnt);
    }
    printf("-------------------------------\n");
    printf("All nodes freed.\n");
    printf("-------------------------------\n");
    return;
}

