#include "stack.h"

Stack *createStack() {
    Stack *newStack = (Stack *) malloc(sizeof(Node));
    newStack->top = 0;
    newStack->list = NULL;
    return newStack;
}

void push(Stack *myStack, int value) {
    if(myStack) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->value = value;
        newNode->ptrNextNode = myStack->list;
        myStack->list = newNode;
        myStack->top++;
    }
}

int pop(Stack *myStack) {
    if(myStack) {
        if(myStack->top) {
            int returnValue;
            Node *aux = myStack->list;
            returnValue = aux->value;
            myStack->list = myStack->list->ptrNextNode;
            myStack->top--;
            free(aux);
            return returnValue;
        }
    }
}

int top(Stack *myStack) {
    if(myStack) {
        if(myStack->top) {
            return myStack->list->value;   
        }
    }
}