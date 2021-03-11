#include "lab12.h"

/*
 * This function reads data from the employeeInfo.csv file, creates an array of Employee pointers, and point to Employee structs that containing their information.
 */
Employee ** readFile(void)
{
    FILE *fp;
    
    // Open the employeeInfo.csv file to read
    fp = fopen("employeeInfo.csv", "r");
    
    if (fp == NULL)
    {
        printf("Cannot find file\n");
        return NULL;
    }
    
    // Create an array of Employee pointers
    Employee** employeePtrs = malloc( sizeof(Employee*) * ARRAY_SIZE);
    
    if (employeePtrs == NULL)
    {
        printf("Malloc failed\n");
        return NULL;
    }
    
    /*
     * In this for-loop, it reads the data from the file and initialize Employee structs
     */
    for (int i = 0 ; i < ARRAY_SIZE && !feof(fp) ; i++)
    {
        // employeePtrs[i] points to newly created Employee struct
        employeePtrs[i] = malloc(sizeof(Employee));
        
        if (employeePtrs[i] == NULL)
        {
            printf("Individual malloc failed\n");
            return NULL;
        }
        
        // Read the data from the file and initialize each member of the Employee struct
        fscanf(fp, "%d, %d, %d, %f, %s",
               &(employeePtrs[i]->id),
               &(employeePtrs[i]->age),
               &(employeePtrs[i]->department),
               &(employeePtrs[i]->salary),
               employeePtrs[i]->name);
    }
    
    // Close the file
    fclose(fp);
    
    return employeePtrs; // Return an array of Employee pointers
}


/*
 * Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array.
 * If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
 * Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.
 */
void * binarySearch(void * employeePtrs[], int first, int last, void * query)
{
    int mid, outcome;
    
    if (first <= last)
    {
        // Find the middle index
        mid = (first + last) / 2;
        
        // Compare between query and the middle element of the array
        outcome = compare(query, employeePtrs[mid]);
        
        // If the employee is found, return the found employee struct back to the main
        if (outcome == 0)
        {
            return employeePtrs[mid];
        }
        else if (outcome < 0)
        {
            // Narrow the interval to the lower half
            return binarySearch(employeePtrs, first, mid-1, query);
        }
        else
        {
            // Narrow the interval to the upper half
            return binarySearch(employeePtrs, mid+1, last, query);
        }
    }
    return NULL;
}


/*
 * Compare between two IDs from two different Employee objects where the return value is negative if obj1's id is less than obj2's id,
 * zero if they’re equal, and positive if obj1's id is greater than obj2's id.
 */
int compare(void * obj1, void * obj2)
{
    return ((Employee *)obj1)->id - *((int *)obj2);
}


/*
 * Free the malloc memory
 */
void freeArray(void * employeePtrs[])
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        // Free each Employee struct
        free(employeePtrs[i]);
    }
    
    // Free the array of employee pointers
    free(employeePtrs);
}



