/*
 *  BTree.h
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}tNode;

typedef tNode *BTree;

//GENERAL FUNCTIONS
void init(BTree *);
int empty(BTree);
BTree search(BTree, int);
void preOrder(BTree);
void inOrder(BTree);
void postOrder(BTree);
BTree leftNode(BTree);
BTree rightNode(BTree);
void nodeFamily(BTree);
int nodesNumber(BTree);

//INSERT FUNCTIONS
int insertRoot(BTree *, int);
int insertLeft(BTree, int, int);
int insertRight(BTree, int, int);

//DELETE FUNCTIONS
/* ... */


#endif //BTREE_H