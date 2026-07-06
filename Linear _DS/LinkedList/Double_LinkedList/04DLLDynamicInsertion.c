/*
Assignment 13: The Complete DLL Insertion Module
Your Task: Incorporate a robust arbitrary positioning function into your Doubly Linked List code base.

Requirements:
Implement the Function: Write bool DLLInsert(node headref, int val, int pos);. It should return true on success 
                        and false if the position is out of bounds or negative.

Interactive Menu Expansion: Add a new option to your main console loop: 2) Insert Node at specified position. 
                            (Shift your subsequent display, delete, and exit menu option numbers downward accordingly).

Input Validation: Prompt the user for both the integer value and target position, protecting inputs with your 
                    standard scanf error traps
*/

// Header File Inclusion 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/// @brief Structure Definition for a Node in a Doubly Linked List

typedef struct doubleNode{
    struct doubleNode * prev;
    int data;
    struct doubleNode* next;
}node;

/// @brief Function to select functionality of the program  
bool appendDLL(node ** headref, int val);
bool insertAtPosition(node ** headref, int val, int pos);
void  displayForwardDLL(node* head);
void  displayBackwardDLL(node* head);
bool deleteNodeDLL(node ** headref, int pos);
void freeListDLL(node * head);


/// @brief Main Function to drive the program
int main()
{
    node *head = NULL;
    int opt;
    printf("\n=================================================================================================================\n");
    printf("\tDoubly Linked List full Implementation");
    printf("\n=================================================================================================================\n");
    while (true)
    {
        printf("Select an option from the menu below to use functionality:\n");
        printf("1) Append Node at the end\n");
        printf("2) Insert Node at specified position\n");
        printf("3) Display List Forward\n");
        printf("4) Display List Backward\n");
        printf("5) Delete Node at specified position\n");
        printf("6) Free Entire List\n");
        printf("7) Exit\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &opt) != 1)
        {
            fprintf(stderr, "Error:Invalid Input from user\nplease try again..\n");
            while (getchar() != '\n')
                ; // Flust the Bad Input
            printf("------------------------------------------------------------------------------------\n");
            continue;
        }

        // Append Functionality 
        if(opt == 1)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Append Node at the end' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int val;
            node * newNode = (node*)malloc(sizeof(node));
            if(newNode == NULL)
            {
                fprintf(stderr,"Error:Memory allocation failed..\n");
                if(head != NULL)
                {
                    freeListDLL(head);
                }
                else
                    return EXIT_FAILURE;
            }
            printf("Enter the value: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }
            else{
                if(appendDLL(&head,val))
                {
                    printf("\nAppend Sucess..!!\n");
                }
                else   
                    printf("\nAppend Failed..!!\n");
            }
            printf("------------------------------------------------------------------------------------\n");      
        }

        // Insert at specific position functionality 
        else if(opt == 2)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Insert Node at specified position' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int val,pos;
            printf("Enter the position to inser data: ");
            if(scanf("%d",&pos)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }
            printf("\nEnter val to insert: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }

            if (insertAtPosition(&head, val, pos))
            {
                printf("\nAppend Sucess..!!\n");
            }
            else
                printf("\nAppend Failed..!!\n");
            
            printf("------------------------------------------------------------------------------------\n");
        }

        // LinkedList Traversal from Forward to Dispplay the List 
        else if(opt == 3)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Display List Forward' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");


            displayForwardDLL(head);
            printf("------------------------------------------------------------------------------------\n");
        }

        // LinkedList Traversal from Backward to Dispplay the List 
        else if(opt == 4)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Display List Backward' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            displayBackwardDLL(head);
            printf("------------------------------------------------------------------------------------\n");

        }

        // deletion functionality to delete specific node or data
        else if(opt == 5)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Delete Node at specified position' Functionality Selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int pos=0;

            printf("Enter Position to Delete Node: ");
            if(scanf("%d",&pos)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
            }
            else{
                if(deleteNodeDLL(&head,pos))
                {
                    printf("\nNode Deletion Sucess..!!\n");
                }
                else   
                    printf("\nNode Deletion Failed..!!\n");
            }

            printf("------------------------------------------------------------------------------------\n");

        }

        // Exit functionality 
        if(opt == 6)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Free Entire List' Functionality Selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            freeListDLL(head);
            printf("------------------------------------------------------------------------------------\n");
        }

        else{
            fprintf(stderr,"Error: Wrong Input.. Please try again ...\n");
            while(getchar()!='\n');
            continue;
        }
    }
}