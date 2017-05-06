/*
 *  Lista Dinamica.h
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

typedef struct node {
    int data;
    struct node *next;
}tNode;

typedef struct {
    tNode *head;
    int size;
}tList;

//GENERAL FUNCTIONS
void init(tList *);
int size(tList);
int empty(tList);
int visit(tList, int);
int search(tList, int);
void print(tList);

//INSERT FUNCTIONS
int insert(tList *, int, int);
int insertHead(tList *, int);
int insertIndx(tList *, int, int);
int insertBack(tList *, int);

//REMOVE FUNCTIONS
int del(tList *, int, int *);
int delHead(tList *, int *);
int delIndx(tList *, int, int *);
/* int removeBack(tList *, int *); */



#endif //LISTA DINAMICA_H