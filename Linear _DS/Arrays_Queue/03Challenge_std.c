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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // Added for clear, standard boolean returns

#define MAX_SIZE 5

// Naming conventions: Using PascalCase or snake_case for custom types is standard
typedef struct {
    int data[MAX_SIZE];
    int current_size;  // snake_case is highly preferred in C systems programming
} SafeArray_t;

// Clear, descriptive function prototypes
bool safe_array_append(SafeArray_t *arr, int value);
void safe_array_display(const SafeArray_t *arr); // const ensures read-only access

int main(void)
{
    // Initialize structure cleanly setting all elements and size to 0
    SafeArray_t array = { .data = {0}, .current_size = 0 };
    printf("------------ Safe Array Container --------------\n");

    while (1)
    {
        int option = 0;
        printf("\nOptions: 1) Append\t2) Display\t3) Exit\nSelect Option: ");
        
        // Industry Rule: Always validate the result of input scans to prevent infinite loops
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Error: Invalid menu input. Exiting program safely.\n");
            return EXIT_FAILURE;
        }

        if (option == 1)
        {
            int value = 0;
            printf("Enter value to append: ");
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Error: Invalid integer input.\n");
                return EXIT_FAILURE;
            }
            
            // Using the bool return status cleanly
            if (safe_array_append(&array, value)) {
                printf("Append Success.\n");
            } else {
                printf("Append Unsuccessful: Container is full!\n");
            }
        }
        else if (option == 2)
        {
            // Fixed: Pass by reference so display knows the actual size, avoiding printing garbage
            safe_array_display(&array); 
        }
        else if (option == 3)
        {
            printf("Exiting program cleanly.\n");
            break;
        }
        else {
            printf("Invalid Option! Please select 1, 2, or 3.\n");
            // Clean out stdin buffer in case of extra characters
            while (getchar() != '\n'); 
        }
    }

    return EXIT_SUCCESS;
}

/**
 * @brief Appends an integer to the safe array container if space permits.
 * @param arr Pointer to the SafeArray container.
 * @param value Integer value to store.
 * @return true if append succeeded, false if container is out of space.
 */
bool safe_array_append(SafeArray_t *arr, int value)
{
    // Fail-fast principle: check boundaries first
    if (arr->current_size >= MAX_SIZE) {
        return false; 
    }

    // Assign exactly to current size position, then increment smoothly
    arr->data[arr->current_size] = value;
    arr->current_size++;
    
    return true;
}

/**
 * @brief Displays only the active elements stored inside the container.
 * @param arr Const pointer ensuring tracking variables aren't accidentally overwritten.
 */
void safe_array_display(const SafeArray_t *arr)
{
    printf("------------ Safe-Array Display -----------\n");
    
    if (arr->current_size == 0) {
        printf("[Info] Array is empty.\n");
    } else {
        // Industry Rule: Never display uninitialized array trailing space
        for (int i = 0; i < arr->current_size; ++i)
        {
            printf("Element [%d]: %d\n", i, arr->data[i]);
        }
    }
    
    printf("------------ Safe-Array Display End -----------\n");
}