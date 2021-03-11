#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Student Struct
typedef struct {
    int id;
    float GPA;
} Student;

// Function Prototypes
Student * createArray(void);
float getAverageOfGPA(Student *);
int getNumberOfStudents(Student *);
void freeArray(Student*);
