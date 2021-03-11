#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void* createArray(int);
int getArraySize(void*);
void freeArray(void*);

// Define a new data type, Record
typedef struct {
    int EID;
    double salary;
} Record;
