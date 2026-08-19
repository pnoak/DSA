#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct cirNode{
    int data;
    struct cirNode* next;
    struct cirNode* prev;
}cNode;

bool cllAppend(cNode** head, int data);
bool cllInsert(cNode** head, int data, int position);
void display(cNode* head);
void freecll(cNode* head);

int main()
{
    cNode* head = NULL;
    int option=0;
    
    while(true)
    {
        printf("Functionalities of Circular Linked List \n1)Append Node\n2)Insert Element at a position\n3)Display Circular List\n4)Free List\n5) Exit\n Select option: ");
        scanf("%d",&option);

        switch (option)
        {
            case 1:
            {
                int data;
                printf("Enter the data to append: ");
                scanf("%d",&data);  
                if(cllAppend(&head,data))
                {
                    printf("Node appended successfully\n");
                }
                else
                {
                    printf("Node append failed\n");
                }
                break;
            }

            case 2:
            {
                int data,position=0;
                printf("Enter the data to insert: ");   
                scanf("%d",&data);
                printf("Enter the position to insert: ");
                scanf("%d",&position);
                if(cllInsert(&head,data,position))
                {
                    printf("Node Inserted Sucessfully\n");
                }
                else
                {
                    printf("Node Insert failed\n");
                }
                break;
            }
            case 3:
            {
                display(head);
                break;
            }
            case 4:
            {
                freecll(head);
                head = NULL;
                break;
            }
            case 5:
            {
                freecll(head);
                head = NULL;
                printf("Exiting the program\n");
                return EXIT_SUCCESS;
            }
            default:
            {
                printf("Invalid option selected\n");
                break;
            }
        }
    }
}

bool cllAppend(cNode** head, int data)
{
    // allocate heap memory for new node
    cNode* newNode = (cNode*)malloc(sizeof(cNode));
    if(newNode == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        return false;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    // check for uninitialised list
    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return true;
    }
    // for already initialised linked list
    else
    {
        cNode* temp = *head;
        while(temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *head;
        (*head)->prev = newNode;
        return true;
    }
}

bool cllInsert(cNode** head, int data, int position)
{
    cNode* newNode = (cNode*)malloc(sizeof(cNode));
    if(newNode == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        return false;
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Insert at the beginning
    if(position == 0)
    {
        if(*head == NULL)
        {
            *head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            cNode* last = (*head)->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
        return true;
    }

    // Insert at a specific position
    cNode* temp = *head;
    for(int i = 0; i < position - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    if(temp->next == *head && position > 0)
    {
        fprintf(stderr,"Invalid position\n");
        free(newNode);
        return false;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return true;
}
void display(cNode* head)
{
    printf("============== Display Function ==============\n");
    if(head == NULL)
    {
        printf("Circular Linked List is empty\n");
        return;
    }
    cNode* temp = head;
    do
    {
        printf("Node Data: %d\n",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("==============================================\n");
}

void freecll(cNode* head)
{
    if(head == NULL)
    {
        return;
    }

    cNode* next = NULL;
    cNode* current = head;
    cNode* last = current->prev;
    last->next = NULL;            // Break the circular loop 
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}