/*
Challenge 1: The Dynamic Integer Array (Warm-up)Objective: Handle basic dynamic allocation, resizing, and memory 
            cleanup.
        Task: Write a program that prompts the user to enter "N" integers. Allocate memory dynamically for 
            these "N" integers.Twist: After reading the initial "N" integers, ask the user for "M" additional integers.
             Resize the allocated memory block to hold "N + M" elements without losing the original data. 
             Print the entire final array, and then free all allocated memory.
*/

#include <stdio.h>
#include<stdlib.h>


int main()
{
    int n1,n2,n3,updated_size;
    printf("Enter 3 Numbers: ");
    scanf("%d %d %d", &n1,&n2,&n3);
    
    // Allocate dynamic memory
    int* ptr = malloc(3*sizeof(int));
    if(ptr == NULL)
    {
        printf("Error in allocataion of memory");
        return (-1);
    }

    //Assign value to dyanamically allocated memory 
    *ptr = n1;
    *(ptr+1)= n2;
    *(ptr+2)=n3;

    printf("------------ Cross Verification of memory ------------------\nDyna_n1=%d\nDyna_n2=%d\nDyna_n3=%d\n--------------- Cross Verification Complete ---------------\n",*ptr,*(ptr+1),*(ptr+2));

    
    printf("Enter Number you want to add : ");
    scanf("%d", &updated_size);

    ptr = realloc(ptr,(3+updated_size)* sizeof(int));
    if(ptr==NULL)
    {
        printf("memory reallocation failed ..");
        return(-1);
    }

    printf("Enter Values: ");
    for(int i=3; i<(3+updated_size);++i){
        scanf("%d",&ptr[i]);
    }

    printf("---------------- Final Output -----------------------");
    for(int i=0;i<(3+updated_size); ++i)
    {
        printf("n%d : %d",i,ptr[i]);
    }

    return (0);
} 