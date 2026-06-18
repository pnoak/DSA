/*
Challenge 2: The String Concatenation Engine (Intermediate)
Objective: Avoid buffer overflows by calculating memory requirements dynamically at runtime.

Task: Create a function with the signature char* dynamic_concat(const char* str1, const char* str2).

Twist: Inside the function, calculate the exact length of both strings, allocate a precise amount of memory on the heap
     to store the combined string (plus the null-terminator \0), concatenate them, and return the pointer. In your main function,
     call this engine, print the result, and ensure no memory leaks occur.
*/

#include<iostream>
#include<string>
#include<cstdlib>

using std::string;

int main()
{
    std::cout << "-------------- Dynamic String Concatination Engin --------------" << std::endl;

    string string1;
    string string2;
    string finalString;
    

    //Requesting user to enter 1st string
    std::cout << "Enter 1st and 2nd String: " ;
    std::cin >> string1 >> string2;

    finalString = string1 + string2 ;

    std::cout << "Concatinated String: " <<finalString << std::endl;
    
    return EXIT_SUCCESS;
}