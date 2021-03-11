#include "lab5.h"

int main(void)
{
    srand(time(NULL)); // This seeds random integers.
    
    // Declare all variables
    Record *employee;
    double sum = 0.0;
    int size;
    
    printf("\nPlease enter number of employees: ");
    scanf("%d", &size);
    
    // Error check to make sure the size is above 0
    while (size <= 0)
    {
        printf("ERROR: Number of employees must be larger than 0!\n\n");
        printf(">> Please input a different value: ");
        scanf("%d", &size);
    }
    
    employee = createArray(size);
    
    // Checks if malloc is valid
    if(employee == NULL)
    {
        puts("ERROR: malloc returns NULL.");
        return 1; // EXIT_FAILURE
    }
    
    // Adds each employee age and assigns to sum
    for (int i = 0; i < getArraySize(employee); i++)
    {
        sum = employee[i].salary + sum;
    }
    
    printf("The sum of %d employees' salary is $%.2f\n\n", size, sum);
    
    freeArray(employee);
    
    return 0;
}
