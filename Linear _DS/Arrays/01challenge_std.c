/*
Challenge 1: The Dynamic Integer Array (Warm-up)Objective: Handle basic dynamic allocation, resizing, and memory 
            cleanup.
        Task: Write a program that prompts the user to enter "N" integers. Allocate memory dynamically for 
            these "N" integers.Twist: After reading the initial "N" integers, ask the user for "M" additional integers.
             Resize the allocated memory block to hold "N + M" elements without losing the original data. 
             Print the entire final array, and then free all allocated memory.
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    int base_size,extra_size,final_size;
    int *base_ptr=NULL;

    //Taking No. of elements for Dynamically allocating memory
    printf("Enter number of Elements:");
    if(scanf("%d",&base_size)!=1 || (base_size <=0))
    {
        fprintf(stderr,"Error: Invalid values to take input\n");
        return EXIT_FAILURE;
    }

    //Initialisation and allocation of memory Dynamically for entered values 
    printf("------------ Initializing the dynamic memory -------------\n");
    base_ptr = malloc(base_size * sizeof(int));
    if(base_ptr == NULL )
    {
        fprintf(stderr,"Error:Memory not Initialized..\n");
        return(EXIT_FAILURE);
    } 


    printf("Enter %d Elements: ",base_size);
    for(int i=0;i<base_size;++i)
    {
        if(scanf("%d",base_ptr+i) !=1)
        {
            fprintf(stderr,"Error:invalid Input..\n");
            free(base_ptr);
            return EXIT_FAILURE;
        }
    }

    //requesting for additional No. of elements
    printf("Enter no. of additional elements: ");
    scanf("%d",&extra_size);
    if(extra_size != 0)
    {
        printf("Accepted\n");
    }

    //Reallocating the Dynamic memory for requested 
    final_size = base_size + extra_size;
    int * temp = realloc(base_ptr,final_size*sizeof(int));
    if(temp == NULL)
    {
        fprintf(stderr, "Error:Reallocation Failed");
        free(base_ptr);
        return EXIT_FAILURE;
    }

    base_ptr = temp;

    //Initilising with new elements
    printf("Enter %d additional elements: ",extra_size);
    for(int i=base_size; i<final_size;++i)
    {
        if(scanf("%d",base_ptr+i) != 1)
        {
            fprintf(stderr,"Error: Invalid Integer value\n");
            free(base_ptr);
            return EXIT_FAILURE;
        }
    }

    // Final Output

    printf("\n\n\033[1m------------ Final Output ------------[0m\n");
    for(int i=0; i<final_size;++i)
    {
        printf("Element[%d]: %d\n",i,base_ptr[i]);
    }


    // Memory Clanup 
    free(base_ptr);
    base_ptr == NULL;
    temp==NULL;

    return 0;
}
