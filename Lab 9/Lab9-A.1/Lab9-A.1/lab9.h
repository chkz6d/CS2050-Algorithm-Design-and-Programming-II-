#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct nodeL {
    int data;
    struct nodeL *next;
} Node;


// Function prototypes
Node * createSortedLinkedList( int numOfNodes );
Node * createNode( int num );
Node * insertOneNewNode( Node *head, Node *newNode );
Node * removeAllKeyNodes( Node *head, int searchKey );
Node * findNode( int searchKey, Node *head );
void displayLinkedList( Node *head );
void freeLinkedList( Node *head );

