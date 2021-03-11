#include "lab5.h"

/*
 * Function:  createArray
 * --------------------------------
 * Purpose: To create an array and initialize the array
 * Parameter:
 *      arraySize: An integer that greater than 0
 * Returns:
 *      A void pointer: A pointer to the array
 */
void *createArray(int arraySize)
{
    // Initializes array
    int *array = NULL;
    
    // Allows us to dynamically allocate array depending on users input
    array = malloc( sizeof(int) + (arraySize * sizeof(Record)) );
    
    // Error check for malloc()
    // Malloc will return NULL when the kernel/system lib are certain that no memory can be allocated.
    if(array == NULL)
    {
        return NULL;
    }
    
    // Initialize the size of the array
    array[0] = arraySize;
    array++;
    
    // Allocate each Record structure with employee ID and age
    for(int i = 0; i < arraySize; i++)
    {
        ((Record *)array + i) -> EID = i;
        ((Record *)array + i) -> salary = rand() % 479000 + 42000;
    }
    return array;
}

/*
 * Function: getArraySize
 * --------------------------------
 * Purpose: To find the size of a given array when array size is hidden in array
 * Parameter:
 *      array: An integer pointer to the allocated memory
 * Returns:
 *      An integer: An array size
 */
int getArraySize(void *array)
{
    return *((int *)array - 1);
}

/*
 * Function: freeArray
 * --------------------------------
 * Purpose: To free an allocated memory
 * Parameter:
 *     array: An integer pointer to the allocated memory
 * Returns: None
 */
void freeArray(void* array)
{
    free( (int*)array - 1 );
}
