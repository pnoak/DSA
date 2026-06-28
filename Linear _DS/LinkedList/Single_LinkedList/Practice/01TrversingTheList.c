/*  
    C code to trvers the list and count the number of nodes in the list 
 */

 #include<stdio.h>
 #include<stdlib.h>
#include<stdbool.h>

 typedef struct node{
    int intData;
    struct node* next; 
 }Node;

bool append(Node** headRef, int val);
int count(Node* head);
void display(Node* head);
void freeList(Node* head);

int main()
{
    Node* head= NULL;
    int option =0;
    int value =0;
    printf("------------ Traversing the list --------------------\n");
    while (true)
    {
        printf("optins to select operation:\n1) Append data on next node\n2) Display List\n3) Count\n4) Exit\n Select Option: ");
        if (scanf("%d", &option) != 1)
        {
            fprintf(stderr, "Error: Invalid Input please try again..\n");
        }
        if (option == 1)
        {
            printf("Enter value to append: ");
            if (scanf("%d", &value) != 1)
            {
                fprintf(stderr, "Error: inavlid Input..\n");
                free(head);
                head = NULL;
                return EXIT_FAILURE;
            }

            if (append(&head, value))
            {
                printf("Append Sucess..\n");
            }
            else
                printf("Append Failed..\nplease try agin\n");
        }
        else if (option == 2)
        {
            display(head);
        }
        else if (option == 3)
        {
            printf("Count of Node in the list: %d\n", count(head));
        }
        else if (option == 4)
        {
            printf("Program Exit sequence Initialized ..\n");
            freeList(head);
            printf("Sequence Complete..\nExiting..");
            return EXIT_SUCCESS;
        }
        else
            printf("Invalid Input.. please try again ");
    }

    return EXIT_SUCCESS;
}

bool append(Node** headRef, int val)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error: Memory initilization failed\n");
        return false;
    }

    newNode->intData = val;
    newNode->next = NULL;

    if(*headRef==NULL)
    {
        *headRef = newNode;
    }
    else
    {
        Node * current  = *headRef;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return true;
}

int count(Node* head)
{
    int cnt=0;
    Node* current = head;
    if(head == NULL)
    {
        printf("Linked List is not initialized yet ...\n");
        return cnt;
    }

    while (current != NULL)
    {
        ++ cnt;
        current = current->next; 
    }
    return cnt;
    
}

void display(Node* head)
{
    printf("--------------- Linked List status -----------------\n");
    Node* current=head;
    int i=0;
    if(current == NULL)
    {
        printf("Linked List is empty\n");
        printf("-----------------------------------------------------\n");
        return;
    }
    while(current != NULL)
    {
        printf("Node%d: %d\n",i,current->intData);
        ++i;
        current = current->next;
    }
    printf("-----------------------------------------------------\n");
}

void freeList(Node* head)
{
    printf("Clearing Heap memory Node By Node...");
    Node * current = head;
    Node * next = NULL;

    while(current != NULL)
    {
        next = current ->next;
        free(current);
        current = next;
        printf(".");
    }
    printf("\n Heap memory Cleared..");
}