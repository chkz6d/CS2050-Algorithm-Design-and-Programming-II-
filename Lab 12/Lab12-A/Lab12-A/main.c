#include "lab12.h"

int main(void)
{
    // Declare variables
    Employee * searchedEmployee = NULL;
    int first = 0;
    int last = ARRAY_SIZE-1;
    int query;
    
    // Read in data and initialize employee array
    Employee** employeePtrs = readFile();
    
    if (employeePtrs == NULL)
    {
        return -1;
    }
    
    // Prompt for searching an employee
    printf("Please enter an employee ID to search the personal info: ");
    scanf("%d", &query);
    
    // Search for the entered ID
    searchedEmployee = binarySearch((void **)employeePtrs, first, last, (void *)(&query));
    
    // Display the result from the binary search
    if (searchedEmployee == NULL)
    {
        printf("Employee ID %d doesn't exist!!\n", query);
    }
    else
    {
        // Display the employee info
        printf("Employee ID : %d\nName        : %s\nAge         : %d\nDepartment  : %d\nSalary      : $%.2f\n",
               searchedEmployee->id,
               searchedEmployee->name,
               searchedEmployee->age,
               searchedEmployee->department,
               searchedEmployee->salary);
    }
    
    // Free all malloc
    freeArray((void **)employeePtrs);
    
    return 0;
}

