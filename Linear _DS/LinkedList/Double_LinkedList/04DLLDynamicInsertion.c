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
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct doublenode
{
    struct doublenode* prev;
    int data;
    struct doublenode* next;
}node;

bool dllAppend(node** headref, int val);
bool dllInsert(node** headref, int pos, int val);
void displayForward( node* head);
void displayBackward(node* head);
bool deleteDLL(node** headref, int pos);
void freeList(node* head);

int main()
{
    node* head = NULL;
    int option =0;

    printf("\n===========================================================\n");
    printf("\tDynamic Insertion of Double LinkedList\n");
    printf("===========================================================\n\n");

    while(true)
    {
        printf("options to select funcationality:\n");
        printf("\n1) Append the data in the list\n2) Insert Node at specified position\n3) Display List from Front\n4) Display List from Back\n5) Delete Node From Specified position\n6) Exit\n");
        printf("\n-------------------------------\n");
        printf("Enter Option: ");
        if(scanf("%d",&option)!=1)
        {
            fprintf(stderr,"Error: Invalid input\n");
            return EXIT_FAILURE;
        }

        // Option 1: Append the data in the list
        if(option == 1)
        {
            int val=0;
            printf("Append Functionality Selected.\nEnter Value to append: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user\n");
                return EXIT_FAILURE;
            }
            if(dllAppend(&head, val))
            {
                printf("Append Sucessful..\n");
                printf("--------------------------------\n");
            }
            else
            {
                printf("Append Failed..\n");
                printf("--------------------------------\n");
            }
        }

        //option 2: Insert Node at specified position
        else if(option == 2)
        {
           printf("Insert Node at specified position Functionality Selected.\n");

           int val=0,pos=0;
           printf("Enter the value to insert: ");
           if(scanf("%d",&val)!=1)
           {
                fprintf(stderr,"Error: Invalid Input..\n");
                return EXIT_FAILURE;
           }
           printf("Enter Position to insert a node: ");
           if(scanf("%d",&pos)!= 1)
           {
                fprintf(stderr,"Error: Invalid Input..\n");
                return EXIT_FAILURE;
           }

           //insertion Function call
           if(dllInsert(&head, pos,val))
           {
            printf("Insertion Procedure Complete..\n");
            printf("\n-------------------------------\n");
           }
           else
           {
            printf("Insertion Procedure Failed..\n");
            printf("\n-------------------------------\n");
           }
        }

        // Option 3: Display List from Front
        else if(option == 3)
        {
            displayForward(head);
        }

        //option 4: Display List from Back
        else if(option == 4)
        {
            displayBackward(head);
        }

        // Option 5: Delete Node From Specified position
        else if(option == 5)
        {
            int position = 0;
            printf("Node Deletion Procedure:\nEnter Position to delete node: ");
            if(scanf("%d",&position)!=1)
            {
                fprintf(stderr,"Error: Invalid input..\n");
                freeList(head);
                return EXIT_FAILURE;
            }

            if(deleteDLL(&head,position))
            {
                printf("Node Deletion Procedure Complete..\n");
                printf("-------------------------------\n"); 
            }
            else
            {
                printf("Procedure failed to delete node\n");
                printf("-------------------------------\n");
            }
        }

        //option 6: Exit
        else if(option == 6)
        {
            printf("\n-------------------------------\n"); 
            printf("\nExit Procedure Started..\n");
            freeList(head);
            printf("Exit Procedure Complete..\n");
            printf("\n===============================\n"); 
            break;
        }

        //invalid input Handling
        else
        {
            printf("Invalid Option Selected. Please select a valid option from the list\n");
            while(getchar() != '\n');
        }
    }
}

bool dllAppend(node** headref, int val)
{   
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr,"Error: memory allocation failed\n");
        return false;
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*headref == NULL)
    {
        *headref = newNode;
        return true ;
    }
    else
    {
        node* current = *headref;
        while(current->next != NULL)
        {
            current = current -> next;
        }
        current->next = newNode;
        newNode->prev = current;
        return true;
    }
}

bool dllInsert(node** headref, int pos, int val)
{
    int cnt=0;
    node* current = *headref;
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error: Memory allocation failed..\n");
        freeList(*headref);
        return false;
    }

    newNode->data = val;

    if(pos<0)
    {
        fprintf(stderr,"Error: Invalid position..\n");
        free(newNode);
        return false;    
    }
    else if(pos==0)
    {
        newNode->prev = NULL;
        newNode->next = current;
        current->prev = newNode;
        *headref = newNode;
        return true;
    }
    else if(pos>0)
    {
        while ((cnt < pos) && (current != NULL))
        {
            current = current->next;
            ++cnt;
        }

        // position out of bounds
        if(current == NULL)
        {
            printf("Position %d does not exist in the list.. please try again with a valid position..\n", pos);
            printf("\n-------------------------------\n"); 
            free(newNode);
            return false;
        }
        
        // tail insertion
        else if((current != NULL) && (current->next == NULL) && (cnt == pos))
        {
            current ->next = newNode;
            newNode->prev = current;
            newNode->next = NULL;
            return true;
        }

        // middle insertion 
        else if((current != NULL) && (cnt < pos))
        {
            node* temp = current->prev;
            newNode->next = current;
            newNode->prev = current->prev;
            temp->next= newNode;
            current->prev = newNode;
            return true;
        }
    }
}

void displayForward(node* head)
{
    printf("-------------------------------\n");
    printf("Displaying list form Front..\n");
    printf("-------------------------------\n");

    node* current = head;
    int cnt=0;
    while(current != NULL)
    {
        printf("Node %d: %d\n",cnt,current->data);
        current = current ->next;
        ++cnt;
    }
    printf("-------------------------------\n");
}

void displayBackward(node* head)
{
    printf("-------------------------------\n");
    printf("Displaying list form Back..\n");
    printf("-------------------------------\n");

    node* current = head;
    int cnt=0;
    
    while(current->next != NULL)
    {
        current = current->next;
    }

    while(current != NULL)
    {
        printf("Node %d: %d\n",cnt,current->data);
        current = current->prev;
        ++cnt;
    }
    printf("-------------------------------\n");
}

bool deleteDLL(node** headref, int pos)
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

void freeList(node* head)
{
    printf("-------------------------------\n");
    printf("Freeing all nodes in the list..\n");
    printf("-------------------------------\n");
    node* current = head;
    node* next = NULL;
    int cnt=0;
    while(current != NULL)
    {
        next = current ->next;
        free(current);
        current = next;
        printf("Node %d Freed..\n",cnt);
        ++cnt;
    }
    printf("-------------------------------\n");
    printf("All nodes freed.\n");
    printf("-------------------------------\n");
}