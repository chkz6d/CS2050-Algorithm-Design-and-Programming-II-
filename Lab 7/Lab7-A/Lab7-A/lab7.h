#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _node {
    int key;
    struct _node *next;
} Node;

// Function prototypes
Node * createLinkedList(int numOfNodes);
Node * createNode(int num);
Node * findNode(int key, Node * head);
void displayLinkedList(Node *head);
void freeLinkedList(Node *head);
