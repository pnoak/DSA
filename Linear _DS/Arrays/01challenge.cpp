/*
Challenge 1: The Dynamic Integer Array (Warm-up)Objective: Handle basic dynamic allocation, resizing, and memory 
            cleanup.
        Task: Write a program that prompts the user to enter "N" integers. Allocate memory dynamically for 
            these "N" integers.Twist: After reading the initial "N" integers, ask the user for "M" additional integers.
             Resize the allocated memory block to hold "N + M" elements without losing the original data. 
             Print the entire final array, and then free all allocated memory.
*/

#include<iostream>
#include<string>
#include<cstdlib>

int main()
{
    int size,extra,final;
    int * base_ptr = NULL;

    // Requesting User for No. of Elements to allocate dynamic memory
    std::cout << "Enter number of elements: ";
    if(!(std::cin >> size) || (size <=0))
    {
        std::cerr << "Error : Invalid No. of elemnts " << std::endl;
        return EXIT_FAILURE;
    }

    // Allocation of Dynamic Memory for entered No. of elements 
    std::cout << "------------ Initializing the dynamic memory -------------" << std::endl;
    base_ptr = new int [size];
    if(base_ptr == NULL)
    {
        std::cerr << "Error: Memory is not alloccated " << std::endl;
        return EXIT_FAILURE;
    }

    // initialisation of elements
    std::cout << "Enter " << size << " Elements: ";
    for (int i=0; i < size; ++i)
    {
        if(!(std::cin >> base_ptr[i]))
        {
            std::cerr << "Error: Invalid Input " << std::endl;
            delete[] base_ptr;
            return EXIT_FAILURE;
        }
    }

    // Requesting User for No. of additional elements to allocate dynamic memory
    std::cout << "Enter No. of elements to add in Memory: ";
    if(!(std::cin >> extra) || (extra < 0))
    {
        std::cerr << "Error: Invalid No. of extra Elemts " << std::endl;
        delete [] base_ptr;
        return EXIT_FAILURE;
    }

    final = size + extra;

    // Reallocation of dyanamic memory for requested elelments
    std::cout << "------------ Reallocating the dynamic memory -------------" << std::endl;
    int *temp = new int [final];
    if(temp == NULL)
    {
        std::cerr << "Error: Memory is not alloccated " << std::endl;
        delete[] base_ptr;
        return EXIT_FAILURE;
    }

    // Copying the old data to new memory block
    for(int i=0; i<size; ++i)
    {
        temp[i] = base_ptr[i];
    }

    delete[] base_ptr; // Freeing the old memory block

    base_ptr = temp; // Pointing to new memory block

    // Initialisation of new elements
    std::cout << "Enter new " << extra << " elements" <<std :: endl;
    for (int i=size;i<final;++i)
    {
        if(!(std::cin >> base_ptr[i]))
        {
            std::cerr <<"Error: Invalid Input " << std::endl;
            delete[] base_ptr;
            return EXIT_FAILURE;
        }
    }

    // Final Output Printing 

    std:: cout << "\n\n -------------- Final Array --------------" << std::endl;
    for (int i=0; i<final;++i)
    {
        std::cout << "Element " << i+1 << ": " << base_ptr[i] << std::endl;
    }

    // Free the Dynamically allocated memory
    delete [] base_ptr;

    return EXIT_SUCCESS;
}