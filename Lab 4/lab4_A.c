#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int* createIntArray(int n);
int getArraySize(int* array);
void displayArray(int* array); // This is optional.
void freeArray(int* array);

int main(void)
{
    // Declare all variables
    int arraySize;
    int* array;
    
    printf("Please pick an array size: ");
    scanf("%d", &arraySize);
    
    // Error check to make sure the size is above 0
    while (arraySize <= 0)
    {
        printf("ERROR: Number must be larger than 0! Please input a different value: ");
        scanf("%d", &arraySize);
    }
    
    // Call createArray()
    array = createIntArray(arraySize);
    
    printf("Array: ");
    displayArray(array);
    
    // Print the max value result
    printf("Max value in the array: %d\n", array[-1]);
    
    freeArray(array);
    
    /* NOTE: The return value of the main function is considered the "Exit Status" of the application.
     * On most operating systems returning 0 is a success status like saying "The program worked fine".
     */
    return 0;
}


/*
 * Function:  createIntArray
 * --------------------------------
 * Purpose: To create array for user with predifined size; store the max number into newArray[-1] and the array size into newArray[-2]
 * Parameter:
 *      arraySize: An integer that greater than 0
 *
 * Returns:
 *      An integer pointer: A pointer to the array with size stores at newArray[-1] and max stores at newArray[-2]
 */
int* createIntArray(int arraySize)
{
    srand(time(NULL)); // NOTE: This seeds random with the current time so we get a random number when we call rand.
    int* newArray;
    int maxValue = 0;
    
    // Allocate space for an array plus 2 hidden integers
    newArray = (int *)malloc(sizeof(int) * (arraySize + 2));
    
    // Update newArray pointer over two spaces to the right (to hide two elements)
    newArray += 2;
    
    // Assign the array size to the -2 space in the array
    newArray[-2] = arraySize;
    
    // Assign a random number between 1 and 20 to each element and keep track of max value of the array
    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = (rand() % 20) + 1;
        
        // If the current element is larger than max, then make max equal to the current element.
        if (newArray[i] > maxValue)
        {
            maxValue = newArray[i];
        }
    }
    
    // Assign the max value into the newly created array
    newArray[-1] = maxValue;
    
    return newArray;
}

/*
 * Function: getArraySize
 * --------------------------------
 * Purpose: To find the size of a given array when array size is hidden in array[-2]
 * Parameter:
 *      array: An integer pointer to the allocated memory
 *
 * Returns:
 *      An integer: An array size
 */
int getArraySize(int* array)
{
    return array[-2];
}

/*
 * Function: displayArray
 * --------------------------------
 * Purpose: To display an array
 * Parameter:
 *   array: An integer pointer to the allocated memory
 *
 * Returns: None
 */
void displayArray(int* array)
{
    int size = getArraySize(array);
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

/*
 * Function: freeArray
 * --------------------------------
 * Purpose: To free an allocated memory
 * Parameter:
 *      array: An integer pointer to the allocated memory
 *
 * Returns: None
 */
void freeArray(int* array)
{
    // Shift the array back over
    array -= 2;
    free(array);
    array = NULL;
}


