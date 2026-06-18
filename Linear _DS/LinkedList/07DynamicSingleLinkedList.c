/*
Assignment 7: Building a Dynamic Single Linked List Module
Following your rules, write this program out. When you upload it, I will first provide a complete
        microscopic list of all minute bugs, and then present the industry-standard improvements.

Your Objectives:
Define the Node Structure: Use the standard struct node pattern.

Implement an Append Function: Write void append(struct node head_ref, int value).

Hint: We pass a pointer-to-a-pointer (struct node) because if the list is empty, the function 
        needs to directly modify the head pointer inside main().

Implement a Traversal Display Function: Write void display(struct node* head) that uses a while (current != NULL) 
                                        loop to slide forward and print every active node's data field sequentially.

Implement a Master Cleanup Function: Write void free_list(struct node* head) that loops through the 
                            entire list and frees every node individually so you leave zero active blocks on the heap.
                            
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
        int data;
        struct node* next;
}Node;

//Funtion Prototypes
bool append(Node** headRef, int value);
void display(Node* head);
void freeList(Node* head);

//Entry function 
int main()
{
        Node* head = NULL;
        int option =0;

        printf("--------------- Dynamic Single LinkedList Implementation ----------------------\n");
        while(true)
        {
                printf("\nOptions to choose: 1)Append the node\n2)Display List\n3)Exit from Program\n\n Select option: ");
                if(scanf("%d",&option)!=1)
                {
                        fprintf(stderr, "Error: Invalid input ...\n");
                        freeList(head);
                        return EXIT_FAILURE;
                }

                if(option == 1)
                {
                        int val=0;
                        printf("Enter value to append: ");
                        if(scanf("%d",&val)!=1)
                        {
                                fprintf(stderr,"Error: invalid Input from user..\n");
                                freeList(head);
                                return EXIT_FAILURE;
                        }
                        if(append(&head,val))
                        {
                                printf("Append Sucess..\n");
                        }
                        else{
                                printf("Append Failed.");
                        }
                }
                else if(option == 2)
                {
                        display(head);
                }
                else if(option == 3)
                {
                        display(head);
                        freeList(head);
                        printf("Exiting From Program ........\n");
                        break;
                }
                else
                {
                        printf("Invalid option selected.... Please try again\n");
                        while(getchar() != '\n');
                }
        }
        printf("\n---------------------------------------------------------------------------------\n");
        return EXIT_SUCCESS;
}


//Function Definations 

bool append(Node** headRef, int value)
{
        // Allocating Heap memory for new node 
        Node*  newNode = (Node *) malloc( sizeof(Node));
        if(newNode == NULL)
        {
                fprintf(stderr,"Error: Memory allocation Failed\n");
                return false;
        }

        newNode->data = value;
        newNode->next = NULL;

        // SCENARIO A: *headRef is pointing to NULL
        if(*headRef == NULL)
        {
                *headRef = newNode;
        }
        else{
                Node * current = *headRef; // make a pointer which will start searching for null to teh end of list 
                
                while(current->next != NULL)
                {
                        current = current->next;
                }
                
                // connect new node to last node 
                current->next = newNode;
        }
        return true;
}

void display(Node* head)
{
        printf("\n------------ Current List Status ------------\n");
        if(head == NULL){
                printf("No element in the list");
                return;
        }
        else{
                Node * current = head;
                int count =0;

                while(current != NULL)
                {
                        printf("Node %d:\nAddr of node: %p\tData = %d\tNext node addr: %p\n\n",count,(void*)current,current->data,(void*)current->next);
                        current = current->next;
                        ++count;
                }
        }
        printf("\n----------------------------------------------\n");
}


void freeList(Node* head)
{
        printf("\nClearing the heap memory ........\n");

        Node* current = head;
        Node* next = NULL;

        while(current != NULL)
        {
                next = current->next;

                free(current);

                current = next;
        }
        printf("Done.. Heap memory is cleared..\n");
}