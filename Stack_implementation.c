#include <stdio.h>

#define MAX 5

int st_info[MAX];   // Stack- for element Storage 
int top;            // to maintain top of stack

/*Function Declarations*/
void init();        // to init the variables 
int isFull();       // to check whether stack is full or not
int isEmpty();      // to check wheather stck is empty or not 
void push(int);     // add the new element on top of stack 
void pop();         // to get top element from stack and delete that element 
int peek();         // to get the top element without deletation

int main()
{
    int choice = 15 , value = 0;

    init();

    do
    {
        printf("\n\n0.Exit\n1.Push\n2.Pop\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:             //Push
                if(isFull())
                {
                    printf("The stack is Full ");
                }
                else
                {
                  printf("Enter the Value: ");
                  scanf("%d", &value);
                  push(value);
                  printf("Value Pushed!!\n value: %d",value);  
                }
                break;
            
            case 2:                //Pop
                if(isEmpty())
                {
                    printf("Stack is Empty !!");
                }
                else{
                    value = peek();
                    pop();
                    printf("Value poped : %d", value);
                }
                break;
        }

    }while (choice != 0);

    return 0;
}

/* Function Definations  */
void init()        // to init the variables 
{
    top = -1;               // Top is init to -1 
    for (int i = 0; i < MAX; i++)
    {
        st_info[i] = -1;
    }
    
}
int isFull()       // to check whether stack is full or not
{
    if(top == MAX-1)
        return 1;   //stck is full
    else
        return 0;
}
int isEmpty()      // to check wheather stck is empty or not 
{
    if(top == -1)
        return 1;       // stck is empty
    else 
        return 0;
}

void push(int val)     // add the new element on top of stack 
{
    top = top + 1;
    st_info[top] = val;
}
void pop()         // to get top element from stack and delete that element 
{
    st_info[top] = -1;
    top = top - 1;
}
int peek()         // to get the top element without deletation
{
    return (st_info[top]);
}
