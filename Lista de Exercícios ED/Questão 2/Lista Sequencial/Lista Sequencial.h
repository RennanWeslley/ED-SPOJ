 /*
 *  Lista Sequencial.h
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 100

typedef struct {
    int data[MAX];
    int size;
}tList;

//GENERAL FUNCTIONS
void init(tList *);
int size(tList);
int empty(tList);
int full(tList);
int visit(tList, int);
int search(tList, int);
void print(tList);
void evenOrOdd(tList, tList *, tList *);
void catenate(tList, tList, tList *);
int changeValue(tList *, int, int);

//INSERT FUNCTIONS
int insert(tList *, int, int);

//REMOVE FUNCTIONS
int del(tList *, int, int *);
int delValue(tList *, int, int *);

#endif //LISTA_SEQUENCIAL_H