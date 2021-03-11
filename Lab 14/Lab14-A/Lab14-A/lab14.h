#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15

typedef struct {
    int id;
    int age;
    float salary;
} Employee;


//--------------------------------------------------------------------------------//
//------------------------------ Function prototypes -----------------------------//
//--------------------------------------------------------------------------------//
void* readFile(void);
void printEmployees(void * empArray, int size);
void swap(void* a, void* b);
int partition (void * empArray, int low, int high);
void quickSort(void * empArray, int low, int high);
void freeArray(void * empArray);

