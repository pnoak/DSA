#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool LinearSearch(const int [],int, int*);
bool RandomArrayGeneration(int*);
void displayArray(int*);

int main()
{
    //Array of size 10
    int arr[10];
    if(!RandomArrayGeneration(arr))
    {
        fprintf(stderr,"Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    // Display randomly generated array of size 10
    displayArray(arr);

    // Search for a number in the array
    int searchNum;
    int foundAtIndex = 0;
    printf("Enter the number to search: ");
    scanf("%d",&searchNum);
    if(LinearSearch(arr,searchNum,&foundAtIndex))
    {
        printf("The number %d is found in the array at index %d\n",searchNum,foundAtIndex);
    }
    else
    {
        printf("The number %d is not found in the array\n",searchNum);
    }

    return EXIT_SUCCESS;
}

bool RandomArrayGeneration(int* arr)
{
    for(int i=0;i<10;i++)
    {
        arr[i] = (rand() % 100+1);
    }
    return true;
}

void displayArray(int* arr)
{
    printf("The generated array: \n");
    for(int i=0;i<10;i++)
    {
        printf("%d\n ",arr[i]);
    }
    printf("\n");
}

bool LinearSearch(const int arr[],int searchNum, int* FoundIndex)
{
    for(int i=0;i<10;i++)
    {
        if(arr[i] == searchNum)
        {
            *FoundIndex = i;
            return true;
        }
    }
    return false;
}