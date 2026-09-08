// Assignment 17: Binary search implementation on sorted array or list 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Function Declarations 

int binarySearch(int arr[], int size, int target_number);
void displayArray(int arr[], int size);


int main()
{
    int target_number= 0,foundIndex = 0;

    int arr[] = {11, 24, 35, 43, 57, 63, 75, 81, 90, 100};
    int size = sizeof(arr)/ sizeof(arr[0]);

    printf("The sorted array is: ");
    displayArray(arr,size);

    printf("Enter the number to search: ");
    scanf("%d",&target_number);

    foundIndex = binarySearch(arr,size,target_number);

    if(foundIndex != -1)
    {
        printf("Number found at index: %d\n", foundIndex);
    }
    else
    {
        printf("Number not found in the array.\n");
    }

    return EXIT_SUCCESS;
}

void displayArray(int arr[],int size)
{
    for( int i=0;i<size; i++)
    {
        printf("%d \n",arr[i]);
    }
    return;
}

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}