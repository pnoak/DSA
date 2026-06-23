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
bool append(node* head,int val);
bool insertAtPosition(node** headRef,int val, int position);
bool deleteAtPosition(node ** headRef,int position);
void freeList(node* head);

int main()
{
    int position= 0;
    int value = 0;
    int option = 0;
    
    printf("\n\n-------------- Node deletion imlementation -------------------\n");

    node * head = NULL;
    
    while(true)
    {
        printf("\n\nOptions to select Functionality:\n1) Append the Node\n2) Append Node at perticular position\n3) Delete Node From perticular position\n4) Display List\n5) Exit\nSelect Option:  ");
        if(scanf("%d",&option)!=1)
        {
            fprintf(stderr,"Error: Invalid Input from User.\n\n ");
            return EXIT_FAILURE;
        }

        if(option == 1)
        {
            node * newNode = (node* )malloc(sizeof(node));
            if(newNode == NULL)
            {
                fprintf(stderr,"Error: Memory allocation Failed..\nPlease Try again..\n\n");
                return EXIT_FAILURE;
            }

            printf("Enter Value: ");
            if(scanf("%d",&value)!= 1)
            {
                fprintf(stderr,"Error: Invalid Input from User.\n\n ");
                return EXIT_FAILURE;
            }

        }
    }
}

void displayList(node* head);
bool append(node* head,int val);
bool insertAtPosition(node** headRef,int val, int position);
bool deleteAtPosition(node ** headRef,int position);
void freeList(node* head);