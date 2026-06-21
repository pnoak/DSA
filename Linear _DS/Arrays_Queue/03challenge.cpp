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
void display();

int main()
{
     

}
