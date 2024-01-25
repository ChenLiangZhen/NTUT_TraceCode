//
// Created by Light Chen on 2024/1/2.
//

#ifndef TRACECODE_STACK_H
#define TRACECODE_STACK_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct stack_node {
    int data;
    struct stack_node *next;
} NODE;

int showTop(NODE *top) {
    return top->data;
}

void pushStack(NODE **top, int data) {

    NODE *node;
    node = (NODE *) malloc(sizeof(NODE));

    if (node == NULL) {
        printf("Memory allocation failure!\n");
        exit(1);
    }

    node->data = data;
    node->next = *top;
    *top = node;
}

void showStack(NODE *top) {
    NODE *node = top;

    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }

    printf("\n");
}

int popStack(NODE **top) {

    int value;
    NODE *node = *top;

    if (node == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }

    value = (int) (node->data);
    *top = node->next;
    free(node);
    return value;
}

void execute_stack_110() {

    int a = 10;
    int* p = &a;
    int** q = &p;

    cout << a << endl
         << "&A is: " << &a << endl
         << "P is: " << p << endl
         << "&P is: " << &p << endl
         << "*P is: " << *p << endl
         << "Q is: " << q << endl
         << "&Q is: " << &q << endl
         << "*Q is: " << *q << endl
         << "**Q is: " << **q << endl;

    NODE* stackTop = NULL;
    pushStack(&stackTop, 5);
    pushStack(&stackTop, 6);
    pushStack(&stackTop, 2);
    showStack(stackTop);
    printf("%d\n", popStack(&stackTop));
    printf("%d\n", popStack(&stackTop));
    printf("%d\n", showTop(stackTop));
}


#endif //TRACECODE_STACK_H
