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

// Header File Inclusion 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/// @brief Structure Definition for a Node in a Doubly Linked List

typedef struct doubleNode{
    struct doubleNode * prev;
    int data;
    struct doubleNode* next;
}node;

/// @brief Function to select functionality of the program  
bool appendDLL(node ** headref, int val);
bool insertAtPosition(node ** headref, int val, int pos);
void  displayForwardDLL(node* head);
void  displayBackwardDLL(node* head);
bool deleteNodeDLL(node ** headref, int pos);
void freeListDLL(node * head);


/// @brief Main Function to drive the program
int main()
{
    node *head = NULL;
    int opt;
    printf("\n=================================================================================================================\n");
    printf("\tDoubly Linked List full Implementation");
    printf("\n=================================================================================================================\n");
    while (true)
    {
        printf("Select an option from the menu below to use functionality:\n");
        printf("1) Append Node at the end\n");
        printf("2) Insert Node at specified position\n");
        printf("3) Display List Forward\n");
        printf("4) Display List Backward\n");
        printf("5) Delete Node at specified position\n");
        printf("6) Free Entire List\n");
        printf("7) Exit\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &opt) != 1)
        {
            fprintf(stderr, "Error:Invalid Input from user\nplease try again..\n");
            while (getchar() != '\n');       // Flust the Bad Input
            printf("------------------------------------------------------------------------------------\n");
        }

        // Append Functionality 
        if(opt == 1)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Append Node at the end' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int val;
            node * newNode = (node*)malloc(sizeof(node));
            if(newNode == NULL)
            {
                fprintf(stderr,"Error:Memory allocation failed..\n");
                if(head != NULL)
                {
                    freeListDLL(head);
                }
                else
                    return EXIT_FAILURE;
            }
            printf("Enter the value: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }
            else{
                if(appendDLL(&head,val))
                {
                    printf("\nAppend Sucess..!!\n");
                }
                else   
                    printf("\nAppend Failed..!!\n");
            }
            printf("------------------------------------------------------------------------------------\n");      
        }

        // Insert at specific position functionality 
        else if(opt == 2)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Insert Node at specified position' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int val,pos;
            printf("Enter the position to insert data: ");
            if(scanf("%d",&pos)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }
            printf("\nEnter val to insert: ");
            if(scanf("%d",&val)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
                continue;
            }

            if (insertAtPosition(&head, val, pos))
            {
                printf("\nAppend Sucess..!!\n");
            }
            else
                printf("\nAppend Failed..!!\n");
            
            printf("------------------------------------------------------------------------------------\n");
        }

        // LinkedList Traversal from Forward to Dispplay the List 
        else if(opt == 3)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Display List Forward' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");


            displayForwardDLL(head);
            printf("------------------------------------------------------------------------------------\n");
        }

        // LinkedList Traversal from Backward to Dispplay the List 
        else if(opt == 4)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Display List Backward' functionality selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            displayBackwardDLL(head);
            printf("------------------------------------------------------------------------------------\n");

        }

        // deletion functionality to delete specific node or data
        else if(opt == 5)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Delete Node at specified position' Functionality Selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            int pos=0;

            printf("Enter Position to Delete Node: ");
            if(scanf("%d",&pos)!= 1)
            {
                fprintf(stderr,"Error:Invalid Input from user..\n");
                while(getchar()!='\n');
            }
            else{
                if(deleteNodeDLL(&head,pos))
                {
                    printf("\nNode Deletion Sucess..!!\n");
                }
                else   
                    printf("\nNode Deletion Failed..!!\n");
            }

            printf("------------------------------------------------------------------------------------\n");

        }

        // Free Heap memory Functionality 
        if(opt == 6)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'Free Entire List' Functionality Selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            freeListDLL(head);
            printf("------------------------------------------------------------------------------------\n");
        }

        // Exit functionality 
        else if(opt == 7)
        {
            printf("\n------------------------------------------------------------------------------------\n");
            printf("'EXIT' Functionality Selected..\n");
            printf("------------------------------------------------------------------------------------\n");

            printf("Procedure to free the memory started..\n");
            freeListDLL(head);
            printf("Procedure Complete..\n");
            printf("------------------------------------------------------------------------------------\n");
            return EXIT_SUCCESS;
        }

        else{
            fprintf(stderr,"Error: Wrong Input.. Please try again ...\n");
            while(getchar()!='\n');
            continue;
        }
    }
}

/// @brief Append the new node with data to the end of the list,if it is not initialised then add node to the first position(i.e.Index "0")
///            and update double pointer to head reference pointing to the newly allocated node on heap  
/// @param headref double pointer tho the head for storing the address of the first node.
/// @param val integer value to store in the node
/// @return returns boolian value
bool appendDLL(node ** headref, int val)
{
    node * newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL)
    {
        fprintf(stderr,"Error:Memory Allocation failed.. please try again \n");
        return false;
    }

    //Add user value to the Data member and attach the list to ground from both the side 
    newNode->prev = NULL;
    newNode->data = val;
    newNode->next = NULL;

    //Check for empty list 
    if(*headref == NULL)
    {
        *headref = newNode;
        return true;
    }

    // If list is not empty then go at end of list and append the node 
    node* current = *headref;
    while(current->next != NULL)
    {
        current = current->next;        // This will stop traversing on the end node
    }
    // wire the previous node with the new
    newNode->prev = current;
    newNode->next = NULL;
    current->next = newNode;

    return true;
}

/// @brief Insertion of the node in doubly Linked List at Specific position 
/// @param headref Double pointer to the starting of the LLinked List
/// @param val Integer Data to be stored on the node
/// @param pos Index where to add the node 
/// @return Returns Boolian value, for the failure of teh procedure false be the return value othervise true.
bool insertAtPosition(node ** headref, int val, int pos)
{
    int cnt=0;
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        fprintf(stderr,"Error:Memory allocation on Heap is failed ..please try again..\n");
        return false;
    }
    newNode->data = val;
    newNode->next= NULL;
    newNode->prev = NULL;

    if (*headref == NULL)
    {
        *headref = newNode;
        return true;
    }
    else if (pos < 0)
    {
        printf("Please Enter a valid Index to append Node\n");
        free(newNode);
        return false;
    }
    else if(pos == 0)
    {
        node* current = *headref;
        newNode ->next = current;
        newNode->prev = NULL;
        current->prev = newNode;
        *headref = newNode;
        return true;
    }
    else if(pos>0)
    {
        node*current = *headref;
        while(current != NULL && cnt<(pos-1))
        {
            current=current->next;
            ++cnt;
        }
        if(current==NULL && cnt<pos)
        {
            printf("Error:Index out of reach\nPlease try again with valis index...\n");
            free(newNode);
            return false;
        }
        else if(current !=NULL && (current->next== NULL))
        {
            current->next=newNode;
            newNode->prev = current;
            newNode->next = NULL;
            return true;
        }
        else{
            newNode->next = current->next;
            current->next->prev = newNode;
            newNode->prev= current;
            current->next= newNode;
            return true;
        }
    }
}

/// @brief Displaying the list from the front till end 
/// @param head Pointer to the head of the Linked List
void  displayForwardDLL(node* head)
{
    node* current = head;
    if(current == NULL)
    {
        printf("Please append the node to the list, after that use this funtionality..\n");
        return;
    }
    else{
        int cnt=0;
        while(current!=NULL)
        {
            printf("Node %d: %d\n",cnt,current->data);
            current = current->next;
            ++cnt;
        }
        printf("------------------------------------\n");
        printf("Total Number Of nodes: %d\n",cnt);
    }
}

/// @brief Displaying the list from the end till front
/// @param head Pointer to the head of the Linked List
void  displayBackwardDLL(node* head)
{
    node* current = head;
    if(current == NULL)
    {
        printf("Please append the node to the list, after that use this funtionality..\n");
        return;
    }
    else{
        int cnt=0;
        //Go to the end of the List 
        while(current->next!= NULL)
        {
            current = current->next;
            ++cnt;
        }

        while(current != NULL)
        {
            printf("Node %d: %d\n",cnt,current->data);
            current= current->prev;
            --cnt;
        }
    }
}

/// @brief Function to Delete and free the memory of the node for particular position 
/// @param headref Double pointer for the list trversal and head of the List 
/// @param pos Interger value which defines the position of the node to delete data and free heap memory 
/// @return    returns the boolian value 
bool deleteNodeDLL(node ** headref, int pos)
{
    int cnt=0;
    node* current = *headref;
    if(current == NULL)
    {
        fprintf(stderr,"Error: List is nor initialized..\n please append the data and Enter valid Location to delete node..\n");
        return false;
    }
    else{
       if(pos<0)
       {
            printf("Please Enter valid Position..\n");
            return false;
       }
       else if (pos == 0)
       {
           *headref = current->next;
           if (*headref != NULL)
           {

               (*headref)->prev = NULL;
           }
           free(current);
           return true;
       }
       else
       {
            while((current != NULL) && (cnt<pos))
            {
                current = current->next;
                ++cnt;
            }

            if(current == NULL)
            {   
                printf("Out of Bound ...\nPlease enter valid position..\n");
                return false;
            }
            else{
                if(current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
                if(current->prev != NULL)
                {
                    current->prev->next = current->next;
                }
                free(current);
                return true;
            }
       }
    }
}

/// @brief This function clears the whole list of nodes and releases the heap memory 
/// @param head Pointer to the head of the Linked List
void freeListDLL(node *head)
{
    if (head == NULL)
    {
        printf("No Need to free the List..\n");
    }
    else
    {
        node *current = head;
        node *next = NULL;
        int cnt = 0;
        while (current != NULL)
        {
            next = current->next;
            free(current);
            printf("Node %d freed.\n", cnt);
            cnt++;
            current = next;
        }
        head = NULL;
    }
}