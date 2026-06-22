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

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#define maxSize 5

class safeArray{
    public:
        int data[maxSize];
        int currentsize;
};

bool append(safeArray* array,int value);
void display(int* array);

int main()
{
    safeArray arr = {.currentsize=0};
    cout << "\n\n-------------- Safe Array Container Implementation ------------------ " << endl;
    while(1)
    {
        int option=0;
        cout << "Options to select Functionality:" << endl <<
            "1) Append\t2)Display\t3) Exit\n"<< "Select Option: ";
        cin >> option;
        
        // Check for append selection and append the value in the Queue
        if(option ==1)
        {
            int val,status;
            cout << "Enter value to append: "; cin>>val;

            if(append(&arr,val))
            {
                cout << "Append Sucessful .." << endl;
            }
            else
            {
                cout << "Append Failed" << endl;
            }
        }
        //Check for display option and display the Queue
        else if(option == 2)
        {
            display(arr.data);
        }
        //Check for Exit selection and safely exit from the program 
        else if(option == 3)
        {
            display(arr.data);
            break;
        }
    }
    return EXIT_SUCCESS;
}

void display(int * arr)
{
    cout << "\n---------- Safe Array Display ----------" << endl;
    for(int i=0; i<maxSize;++i)
    {
        cout << "safeArrya->element " << i << ": " << arr[i] << endl;
    }
    cout << "------------------------------------------" <<endl;
}

bool append(safeArray* array,int value)
{
    if(array->currentsize < maxSize)
    {
        array->data[array->currentsize] = value;
        ++array->currentsize;
        return true;
    }
    else
    {
        cout <<"Out of memory..." << endl;
        return false;

    }
}