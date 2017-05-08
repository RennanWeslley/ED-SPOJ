/*
 *  Pilha.h
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef PILHA_H
#define PILHA_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data[MAX];
    int top;
}tStack;

//GENERAL FUNCTIONS
void init(tStack *);
int size(tStack);
int full(tStack);
int empty(tStack);
int top(tStack);
void print(tStack);
void invert(tStack *);
int equals(tStack, tStack);

//PUSH FUNCTIONS
int push(tStack *, int);

//POP FUNCTIONS
int pop(tStack *);
int popValue(tStack *, int);
void destroy(tStack *);

#endif //PILHA_H
