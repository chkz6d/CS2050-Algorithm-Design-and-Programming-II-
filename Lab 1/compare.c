#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


// Function Prototype
void compare(int input1, int input2, int * output);

int main(void)
{
    /*
     * Variable declaration
     */
    int integer1 = 1;
    int integer2 = 2;
    int result;
    int * resultPtr; // pointer to type int
    
    printf("First integer:  %d\n",integer1);
    printf("Second integer: %d\n",integer2);
    
    // resultPtr points to the result
    resultPtr = &result;
    
    // Compare two integer inputs by calling your compare function
    compare(integer1, integer2, resultPtr);
    
    // Dereferencing the resultPtr pointer into the result
    result = *resultPtr;
      
    // Print out the output difference of a and b
    printf("The difference between the integers is %d\n", result);
    
    return 0;
}


/*
 * Function:  compare
 * --------------------
 * Purpose: To compare two inputs and modify the result variable by using its address
 *
 * input1: integer input
 * input2: the other integer input
 * output: integer pointer
 *
 *  returns: None or nothing
 */
void compare(int input1, int input2, int * output)
{
    if(input1 <= input2)
    {
        *output = input1 - input2;
    }
    else
    {
        *output = input2 - input1;
    }
}
