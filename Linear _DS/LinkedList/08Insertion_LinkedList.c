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
bool inserAtPosition(Node** headRef, int position, int value);
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
            if(scanf("%d %d",&val,&position)!=1)
            {
                fprintf(stderr,"Error: invalid Input from user.\n");
                free(head);
                return EXIT_FAILURE;
            }

            if(inserAtPosition(&head,position,val))
            {
                printf("Append at specified position Sucessful \n");
            }
            else
            {
                printf("Append Failed..\nPlease try again...\n");
            }

        }
    }

    return EXIT_SUCCESS;
}
