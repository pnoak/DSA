/*
Assignment 9: The Node Deletion Challenge
Incorporate a robust node deletion function into your current working Singly Linked List codebase.

Requirements:
Implement the Delete Function: Write bool deleteAtPosition(Node headRef, int position);. It should return 
true on successful deletion and false if the position is out of bounds or the list is completely empty.

Interactive Menu Expansion: Add a new option to your main() loop: 
    4) Delete at Position (and shift your exit option to 5).

Scan Validation: Prompt the user for the target index to delete and protect
     the entry using your standard scanf verification logic.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

void displayList(node* head);
bool append(node** headRef,int val);
bool insertAtPosition(node** headRef,int val, int position);
bool deleteAtPosition(node ** headRef,int position);
void freeList(node* head);

int main()
{
    int option = 0;
    node* head = NULL;

    printf("\n\n-------------- Node deletion imlementation -------------------\n");

    
    
    while(true)
    {
        printf("\n\nOptions to select Functionality:\n1) Append the Node\n2) Append Node at perticular position\n3) Delete Node From perticular position\n4) Display List\n5) Exit\nSelect Option:  ");
        if(scanf("%d",&option)!=1)
        {
            fprintf(stderr,"Error: Invalid Input from User.\n\n ");
            return EXIT_FAILURE;
        }

        //Check to append the node
        if(option == 1)
        {
            int value=0;
            
            printf("Enter Value: ");
            if(scanf("%d",&value)!= 1)
            {
                fprintf(stderr,"Error: Invalid Input from User.\n\n ");
                return EXIT_FAILURE;
            }

            if(append(&head,value))
            {
                printf("\n Append Sucess..\n");
            }
            else
                printf("\nAppend Fialed..\n please try again..\n\n");
        }

        // Check for insertion of node at a perticular position 
        else if(option == 2)
        {
            int val=0,position=0;
            printf("\nEnter the position: ");
            if(scanf("%d",&position)!=1)
            {
                fprintf(stderr,"Error: Invalid Input from User.\n\n ");
                return EXIT_FAILURE;
            }
            printf("\nEnter the Value: ");
            if(scanf("%d",&val)!=1)
            {
                fprintf(stderr,"Error: Invalid Input from User.\n\n ");
                return EXIT_FAILURE;
            }

            if(insertAtPosition(&head,val,position))
            {
                printf("\nNode added sucess..\n");
            }
            else{
                printf("\nNode allocation failed..\n");
            }
        }

        // Check for node deletion option 
        else if(option == 3)
        {
            int pos=0;
            
            printf("\nEnter the position: ");
            if(scanf("%d",&pos)!=1)
            {
                fprintf(stderr,"Error: Invalid Input from User.\n\n ");
                return EXIT_FAILURE;
            }

            if(deleteAtPosition(&head,pos))
            {
                printf("\nDeletion sucessful\n");
            }
            else{
                printf("\nDeetion of Ndoe Failed..\n\n");            }
        }

        //Check for Display functionality selection
        else if(option == 4)
        {
            displayList(head);
        }

        // Check for exit functio selection
        else if( option == 5)
        {
            printf("\n\nExit Procedure started..\n De-allocating the memory of LinkedList..\n ");

            freeList(head);
            printf("\nProcedure Completed.. \t Exiting from Program Safely ...\n\n");
        }

        else
            printf("Error: Invalid Input..\n Please try again..\n");
    }

    return EXIT_SUCCESS;
}

void displayList(node* head)
{
    node* newNode = head;
    int cnt=0;
    printf("\n---------------- Linked List Display Function -----------------\n");
    while(newNode!= NULL)
    {
        printf("Node%d: %d\n",cnt,newNode->data);
        newNode = newNode->next;
        ++cnt;
    }
    printf("--------------------------------------------------------------\n");
}


bool append(node** headRef,int val)
{

}


bool insertAtPosition(node** headRef,int val, int position)
{

}


bool deleteAtPosition(node ** headRef,int position)
{

}


void freeList(node* head)
{

}