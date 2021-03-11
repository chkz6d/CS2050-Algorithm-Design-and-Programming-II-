#include "lab7.h"

/*
 * Create a head-inserted linked list.
 */
Node * createLinkedList(int numOfNodes)
{
    srand(time(NULL));
    
    // Declare all variables
    Node * head = NULL;
    Node * newNode = NULL;
    
    for (int i = 0; i < numOfNodes; i++)
    {
        newNode = createNode(rand() % 10 + 1);
        
        if (head == NULL)
        {   // Case 1: if nothing in list, create a node and set head to it
            head = newNode;
        }
        else
        {
            // Case 2: If the list is not empty, insert a new node at the head of the linked list.
            newNode->next = head;
            head = newNode;
        }
    }
    return head;
}

/*
 * Create a node
 */
Node * createNode(int num)
{
    Node * newNode = malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->key = num;
        newNode->next = NULL;
    }
    return newNode;
}

/*
 * Find a Node that contains the key value
 */
Node * findNode(int key,Node * head)
{
    Node * currentNode = head;
    while (currentNode != NULL)
    {
        if (currentNode->key == key)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

/*
 * Display keys of the linked list
 */
void displayLinkedList(Node *head)
{
    Node * currentNode = head;
    while (currentNode != NULL)
    {
        printf(" %d", currentNode->key);
        currentNode = currentNode->next;
    }
    printf("\n");
}

/*
 * Free the linked list
 */
void freeLinkedList(Node *head)
{
    Node * nextNode = head;
    while (head != NULL)
    {
        nextNode = head->next;
        free(head);
        head = nextNode;
    }
}

