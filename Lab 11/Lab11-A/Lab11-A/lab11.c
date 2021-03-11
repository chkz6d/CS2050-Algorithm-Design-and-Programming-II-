#include "lab11.h"


/***************************************************************************
 * Push an item to the top of a stack
 ***************************************************************************/
Stack * push(Stack *top, void *item)
{
    if (item != NULL)
    {
        Stack * newStack = malloc(sizeof(Stack));
        newStack->item = item;
        newStack->next = top;
        top = newStack;
    }
    else
    {
        printf("\nNo item to be pushed.\n");
    }
    return top;
}


/***************************************************************************
 * Removes the element from the top of a stack.
 ***************************************************************************/
Stack * pop(Stack *top)
{
    Stack * nextTop = NULL;
    if (top != NULL)
    {
        nextTop = top->next;
        free(top);
        top = nextTop;
    }
    else
    {
        printf("\nThe stack is empty, nothing to be removed.\n");
    }
    return top;
}


/***************************************************************************
 * Display all students' ages in the stack
 ***************************************************************************/
void printStack(Stack *myStack)
{
    if (myStack != NULL)
    {
        Stack * top = myStack;
        printf("Stack is ");
        while (top != NULL)
        {
            printf("%d ", ((Student *)(top->item))->age);
            top = top->next;
        }
        printf("\n");
    }
    else
    {
        printf("The stack is empty, nothing to be printed.\n\n");
    }
}


/***************************************************************************
 * Establishes my Queue
 **************************************************************************/
Queue * initQueue(void)
{
    Queue* myQ = malloc(sizeof(Queue));
    myQ->front = myQ->rear = NULL;
    return myQ;
}


/***************************************************************************
 * Enqueues an item to the rear of a queue.
 ***************************************************************************/
void enqueue (Queue *myQ, void *item)
{
    if (item != NULL)
    {
        QueueNode * newNode = createQueueNode(item);
        
        // Case 1: myQ is an empty queue.
        if (myQ->front == NULL || myQ->rear == NULL)
        {
            myQ->front = myQ->rear = newNode;
        }
        // Case 2: myQ is not an empty queue.
        else
        {
            myQ->rear->next = newNode;  // enqueue my new node
            myQ->rear = newNode;        // update my rear pointer
        }
    }
    else
    {
        printf("\nNo item to be enqueued.\n");
    }
}


/***************************************************************************
 * Create an queue node
 ***************************************************************************/
QueueNode * createQueueNode(void * item)
{
    QueueNode * newNode = malloc(sizeof(QueueNode));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

/***************************************************************************
 * Removes the element from the front of a queue.
 ***************************************************************************/
Queue * dequeue (Queue *myQ)
{
    if (myQ != NULL)
    {
        QueueNode * frontNode = myQ->front;
        
        if (frontNode != NULL)
        {
            myQ->front = frontNode->next;
            free(frontNode);
            frontNode = myQ->front;
        }
        
        // Once we free the front node, we also need to check if our queue is empty or not.
        // If it is empty, we just need to free myQ struct and set myQ to NULL.
        if (frontNode == NULL)
        {
            free(myQ);
            myQ = NULL;
        }
    }
    else
    {
        printf("\nThe queue is empty, nothing to be dequeued.\n");
    }
    return myQ;
}


/***************************************************************************
 * Display all students' ages in the queue
 ***************************************************************************/
void printQueue(Queue *myQ)
{
    if (myQ != NULL && myQ->front != NULL)
    {
        // Get the front of the queue
        QueueNode * front = myQ->front;
        
        printf("Queue is ");
        while (front != NULL)
        {
            printf("%d ", ((Student *)(front->item))->age);
            front = front->next;
        }
        printf("\n");
    }
    else
    {
        printf("The queue is empty, nothing to be printed.\n\n");
    }
}



