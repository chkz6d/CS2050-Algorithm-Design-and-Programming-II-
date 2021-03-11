#include "lab14.h"

int main(void)
{
    // Declare variables
    Employee* empArray = NULL;
    
    // Read in data and initialize employee array
    empArray = readFile();
    
    if (empArray == NULL)
    {
        return -1;
    }
    
    printf("Given array is\n");
    printEmployees(empArray, ARRAY_SIZE);
    
    quickSort(empArray, 0, ARRAY_SIZE - 1);
    
    printf("Sorted array is\n");
    printEmployees(empArray, ARRAY_SIZE);
    
    // Free all malloc
    freeArray(empArray);

    return 0;
}

