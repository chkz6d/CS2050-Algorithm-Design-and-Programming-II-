#include "lab10.h"

int main(void)
{
    // Declare all variables
    int key;
    Node *dummyNode, *foundNode = NULL;
    
    // Create a 10-Node linked list
    dummyNode = createCircularSortedLinkedList(10);
    
    printf("My linked list’s keys: ");
    displayLinkedList(dummyNode);

    printf("Enter an integer search key from 1 to 10 to delete the nodes: ");
    scanf("%d",&key);

    // Error checking to make sure the input search key is 1 to 10
    while (key < 1 || key > 10)
    {
        printf("ERROR: Number of the search key must be 1 to 10\n\n");
        printf(">> Please input a different integer: ");
        scanf("%d", &key);
    }
    
    foundNode = findNode(key, dummyNode);

    if (foundNode == NULL)
    {
        printf("The key %d is not found!\n", key);
    }
    else // Found the key search and delete all the key search in the linked list
    {
        removeAllKeyNodes(dummyNode, key);

        // Display the final result
        printf("My updated linked list’s keys: ");
        displayLinkedList(dummyNode);
    }

    // Free the linked list
    freeLinkedList(dummyNode);
    
    return 0;
}

