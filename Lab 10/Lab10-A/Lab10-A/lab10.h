#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct nodeL {
    int data;
    struct nodeL *next;
} Node;


// Function prototypes
Node * createCircularSortedLinkedList( int numOfNodes );
Node * createNode( int num );
void insertOneNewNode( Node *head, Node *newNode );
void removeAllKeyNodes( Node *head, int searchKey );
Node * findNode( int searchKey, Node *head );
void displayLinkedList( Node *head );
void freeLinkedList( Node *head );
