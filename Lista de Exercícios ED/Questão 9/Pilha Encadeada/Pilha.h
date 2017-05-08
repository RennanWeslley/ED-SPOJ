/*
 *  Pilha.h
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
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
char top(tStack);
void print(tStack);
void invert(tStack *);
int equals(tStack, tStack);

//PUSH FUNCTIONS
int push(tStack *, char);

//POP FUNCTIONS
char pop(tStack *);
int popValue(tStack *, char);
void destroy(tStack *);

#endif //PILHA_H
