#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int Data;
    struct node* next;
}lNode;

bool insertNode(lNode**, int);
bool deleteNode(lNode**, int);
bool reverseList(lNode**);
bool displayList(lNode**);
bool freeList(lNode**);

int main()
{
    lNode* head = NULL;

    // insert a test data into the linked list
    for(int i=0; i<5; i++)
    {
        if(insertNode(&head, (int)(rand()% 100 + 1)))
        {
            printf("Node Inserted Sucessfully\n");
        }
        else
        {
            printf("Node Insert failed\n");
        }
    }

    //Display the linked list
    if(displayList(&head))
    {
        printf("List Displayed Sucessfully\n");
    }
    else
    {
        printf("List Display failed\n");
    }

    //Reverse the linked list
    if(reverseList(&head))
    {
        printf("List Reversed Sucessfully\n");
    }
    else
    {
        printf("List Reverse failed\n");
    }

    //Display the linked list after reversal
    if(displayList(&head))
    {
        printf("List Displayed Sucessfully\n");
    }
    else
    {
        printf("List Display failed\n");
    }

    //free the Allocated Data 
    if(freeList(&head))
    {
        printf("List Freed Sucessfully\n");
    }
    else
    {
        printf("List Free failed\n");
    }

    //Display the linked list after freeing the data
    if(displayList(&head))
    {
        printf("List Displayed Sucessfully\n");
    }
    else
    {
        printf("List Display failed\n");
    }

    return 0;
}


bool insertNode(lNode** head, int data)
{
    lNode* newNode = (lNode*)malloc(sizeof(lNode));
    if(newNode == NULL)
    {
        fprintf(stderr,"Memory allocation failed\n");
        return false;
    }


    if (*head == NULL)
    {
        newNode->Data = data;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->Data = data;
        newNode->next = NULL;

        lNode* temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return true;
}

bool displayList(lNode** head)
{
    if(*head == NULL)
    {
        fprintf(stderr,"List is empty\n");
        return false;
    }

    lNode* temp = *head;
    unsigned int cnt = 0;
    while(temp != NULL)
    {
        printf("Node %d: %d\n", cnt, temp->Data);
        temp = temp->next;
        ++cnt;
    }
    return true;
}

bool reverseList(lNode** head)
{
    if(*head == NULL)
    {
        fprintf(stderr,"List is empty\n");
        return false;
    }

    lNode* prev, *next, *current;
    prev = NULL;
    current = *head;
    next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    return true;
}

bool freeList(lNode** head)
{
    if(*head == NULL)
    {
        fprintf(stderr,"List is empty\n");
        return false;
    }

    lNode* temp = *head;
    while(temp != NULL)
    {
        lNode* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    return true;
}