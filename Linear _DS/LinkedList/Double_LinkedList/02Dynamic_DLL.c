/*
Assignment 11: The Dynamic DLL Container Module
Your Task: Write a modular, interactive menu program that implements a custom dynamic integer Doubly Linked List.

Requirements:
Define the Node Layout: Use your established typedef struct doubleNode pattern.

Implement Append: Write bool dll_append(DLLNode headRef, int value);.

Implement Dual Traversals:

void display_forward(DLLNode* head); -> Loops forward from head to tail using next.

void display_reverse(DLLNode* head); -> Loops forward to find the tail first, then loops completely backward to the head using the prev pointers to print values.

Implement Clean Freeing: Write void free_dll(DLLNode headRef); that wipes all nodes safely and nullifies the main reference.

Interactive Controller: Build a while(true) terminal loop tracking options: 1) Append, 2) Display Forward, 3) Display Reverse, and 4) Exit. Validate user entry with scanf.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct doublenode
{
    struct doublenode* prev;
    int data;
    struct doublenode* next;
}DynaDLL;

bool dll_append(DynaDLL** headref,int val);
void display_forward(DynaDLL* head);
void display_backward(DynaDLL* head);
bool freeDll(DynaDLL* head);

int main()
{
    printf("===========================================================================\n");
    printf("\tDyanmic Linked List implementation \n");
    printf("===========================================================================\n");

    int option=0;
    int value=0;
    DynaDLL* head=NULL;

    while (true)
    {
        printf("Options to select Functionality:\n1)Append the Data\n2)Display Forward List\n3)Display Backward List\n4)Exit\nSelct option: ");
        scanf("%d",&option);

        if(option == 1 )
        {
            printf("Enter Value to append: ");
            scanf("%d",&value);

            if(append(&head,value))
            {
                printf("\n Append Sucessful\n");
            }
            else
                printf("Append Failed..");
        }
        else if(option = 2 )
        {
            display_forward(head);
        }
        else if(option == 3)
        {
            display_backward(head);
        }
        else if(option == 4)
        {
            printf("");
        }
    }

    return EXIT_SUCCESS;
}