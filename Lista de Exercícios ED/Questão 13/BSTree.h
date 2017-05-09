/*
 *  BSTree.h
 * 
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef BSTREE_H
#define BSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}tNode;

typedef tNode *BSTree;

//GENREAL FUNCTIONS
void init(BSTree *);
int empty(BSTree);
BSTree search(BSTree, int);
void preOrder(BSTree);
void inOrder(BSTree);
void postOrder(BSTree);

//INSERT FUNCTIONS
int insertRoot(BSTree *, int);
int insert(BSTree, int);

//DELETE FUNCTIONS
/* ... */

#endif //BSTREE_H