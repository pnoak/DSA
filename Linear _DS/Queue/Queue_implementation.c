#include<stdio.h>
#define MAX 5

int info[MAX];
int rear,front;     /* To maintain rear and front end of Queue */

/* Function Declarations */
void init();        // To initialize Queue
int isFull();       // to check the Queue is full or not 
int isEmpty();      //To check the Queue is empty or not
void push(int);     // To enter the elements in the queue
void pop();         // to delete the elements from the queue
int peek();         // to get the value from the queue without deleting


int main()
{
    int choice,value;
    init();

    do{
        printf("\n\n0.Exit\n1.Push\n2.Pop\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:             /* Push */
                if(isFull())
                {
                    printf("The Queue is full.");
                }
                else{
                    printf("Entere the value to Push :");
                    scanf("%d",&value);
                    push(value);
                    printf("Value Pushed : %d",value);
                }
                break;

            case 2:
                if(isEmpty())
                {
                    printf("The queue is Empty");
                }
                else{
                    value = peek();
                    pop();
                    printf("Poped value : %d", value);
                }break;

        }
    }while(choice != 0);
    return 0;
}


/* Function Definations */

void init()        // To initialize Queue
{
    int i=0;
    rear=-1;
    front = -1;
    for(i=0;i<MAX;i++)
    {
        info[i]= -1;
    }
}
int isFull()       // to check the Queue is full or not
{
    if(rear == (MAX-1))
        return 1;       //Queue is full
    else
        return 0;       // Queue is not Full
}   
int isEmpty()      //To check the Queue is empty or not
{
    if(rear == front)
        return 1;       // Queue is empty
    else 
        return 0;       // Queue is not empty 
}
void push(int data)     // To enter the elements in the queue
{
    rear = rear + 1;
    info[rear] = data;
}
void pop()         // to delete the elements from the queue
{
    front = front + 1;
    info[front] = -1;    
}
int peek()         // to get the value from the queue without deleting
{
    return info[front+1];
}
