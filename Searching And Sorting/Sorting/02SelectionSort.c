#include<stdio.h>
#include<stdlib.h>

void takeArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%100;
    }
    return;
}

void displayArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= (n - 2); i++)
    {
        int min_index = i;
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
int main()
{
    int n;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    takeArray(arr, n);
    printf("Original array: ");
    displayArray(arr, n);

    selectionSort(arr,n);
    printf("Sorted array: ");
    displayArray(arr,n);

    return 0;
}

