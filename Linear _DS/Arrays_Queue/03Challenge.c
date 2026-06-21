/*
    Assignment 3: Building a Fixed-Size Array Container
Instead of moving straight to complex structures, let's write a clean, modular program that mimics how high-level languages handle arrays safely.

Your Task:
Write a C program that manages a fixed-size integer array using a structured approach. Do not use global variables.

Define a Structure: Create a struct SafeArray that holds:

A fixed integer array (e.g., size 5).

An integer tracking the current_size (how many elements are actually filled).

Implement an Append Function: Write a function int append(struct SafeArray *array, int value) that adds an element to the next available slot. If the array is full, 
    it should reject the input and return an error code.

Implement a Safe Display Function: Write a function to print the elements cleanly.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define maxSize 5

struct SafeArray {
    int data[maxSize];
    int currentSize;
};

bool append(struct SafeArray * arr, int value);
void display(int* arr);
int main()
{
    struct SafeArray array = { .currentSize=0};
    printf("------------ Safe Array Container --------------\n");

    while(1)
    {
        int option=0;
        printf("Options: 1) Append\t2) Display\t3) Exit\nSelect Option: ");
        scanf("%d", &option);
        if(option == 1)
        {
            int value,status;
            printf("Enter value to append: ");
            scanf("%d",&value);
            if(append(&array,value))
            {
                printf("Append Sucess..");
            }
            else
            {
                printf("Append Unsucessful: Container is full.!\n");
                return EXIT_FAILURE;
            }
        }
        else if(option ==2)
        {
            display(array.data);
        }

        else{
            display(array.data);
            break;
        }
    }

    return EXIT_SUCCESS;
}

bool append(struct SafeArray * arr, int value)
{
    if(arr->currentSize < maxSize)
    {
        arr->data[(arr->currentSize)] = value;
        arr->currentSize ++;
        return true;
    }
    else{
        printf("Out of Memory ... \n");
        return false;
    }
}

void display(int* arr)
{
    printf("------------ Safe-Array Display -----------\n");
    for(int i=0;i<maxSize;++i)
    {
        printf("SafeArray -> element %d: %d\n",i,arr[i]);
    }
    printf("------------ Safe-Array Display End -----------\n");
}