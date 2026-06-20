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
bool insertAtPosition(Node** headRef, int position, int value);
bool append(Node** headRef, int value);
void display(Node* head);
void freeList(Node* head);

int main()
{
    Node* head = NULL;
    int option  = 0;

    printf("--------------- Dynamic Single LinkedList Implementation ----------------------\n");
    
    while(true)
    {
        printf("\nOptions to choose: \n1)Append in LinkedList\n2)Append the node at perticular location\n3)Display List\n4)Exit from Program\n\n Select option: ");
        if(scanf("%d",&option) !=1 )
        {
            fprintf(stderr,"Error: Invalid Input, Please select correct option..\n");
            freeList(head);
            return EXIT_FAILURE;
        }        

        //case Append in LinkedList
        if(option ==1)
        {
            int val=0;
            printf("Enter Value to Append: ");
            if(scanf("%d",&val)!=1)
            {
                fprintf(stderr,"Error: invalid Input from user.\n");
                free(head);
                return EXIT_FAILURE;
            }
            if(append(&head,val))
            {
                printf("Append Sucess..");
            }
            else
                printf("Append Failed.. \nPlease Try again ..\n");

        }

        else if(option==2)
        {
            int val=0;
            int position =0;
            printf("Enter Value followed by Position(Index) to Append: ");
            if(scanf("%d %d",&val,&position)!=2)
            {
                fprintf(stderr,"Error: invalid Input from user.\n");
                free(head);
                return EXIT_FAILURE;
            }

            if(insertAtPosition(&head,position,val))
            {
                printf("Append at specified position Sucessful \n");
            }
            else
            {
                printf("Append Failed..\nPlease try again...\n");
            }

        }
        else if(option==3)
        {
            display(head);
        }
        else if(option==4)
        {
            printf("Entering the exit Sequence..\n");
            freeList(head);
            printf("Done..\n");
            return EXIT_SUCCESS;
        }
    }

    return EXIT_SUCCESS;
}


bool insertAtPosition(Node** headRef, int position, int value)
{
    //verify the position is positive
    if(position < 0)
    {
        return false;
    }
    //Make a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        fprintf(stderr,"Error:Memory allocation failed..\nExiting from program safely..\n");
        return false;
    }

    // add the data to the newNode->data
    newNode->data = value;
    newNode->next = NULL;

    //scenario1: if there is empty List then make a new node as First 
    if(*headRef == NULL)
    {
        *headRef = newNode;
        return true;
    }
    //scenario 2: if list is not empty
    else if(position == 0)
    {
        newNode->next = *headRef;
        *headRef = newNode;
        return true;
    }
    //scenario 3: at middle or at End/tail
    Node* current = *headRef;
    //traverse list till position 
    for(int i=0;i<(position-1); ++i)
    {
        current = current->next;
    }
    //check for invalid Position 
    if(current == NULL)
    {
        printf("Error: Position out of bound\n");
        free(newNode);
        return false;
    }
    newNode->next = current->next;
    current->next = newNode;

    return true;

}


bool append(Node** headRef, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error: Memory allocation failed\n");
        return false;
    }
    
    newNode ->data = value;
    newNode->next = NULL;

    if(*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        Node* current = *headRef;
        while(current->next != NULL)
        {
            current = current->next;
        }

        current ->next = newNode;
    }
    return true;

}


void display(Node* head)
{
    if(head == NULL)
    {
        printf("No elements in the list");
        return;
    }
    Node* nodePtr = head;
    int cnt=0;
    printf("------------ List Status --------------\n");
    while(nodePtr != NULL)
    {
        printf("Node %d: %d\n",cnt,nodePtr->data);
        nodePtr = nodePtr->next;
        ++cnt;
    }
    printf("---------------------------------------\n");
}

void freeList(Node* head)
{
    Node* current = head;
    Node* next = NULL;
    printf("\nClearing the heap memory..\n");

    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    printf("Done..\n");
}

void ref()
{
    return;
}