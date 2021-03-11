#include <stdlib.h>
#include <stdio.h>


// Function Prototype
void sumArray(int* sum, int inputArray[], int size);


int main(void)
{
    // Declare and initialize a 5-element array called 'array' of type integer with 1,2,3,4,5
    int size = 5;
    int inputArray[5] = {1,2,3,4,5};
    
    // Initialize sum to zero
    int sum = 0;
    
    // Call the sumArray function
    sumArray(&sum,inputArray,size);
    
    // Print out the result
    printf("\nThe sum of the arrary is %d\n\n",sum);

    return 0;
}


/*
 * Function:  sumArray
 * --------------------
 * Purpose: To get the sum of all elements in array
 *
 * sum: integer pointer
 * inputArray: integer array
 * size: array size
 *
 *  returns: None or nothing
 */
void sumArray(int* sum, int inputArray[], int size)
{
    int i = 0;
    for(i=0; i<size;i++)
    {
        *sum += inputArray[i];
        
    }
}
