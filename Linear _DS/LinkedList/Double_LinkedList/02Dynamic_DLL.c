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
void freeDll(DynaDLL* head);

int main()
{
    printf("===========================================================================\n");
    printf("\tDyanmic Linked List implementation \n");
    printf("===========================================================================\n");

    int option=0;
    int value=0;
    DynaDLL* head = NULL;
    

    while (true)
    {
        printf("\nOptions to select Functionality:\n1)Append the Data\n2)Display Forward List\n3)Display Backward List\n4)Exit\nSelct option: ");
        if(scanf("%d",&option)!=1)
        {   
            fprintf(stderr,"Error:Inavlid User Input\n");
            return EXIT_FAILURE;
        }

        if(option == 1 )
        {
            printf("Enter Value to append: ");
            if(scanf("%d",&value)!=1)
            {
                fprintf(stderr, "Error:Inavlid User Input\n");
                printf("Freeing the memory\n");
                freeDll(head);
                return EXIT_FAILURE;
            }


            if(dll_append(&head,value))
            {
                printf("\n Append Sucessful\n");
            }
            else
                printf("Append Failed..");
        }
        else if(option == 2 )
        {
            display_forward(head);
        }
        else if(option == 3)
        {
            display_backward(head);
        }
        else if(option == 4)
        {
            printf("Exit Sequence initialised..\n");
            freeDll(head);
            printf("Sequence Complete .. Exiting from Program ");
            break;
        }
        else{
            printf("Invalid Input..\n Please try again..\n");
        }
    }

    return EXIT_SUCCESS;
}


bool dll_append(DynaDLL** headref,int val)
{
    DynaDLL* newNode = NULL;

    newNode = (DynaDLL*)malloc(sizeof(DynaDLL));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error: Memory Allocatio Failed..");
        return false;
    }

    newNode->data = val;
    newNode->next = NULL;
    
    DynaDLL* current = *headref;
    if(current == NULL)
    {
        newNode->prev = NULL;
        *headref = newNode;
        return true;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        newNode->prev = current;
        current->next = newNode;
        return true;
    }
}


void display_forward(DynaDLL* head)
{
    if(head == NULL)
    {
        fprintf(stderr,"Error: List is not Initialised..\n please try again by appending at least One Node..\n");
        return;
    }
    printf("===========================================================================\n");
    printf("\tDyanmic Linked List Forward Display Function \n");
    printf("===========================================================================\n");

    DynaDLL* current = head;
    int cnt = 0;

    while(current != NULL)
    {
        printf("Node %d : %d\n",cnt,current->data);
        ++cnt;
        current = current->next;
    }

    printf("===========================================================================\n");
}


void display_backward(DynaDLL* head)
{
    if(head == NULL)
    {
        fprintf(stderr,"Error: List is not Initialised..\n please try again by appending at least One Node..\n");
        return;
    }
    printf("===========================================================================\n");
    printf("\tDyanmic Linked List Backward Display Function \n");
    printf("===========================================================================\n");

    DynaDLL* current = head;
    int cnt = 0;

    while(current->next != NULL)
    {
        current = current->next;
    }

    while(current != NULL)
    {
        printf("Reverse Node %d : %d \n",cnt,current->data);
        ++cnt;
        current = current->prev;
    }

    printf("===========================================================================\n");
}


void freeDll(DynaDLL* head)
{
    DynaDLL* next=NULL;
    DynaDLL* current= head;

    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        printf(".\n");
    }
}
