#ifndef LISTA_H
#define LISTA_H

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}tNode;

typedef struct {
    tNode *head;
    tNode *back;
    int size;
}tList;

//GENERAL FUNCTIONS
void init(tList *);
int size(tList);
int empty(tList);
int visit(tList, int);
int search(tList, int);
void print(tList);
void printBack(tList);

//INSERT FUNCTIONS
int insert(tList *, int, int);
int insertHead(tList *, int);
int insertIndx(tList *, int, int);
int insertBack(tList *, int);

//REMOVE FUNCTIONS
int del(tList *, int, int *);
int delHead(tList *, int *);
int delIndx(tList *, int, int *);
int delBack(tList *, int *);

#endif //LISTA_H