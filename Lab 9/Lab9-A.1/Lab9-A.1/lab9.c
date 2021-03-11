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
    Node *previousNode = head;
    Node *currentNode = head;
    
    if (head == NULL)
    {   // Case 1: If nothing in list, set head = newNode
        head = newNode;
    }
    else
    {
        // Case 2: If the list is not empty, insert a new node in descending order
        while (1)
        {
            if (currentNode == head &&  newNode->data >= currentNode->data)
            {
                // insert the new node at the head of the linked list
                head = newNode;
                newNode->next = currentNode;
                break;
            }
            else if (currentNode != NULL &&  newNode->data >= currentNode->data)
            {
                // insert the new node in between head and tail nodes
                previousNode->next = newNode;
                newNode->next = currentNode;
                break;
            }
            else if (currentNode == NULL)
            {
                // insert the new node at the tail
                previousNode->next = newNode;
                break;
            }
            
            // Update previousNode and currentNode pointers
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return head;
}


/*
 * Remove all the search key Nodes
 */
Node * removeAllKeyNodes( Node *head, int searchKey )
{
    Node *previousNode = head;
    Node *currentNode = head;

    if (head != NULL)
    {
        while (currentNode != NULL)
        {
            // Delete every node that has the search key data
            if (searchKey == currentNode->data)
            {
                    // Delete the found node at the head
                    if (head == currentNode)
                    {
                        head = head->next;
                        free(currentNode);
                        currentNode = head;
                        previousNode = head;
                    }
                    // Delete the found node in between head and tail
                    else if (currentNode->next != NULL)
                    {
                        previousNode->next = currentNode->next;
                        free(currentNode);
                        currentNode = previousNode->next;
                    }
                    // Delete the found node at the tail
                    else if (currentNode->next == NULL)
                    {
                        previousNode->next = NULL;
                        free(currentNode);
                        break;
                    }
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

