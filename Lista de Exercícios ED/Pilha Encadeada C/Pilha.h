#ifndef PILHA_H
#define PILHA_H

typedef struct node {
    int data;
    struct node *next;
}tNode;

typedef struct {
    tNode *top;
    int size;
}tStack;

//GENERAL FUNCTIONS
void init(tStack *);
int size(tStack);
int empty(tStack);
int top(tStack);
void print(tStack);

//PUSH FUNCTIONS
int push(tStack *, int);

//POP FUNCTIONS
int pop(tStack *);

#endif //PILHA_H