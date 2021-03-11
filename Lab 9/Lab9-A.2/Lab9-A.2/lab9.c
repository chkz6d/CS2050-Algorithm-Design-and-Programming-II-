#include "lab9.h"


/*
 * Create a descending order linked list
 */
Node * createSortedLinkedList( int numOfNodes )
{
    srand(time(NULL));
    
    // Declare all variables
    Node * head = NULL;
    Node * newNode = NULL;
    
    printf("Number of nodes is %d\n", numOfNodes);
    
     // Create a linked list of numOfNodes numbers
    for (int i = 0; i < numOfNodes; i++)
    {
        newNode = createNode(rand() % 10 + 1);
        
        if (newNode != NULL)
        {
            head = insertOneNewNode(head,newNode);
        }
        else
        {
            printf("Error: Memory could not be allocated for a linked list of %d nodes.\n", numOfNodes);
            freeLinkedList(head); // Free the nodes that aready be created.
            return NULL;
        }
    }
    return head;
}


/*
 * Create a node
 */
Node * createNode( int num )
{
    Node * newNode = malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->data = num;
        newNode->next = NULL;
    }
    return newNode;
}


/*
 * Insert a new Node into the linked list
 */
Node * insertOneNewNode( Node *head, Node *newNode )
{
    if (newNode != NULL)
    {
        Node* currentNode = head;
        
        // If head is NULL, or the head's data is less than new node insert.
        if (head == NULL || head->data <= newNode->data)
        {
            newNode->next = head;
            return newNode;
        }
        
        // Loop until the end of the linked list or until the new node is less than the current node it passes
        while (currentNode->next != NULL && currentNode->next->data > newNode->data)
        {
            currentNode = currentNode->next;
        }
        
        // Insert the new node into the linked list
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    else
    {
        printf("ERROR: No new node to be inserted.");
    }
    return head;
}


/*
 * Remove all the search key Nodes
 */
Node * removeAllKeyNodes( Node *head, int searchKey )
{
    // Base case
    if (head == NULL)
    {
        return NULL;
    }
    else if (searchKey == head->data)
    {
        Node *nextNode = head->next;
        free(head);
        return  removeAllKeyNodes(nextNode, searchKey);
    }
    head->next = removeAllKeyNodes(head->next,searchKey);
    return head;
}


/*
 * Find a Node that contains the key value
 */
Node * findNode( int searchKey, Node * head )
{
    Node * currentNode = head;
    if (head != NULL)
    {
        while (currentNode != NULL)
        {
            if (currentNode->data == searchKey)
            {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
    }
    else
    {
        printf("The linked list is empty, nothing to find.\n");
    }
    return NULL;  // Return NULL if there is no Node found.
}


/*
 * Display keys of the linked list
 */
void displayLinkedList( Node *head )
{
    Node * currentNode = head;
    if (head != NULL)
    {
        while (currentNode != NULL)
        {
            printf("%d", currentNode->data);
            if (currentNode->next != NULL)
            {
                printf(", ");
            }
            currentNode = currentNode->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nThe linked list is empty, nothing to be printed.\n");
    }
}


/*
 * Free the linked list
 */
void freeLinkedList( Node *head )
{
    Node * nextNode = head;
    
    // If nothing in the input liked list
    if (head == NULL)
    {
        printf("The linked list is empty, nothing to be freed.\n\n");
        return;
    }
    
    while (head != NULL)
    {
        nextNode = head->next;
        free(head);
        head = nextNode;
    }
    printf("The linked list has been freed.\n\n");
}

