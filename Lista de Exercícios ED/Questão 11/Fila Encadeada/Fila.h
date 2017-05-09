/*
 *  Fila.h
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}tNode;

typedef struct {
    tNode *front;
    tNode *back;
    int size;
}tQueue;

//GENERAL FUNCTIONS
void init(tQueue *);
int size(tQueue);
int empty(tQueue);
void print(tQueue);
int search(tQueue, int);
void intercalate(tQueue, tQueue, tQueue *);
void invert(tQueue, tQueue *);

//INSERT FUNCTIONS
int insert(tQueue *, int);

//DELETE FUNCTIONS
int del(tQueue *);

#endif //FILA_H
