// Compare the adjacent elements. If the first element is greater than the second element, swap them.

#include<stdio.h>
#include<stdlib.h>

void fillArray(int arr[], int n);
void displayArray(int arr[], int n);
void bubbleSort(int arr[], int n);

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    
    //create a array of n elememts
    int arr[n];

    //fill teh Array with random numbers
    fillArray(arr,n);

    // display original Array
    printf("Original Array: ");
    displayArray(arr,n);

    // sort array using bubble sort
    bubbleSort(arr, n);

    // display sorted Array
    printf("Sorted Array: ");
    displayArray(arr,n);

    return 0;

}

void fillArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%100;
    }
}

void displayArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<(n-i-1);j++)
        {
            if(arr[j] >arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}