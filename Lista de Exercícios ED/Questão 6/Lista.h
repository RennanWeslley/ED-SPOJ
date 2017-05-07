/*
 *  Lista.h
 *
 *  Created on: May 7th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include<iostream>
#include<cstdlib>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class List {
    private:
        Node *head;
        int size;
        
    public:
        //GENERAL FUNCTIONS
        List();
        int getSize();
        bool empty();
        int visit(int);
        int search(int);
        
        //INSERT FUNCTIONS
        int insert(int, int);
        int insertHead(int);
        int insertIndx(int, int);
        /* int insertBack(int); */
        
        //REMOVE FUNCTIONS
        int del(int, int *);
        int delHead(int *);
        int delIndx(int, int *);
        /* int delBack(tList *, int *); */
        
        //PRINT FUNCTION
        string toString();
};

#endif //LISTA DINAMICA_H
