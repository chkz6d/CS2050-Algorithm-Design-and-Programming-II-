#include "lab6.h"

/*
 * Function:  createArray
 * --------------------------------
 * Purpose: To create a Student array and initialize the array
 * Parameter: None
 * Returns:
 *      A Student pointer: A pointer to the allocated Student array
 */
Student * createArray(void)
{
    // Declare all variables
    int numOfStudents;
    Student* studentArray;
    FILE *fPtr; // File pointer
    
    // Open the student.csv file
    fPtr = fopen("student.csv", "r");
    
    /*
     * Error checking: in case of the file might not exist or some permission error occurred while accessing a file such
     * as "Read-Only" or "Write-Protected", so in those cases fopen will return 0 (a NULL pointer)
     * On success it will return a file pointer as a handler.
     */
    if (fPtr != NULL)
    {
        // Read the first line of the student.cvs file to get the number of students
        fscanf(fPtr, "%d", &numOfStudents);
        
        // Allocate space for the Student array
        studentArray = malloc((sizeof(Student)*numOfStudents) + sizeof(int));
        
        // The malloc() will return NULL when the system lib are certain that no memory can be allocated.
        if (studentArray != NULL)
        {
            // Assign the first 4 bytes with the numOfStudents variable
            *(int*)studentArray = numOfStudents;
            
            // Shift studentArray up 4 bytes
            studentArray = (Student *)( (int*)studentArray + 1 );
        
            // Read in id and GPA of each student
            for (int i = 0; i < numOfStudents; i++)
            {
                fscanf(fPtr, "%d, %f", &studentArray[i].id, &studentArray[i].GPA);
                
                // Error checking if we're at end of file before finishing read
                if (feof(fPtr) && i != numOfStudents-1)
                {
                    printf("ERROR in lab6.c: Hit the end of file before expected.\n");
                    return NULL;
                }
            }
            
            // Close the file
            fclose(fPtr);
            return studentArray;
        }
    }
    printf("ERROR: In createArray() specified file not found or is corrupted.\n");
    return NULL;
}

/*
 * Function: getAverageOfGPA
 * --------------------------------
 * Purpose: To computer average of GPA
 * Parameter:
 *      array: A Student pointer to the allocated Student array
 * Returns:
 *      A float: An average of GPA
 */
float getAverageOfGPA(Student *students)
{
    float totalGPA = 0.0;
    int numOfStudents;
    
    if (students != NULL)
    {
        numOfStudents = getNumberOfStudents(students);
    
        // Sum up all GPA
        for (int i = 0; i < numOfStudents; i++)
        {
            totalGPA += students[i].GPA;
        }
        return totalGPA / numOfStudents;
    }
    return 0;
}

/*
 * Function: getNumberOfStudents
 * --------------------------------
 * Purpose: To find the size of a given Student array when the array size is hidden in array
 * Parameter:
 *      array: A Student pointer to the allocated Student array
 * Returns:
 *      An integer: An array size
 */
int getNumberOfStudents(Student *students)
{
    if (students != NULL)
    {
        return ((int*)students)[-1];
    }
    return 0; // if the students  = NULL
}

/*
 * Function: freeArray
 * --------------------------------
 * Purpose: To free an allocated memory
 * Parameter:
 *     array: A Student pointer to the allocated Student array
 * Returns: None
 */
void freeArray(Student *students)
{
     if (students != NULL)
     {
         free( (int*)students-1 );
         students = NULL;
     }
}
    
