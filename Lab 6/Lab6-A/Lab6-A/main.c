#include "lab6.h"

int main(void)
{
    // Declare all variables
    Student * students;
    
    students = createArray();
    
    if (students != NULL)
    {
        // Print out the result
        printf("The average GPA of %d students is %.2f.\n\n", getNumberOfStudents(students), getAverageOfGPA(students));
        freeArray(students);
    }
    else
    {
        printf("ERROR: Fail to create a Student array.\n");
        return -1; //this only happens if the file cant be opened
    }
    return 0;
}
