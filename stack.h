#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int value;
    struct tNode *ptrNextNode;
} Node;

typedef struct {
    int top;
    Node *list;
} Stack;

Stack *createStack();

void push(Stack *myStack, int value);

int pop(Stack *myStack);

int top(Stack *myStack);