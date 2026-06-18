/*

Assignment 5: Building a Dynamic Vector Container
Your Task:
Write a modular C program that implements a custom integer Vector. 

Requirements:
Define the Structure: Create a struct MyVector holding int *data, int size,
                         and int capacity.

Implement Initialization: Write a function void vector_init(struct MyVector *v, int initial_capacity) 
                            that allocates the initial heap memory using malloc.

Implement Append: Write int vector_append(struct MyVector *v, int value) that adds elements and automatically 
                    doubles the capacity using realloc if the vector fills up.

Implement Display: Write a function to print the current size, capacity, and active 
                    elements cleanly.

Implement Cleanup: Write a function to free the heap memory when done to prevent leaks.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct myVector
{
    int *data;
    int size,capacity;
};

bool init_vector(struct myVector* vec, int init_capacity);
bool vectorAppend(struct myVector* vec,int val);
void dispVector(struct myVector* vec);
void freeVector(struct myVector* vec);

int main()
{
    struct myVector dynaVec;

    //initialize the vector with small capaciy 
    if(init_vector(&dynaVec,2)==false)
    {
        printf("Error: Memory allocation failed..\n");
        return EXIT_FAILURE;
    }

    printf("---------- Dynamic Vector Implementation -----------\n");

    int option=0;
    while(true)
    {
        printf("\nOptins:\n1)Append in Vector\n2) Display Vector\n3)Exit From Vector\nSelect your Option: ");
        if(scanf("%d",&option)!=1)
        {
            printf("Error: Invalid input\n Exiting Safely...\n");
            dispVector(&dynaVec);
            free(dynaVec.data);
            dynaVec.data == NULL;
            return EXIT_FAILURE;
        }

        if (option == 1)
        {
            int val = 0;
            printf("Enter value to append: ");
            if (scanf("%d", &val) != 1)
            {
                printf("Error: Invalid input\n Exiting Safely...\n");
                dispVector(&dynaVec);
                return EXIT_FAILURE;
            }
            if(vectorAppend(&dynaVec,val))
            {
                printf("Append Sucess..\n");
            }
            else{
                printf("Error Append failed.");
            }
        }
        else if(option == 2)
        {
            dispVector(&dynaVec);
        }
        else if(option==3)
        {
            dispVector(&dynaVec);
            freeVector(&dynaVec);
            printf("Exiting from Program");
            break;
        }
        else{
            printf("Error: Invalid Input..!\nTry again..\n");
        }
    }

    
    return EXIT_SUCCESS;
}

bool init_vector(struct myVector* vec, int init_capacity){
    printf("Initializing Vector..\n");
    vec->capacity=init_capacity;
    vec->data=0;
    vec->size=0;
    vec->data = malloc(vec->capacity *sizeof(int));
    if(vec->data== NULL)
    {
        fprintf(stderr,"Error: Memory allocation failed..\n");
        return false;
    }
    printf("Completed\n");
    return true;
}


bool vectorAppend(struct myVector* vec,int val){
    if(vec->size == vec->capacity)
    {
        printf("Dynamic Vector Re-allocation: starting...\n");
        int* temp = realloc(vec->data,(vec->capacity*2)*sizeof(int));
        if(temp==NULL)
        {
            fprintf(stderr,"Error: Memory allocation failed..\n");
            return false;  
        }
        vec->data = temp;
        vec->capacity = (vec->capacity * 2);
        printf("Re-allocation sucessful ..!!\n");
    }
    vec->data[(vec->size)] = val;
    ++ vec->size;
    return true;
}


void dispVector(struct myVector* vec){
    printf("--- Vector Status ---\n");
    for(int i=0;i<vec->size;++i)
    {
        printf("Vector->element%d: %d\n",i,vec->data[i]);
    }
}


void freeVector(struct myVector* vec){
    printf("De-allocating the dyanamic memory...\n");
    free(vec->data);
    printf("Done..!");

}