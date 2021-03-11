#include "lab11.h"

int main(void)
{
    int const numOfStudents = 5;
    Student students[numOfStudents];
    Stack * myStack = NULL;
    
    for (int i = 0; i < numOfStudents; i++)
    {
        students[i].id = i;
        students[i].age = rand() % 65 + 1;
    }
    
    /*********************************
     * Pushing stack into myStack
     *********************************/
    for (int i = 0; i < numOfStudents; i++)
    {
        myStack = push(myStack, &students[i]);
        printStack(myStack);
    }
    
    /*********************************
     * Popping myStack out
     *********************************/
    for (int i = 0; i < numOfStudents; i++)
    {
        myStack = pop(myStack);
        printStack(myStack);
        
    }
    
    /*********************************
     * Enqueue myQueue
     *********************************/
    Queue* myQ = initQueue();
    for (int i = 0; i < numOfStudents; i++)
    {
        enqueue(myQ, &students[i]);
        printQueue(myQ);
    }
    
    /*********************************
     * Dequeue myQueue
     *********************************/
    for (int i = 0; i < numOfStudents; i++)
    {
        myQ = dequeue(myQ);
        printQueue(myQ);
    }
    
    return 0;
}
