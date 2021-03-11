#include "lab10.h"


/*
 * Create a descending order linked list
 */
Node * createCircularSortedLinkedList( int numOfNodes )
{
    srand(time(NULL));
    
    // Declare all variables
    Node * dummyNode = NULL;
    Node * newNode = NULL;
    
    printf("Number of nodes is %d\n", numOfNodes);
    
    // Create dummy node
    dummyNode = createNode(0);
    dummyNode->next = dummyNode;
    
     // Create a linked list of numOfNodes numbers
    for (int i = 0; i < numOfNodes; i++)
    {
        newNode = createNode(rand() % 10 + 1);
        
        if (newNode != NULL)
        {
            insertOneNewNode(dummyNode,newNode);
        }
        else
        {
            printf("Error: Memory could not be allocated for a linked list of %d nodes.\n", numOfNodes);
                freeLinkedList(dummyNode); // Free the nodes that aready be created.
            return NULL;
        }
    }
    return dummyNode;
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
void insertOneNewNode( Node *dummyNode, Node *newNode )
{
    if (dummyNode != NULL)
    {
        Node *previousNode = dummyNode;
        Node *currentNode = dummyNode->next;
        
        while (currentNode != dummyNode)
        {
            // Insert in between the dummy node and the tail
            if (newNode->data >= currentNode->data)
            {
                previousNode->next = newNode;
                newNode->next = currentNode;
                return;
            }
            
            // Update previousNode and currentNode pointers
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        
        // Insert at the tail
        previousNode->next = newNode;
        newNode->next = dummyNode; // newNode->next point to the dummyNode/currentNode
    }
    else
    {
        printf("Error: Nothing to be insert!!\n");
    }
}


/*
 * Remove all the search key Nodes
 */
void removeAllKeyNodes( Node *dummyNode, int searchKey )
{
    Node *previousNode = dummyNode;
    Node *currentNode = dummyNode->next;

    if (dummyNode != NULL)
    {
        while (currentNode != dummyNode)
        {
            // Delete every node that has the search key data
            if (searchKey == currentNode->data)
            {
                // Delete the found node
                previousNode->next = currentNode->next;
                free(currentNode);
                currentNode = previousNode->next;
            }
            else
            {
                // Update previousNode and currentNode pointers
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        } // End of the while-loop
    }
    else
    {
        printf("The linked list is empty, nothing to be found.\n");
    }
}


/*
 * Find a Node that contains the key value
 */
Node * findNode( int searchKey, Node * dummyNode )
{
    if (dummyNode != NULL)
    {
        Node * currentNode = dummyNode->next;
        if (currentNode != NULL)
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
void displayLinkedList( Node *dummyNode )
{
    if (dummyNode != NULL)
    {
        Node * currentNode = dummyNode->next;
        if (currentNode != NULL)
        {
            while (currentNode != dummyNode)
            {
                printf("%d", currentNode->data);
                if (currentNode->next != dummyNode)
                {
                    printf(", ");
                }
                currentNode = currentNode->next;
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nThe linked list is empty, nothing to be printed.\n");
    }
}


/*
 * Free the linked list
 */
void freeLinkedList( Node *dummyNode )
{
    if (dummyNode == NULL)
    {
        printf("The linked list is empty, nothing to be freed.\n\n");
        return;
    }

    Node *nextNode, *currentNode = dummyNode->next;
    while (currentNode != dummyNode)
    {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    // Delete the dummy node
    free(dummyNode);
    printf("The linked list has been freed.\n\n");
}

