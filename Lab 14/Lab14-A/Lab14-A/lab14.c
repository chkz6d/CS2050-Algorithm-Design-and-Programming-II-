#include "lab14.h"


/*
 * This function reads data from the employeeInfo.csv file, creates an array of Employee pointers,
 * and point to Employee structs that containing their information.
 */
void* readFile(void)
{
    FILE *fp;
    
    // Open the employeeInfo.csv file to read
    fp = fopen("employeeInfo.csv", "r");
    
    if (fp == NULL)
    {
        printf("Cannot find file\n");
        return NULL;
    }
    
    // Create an array of Employees
    Employee* empArray = malloc( sizeof(Employee) * ARRAY_SIZE);
    
    if (empArray == NULL)
    {
        printf("Malloc failed\n");
        return NULL;
    }
    
    /*
     * In this for-loop, it reads the data from the file and initialize Employee structs
     */
    for (int i = 0 ; i < ARRAY_SIZE && !feof(fp) ; i++)
    {
        // Read the data from the file and initialize each member of the Employee struct
        fscanf(fp, "%d, %d, %f",
               &empArray[i].id,
               &empArray[i].age,
               &empArray[i].salary);
    }
    
    // Close the file
    fclose(fp);
    
    return empArray; // Return an array of Employee pointers
}

/*
 * A utility function to swap two elements.
 */
void swap(void* a, void* b)
{
    Employee t = *(Employee*)a;
    *(Employee*)a = *(Employee*)b;
    *(Employee*)b = t;
}

/*
 * This function takes last element as pivot, places the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
 */
int partition (void * empArray, int low, int high)
{
    srand(time(0));
    
    int random = low + rand() % (high - low + 1);
    swap(&((Employee*)empArray)[high], &((Employee*)empArray)[random]);
    
    int pivot = ((Employee*)empArray)[high].id; // pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (((Employee*)empArray)[j].id <= pivot)
        {
            i++; // increment index of smaller element
            swap(&((Employee*)empArray)[i], &((Employee*)empArray)[j]);
        }
    }
    swap(&((Employee*)empArray)[i + 1], &((Employee*)empArray)[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 * empArray[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
void quickSort(void * empArray, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(empArray, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(empArray, low, pi - 1);
        quickSort(empArray, pi + 1, high);
    }
}


/*
 * Display an array
 */
void printEmployees(void * empArray, int size)
{
    // Display the sorted results
    for (int i = 0; i < size; i++)
    {
        // Display the employee info
        printf("\tEmployee ID : %d;\tAge : %d;\tSalary : $%.2f\n",
               ((Employee*)empArray+i)->id,
               ((Employee*)empArray+i)->age,
               ((Employee*)empArray+i)->salary);
    }
    printf("\t===================================================\n\n");
}


/*
 * Free the malloc memory
 */
void freeArray(void * empArray)
{
    // Free the array of employee pointer
    free(empArray);
}

