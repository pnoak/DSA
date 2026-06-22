/* function to insert the Node at 1st position of Linked List */

#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL inserFirst(struct node**, int);
void display(struct node*);
int count (struct node*);

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* head = NULL;
    insertFirst(&head, 11);     // Function Call
    insertFirst(&head, 21);
    insertFirst(&head, 31);
    insertFirst(&head, 41);

    display(head);
    int ret = count (head);
    printf("Total no. of nodes are : %d\n",ret);
    return 0;
}

BOOL inserFirst(struct node** first,int val)
{
    struct node* newNode = NULL;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        return FALSE;
    }

    /* Memoru Allocation */
    newNode -> data = val;
    newNode ->next = NULL;
}