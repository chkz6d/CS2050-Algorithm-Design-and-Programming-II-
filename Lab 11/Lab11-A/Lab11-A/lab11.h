#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int id;
    int age;  // A random number from 1 to 65
} Student;

typedef struct stackNode {
    void * item;
    struct stackNode * next;
} Stack;

typedef struct queueNode {
    void * item;
    struct queueNode * next;
} QueueNode;

typedef struct {
    QueueNode * front;
    QueueNode * rear;
} Queue;


//----------------------------------------//
//--------- Function prototypes ----------//
//----------------------------------------//
Stack * push(Stack *top, void *item);
Stack * pop(Stack *top);
void printStack(Stack *myStack);
//----------------------------------------//
Queue * initQueue(void);
void enqueue (Queue *myQ, void *item);
QueueNode * createQueueNode(void * item);
Queue * dequeue (Queue *myQ);
void printQueue(Queue *myQ);
//----------------------------------------//

