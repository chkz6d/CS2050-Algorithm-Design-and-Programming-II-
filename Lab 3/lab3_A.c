
#include <stdlib.h>
#include <stdio.h>

// Function Prototype
int countDuplicateValue(int*, int, int);

int main(void)
{
    int i, size, choice, kCount;
    int* array;
    FILE *fPtr = fopen("data.txt", "r");
    
    if (fPtr == NULL)
    {
        // Gives error message if file cannot be opened
        puts("Error: file could not be opened.");
    }
    else
    {
        // Read the size in from first line of data.txt
        fscanf(fPtr, "%d", &size);
        
        // Allocate space equals to the size times sizeof(int)
        array = malloc(size * sizeof(int));
        
        // Read element data from data.txt into the array
        for(i = 0; i < size; i++)
        {
            fscanf(fPtr, "%d", &array[i]);
        }
        
        // Prompt
        printf("Choose a number between 1 and 10: ");
        scanf("%d", &choice);
        
        // Call the countDuplicate()
        kCount = countDuplicateValue(array, size, choice);
        
        // Display the result
        printf("The number %d appears %d time(s).\n", choice, kCount);
        
        // Close the file
        fclose(fPtr);
    
        // Free the memory
        free(array);
        array = NULL;
    }
    
    /* The return value of the main function is considered the "Exit Status" of the application.
     * On most operating systems returning 0 is a success status like saying "The program worked fine".
     */
    return 0;
}


/*
 * Function:  countDuplicateValue
 * --------------------------------
 * Purpose: To count number of times a user-selected number appears in the array
 *
 * Parameters:
 *   array: integer array
 *   arraySize: size of the integer array
 *   k: a user-selected integer
 *
 * Returns:
 *  An integer: the number of times the chosen number appears in the array
 */
int countDuplicateValue(int *array, int arraySize, int k)
{
    int j;
    int count = 0;
    
    for (j = 0; j < arraySize; j++)
    {
        if(array[j] == k)
        {
            // Increment the count variable if the user-selected integer appears in the array
            count += 1;
        }
    }
    return count;  // Return count
}

