/*
Challenge 2: The String Concatenation Engine (Intermediate)
Objective: Avoid buffer overflows by calculating memory requirements dynamically at runtime.

Task: Create a function with the signature char* dynamic_concat(const char* str1, const char* str2).

Twist: Inside the function, calculate the exact length of both strings, allocate a precise amount of memory on the heap
     to store the combined string (plus the null-terminator \0), concatenate them, and return the pointer. In your main function,
     call this engine, print the result, and ensure no memory leaks occur.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dynamic_concat(const char *str1, const char *str2, const size_t size);

int main()
{
     printf("--------------- String Concatination Engine ----------------------\n\n");
     // Initializing pointers to hold Dynamically allocated memory
     char* arr;
     char* brr;
     char* concatedString;
     size_t arrSize, brrSize;
     char temp[100] = "\0";

//Requesting to user for 1st string
     printf("Enter the string1: ");
     if (fgets(temp,sizeof(temp),stdin)==NULL)
     {
          fprintf(stderr, "Error: String is not Accepted");
          return EXIT_FAILURE;
     }

     arrSize = strlen(temp);
     printf("Size of String: %d\n",arrSize); 

     //Removing the Tailing \n
     if(arrSize > 0 && temp[(arrSize-1)] == '\n')
     {
          temp[arrSize-1] = '\0';
          arrSize --;
     }

     arr = malloc((arrSize + 1) * sizeof(char));
     if(arr == NULL)
     {
          fprintf(stderr,"Error: Memory is nor allocated\n");
          return EXIT_FAILURE;
     }
     printf("Address of str1(heap): %p\n", (void*)arr);

     //Copy the string to heap memory
     strcpy(arr,temp);

     printf("Entered string1: %s\n",arr);


// Taking Second String from User 
     printf("Enter the string2: ");
     if (fgets(temp,sizeof(temp),stdin)==NULL)
     {
          fprintf(stderr, "Error: String is not Accepted");
          return EXIT_FAILURE;
     }

     brrSize = strlen(temp);
     printf("Size of String: %p\n",brrSize); 

     //Removing the Tailing \n
     if(brrSize > 0 && temp[(brrSize-1)] == '\n')
     {
          temp[brrSize-1] = '\0';
          brrSize --;
     }

     brr = malloc((brrSize + 1) * sizeof(char));
     if(brr == NULL)
     {
          fprintf(stderr,"Error: Memory is nor allocated\n");
          return EXIT_FAILURE;
     }
     printf("Address of str2(heap): %d\n", (void*)brr);

     //Copy the string to heap memory
     strcpy(brr,temp);

     printf("Entered string2: %s\n",brr);
     
//dynamic_concat(arr, brr);
     size_t finalSize = arrSize + brrSize;
     concatedString = dynamic_concat(arr, brr,finalSize);
     printf("Final Concatinate String: %s \n",concatedString);

//Free the heap memory 
     free(arr);
     free(brr);
     free(concatedString);

     arr=NULL;
     brr=NULL;
     concatedString = NULL;
     return 0;
}

char* dynamic_concat(const char *str1, const char *str2,const size_t size)
{
     char* finalStr = malloc(size * sizeof(char));
     size_t str_1 = strlen(str1);
     size_t str_2 = strlen(str2);

     for(int i=0; i<str_1; ++i)
     {
          finalStr[i] = str1[i];
     }
     int count=0;
     for(int i=(str_1-1);i<size;++i)
     {
          finalStr[i] = str2[count];
          ++count;
     }

     return finalStr;
}