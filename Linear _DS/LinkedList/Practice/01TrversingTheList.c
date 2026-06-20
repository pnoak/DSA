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

bool append(Node* head, int val);
void display(Node* head);

int main()
{
    Node* head= NULL;
    int option =0;
    int value =0;
    printf("------------ Traversing the list --------------------\n");

    printf("optins to select operation:\n1) Append data on next node\n2) Display List\n3) Exit\n Select Option: ");
    if(scanf("%d",&option)!=1)
    {
        fprintf(stderr, "Error: Invalid Input please try again..\n");
    }

    switch(option)
    {
        case 1:
        {
            head = (Node*)malloc(sizeof(Node));
            if(head == NULL)
            {
                printf("Error: Memory allocatioin failed\n");
                return EXIT_FAILURE;    
            }

            printf("Enter value to append: ");
            if(scanf("%d",&value) !=1)
            {
                fprintf(stderr,"Error: inavlid Input..\n");
                free(head);
                head = NULL;
                return EXIT_FAILURE;
            }

            if(append(&head,value))
            {
                printf("Append Sucess..\n");
            }
            else
                printf("Append Failed..\nplease try agin\n");
        }

        case 2:
        {
            
        }
    }
}