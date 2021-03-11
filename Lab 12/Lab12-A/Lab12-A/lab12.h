#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1001

typedef struct {
    int id;
    int age;
    int department;
    float salary;
    char name[20];
} Employee;


//--------------------------------------------------------------------------------//
//------------------------------ Function prototypes -----------------------------//
//--------------------------------------------------------------------------------//
Employee ** readFile(void);
void * binarySearch(void * employeePtrs[], int first, int last, void * query);
int compare(void * obj1, void * obj2);
void freeArray(void * employeePtrs[]);

