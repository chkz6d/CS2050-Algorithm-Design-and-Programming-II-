#include "lab7.h"

int main(void)
{
    // Declare all variables
    int key;
    Node *head, *foundNode;
    
    // Create a 15-Node linked list
    head = createLinkedList(15);
    
    printf("My linked list’s keys:");
    displayLinkedList(head);
    
    printf("Please enter an integer between 1 to 10: ");
    scanf("%d",&key);
    
   
    // Error checking to make sure the input search key is 1 to 10
    while (key < 1 || key > 10)
    {
        printf("ERROR: Number of the search key must be 1 to 10\n\n");
        printf(">> Please input a different integer: ");
        scanf("%d", &key);
    }
    
    foundNode = findNode(key,head);
    
    if (foundNode == NULL)
    {
        printf("The key %d is not found!\n\n", key);
    }
    else
    {
        printf("The key %d is found, and the next node of the key %d Node is located at %p.\n\n", foundNode->key,foundNode->key, foundNode->next);
    }
    
    freeLinkedList(head);
    
    return 0;
}
