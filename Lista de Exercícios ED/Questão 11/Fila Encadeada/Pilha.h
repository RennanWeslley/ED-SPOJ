/*
 *  Pilha.h
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef PILHA_H
#define PILHA_H

typedef struct tNode {
    int data;
    struct tNode *next;
}node_t;

typedef struct {
    node_t *top;
    int size;
}tStack;

//GENERAL FUNCTIONS
void initStack(tStack *);
int emptyStack(tStack);

//PUSH FUNCTIONS
int push(tStack *, int);

//POP FUNCTIONS
int pop(tStack *);

#endif //PILHA_H
