/*
 *  BTree.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "BTree.h"

void init(BTree *tree) {
    *tree = NULL;
}

int empty(BTree tree) {
    return !tree;
}

BTree search(BTree tree, int data) {
    if(empty(tree))
        return NULL;
    
    if(tree->data == data)
        return tree;
    
    BTree p = search(tree->left, data);
    
    if(!p)
        p = search(tree->right, data);
    
    return p;
}

void preOrder(BTree tree) {
    if(empty(tree))
        return;
    
    printf("%d ", tree->data);
    
    preOrder(tree->left);
    
    preOrder(tree->right);
}

void inOrder(BTree tree) {
    if(empty(tree))
        return;
    
    inOrder(tree->left);
    
    printf("%d ", tree->data);
    
    inOrder(tree->right);
}

void postOrder(BTree tree) {
    if(empty(tree))
        return;
    
    postOrder(tree->left);
    
    postOrder(tree->right);
    
    printf("%d ", tree->data);
}

BTree leftNode(BTree tree) {
    if(empty(tree))
        return NULL;
    
    return tree->left;
}

BTree rightNode(BTree tree) {
    if(empty(tree))
        return NULL;
    
    return tree->right;
}

void nodeFamily(BTree tree) {
    printf("In Pre-Order: ");
    preOrder(tree);
    
    printf("In In-Order: ");
    inOrder(tree);
    
    printf("In Post-Order: ");
    postOrder(tree);
}

int nodesNumber(BTree tree) {
    if(empty(tree))
        return 0;
    
    static int c = 0;
    
    c++;
    
    if(tree->left)
        nodesNumber(tree->left);
    if(tree->right)
        nodesNumber(tree->right);
    
    return c;
}

int insertRoot(BTree *tree, int data) {
    if(!empty(*tree))
        return 0;
    
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    
    *tree = node;
    
    return 1;
}

int insertLeft(BTree tree, int father, int data) {
    if(empty(tree))
        return 0;
    
    tNode *p = search(tree, data);
    
    if(p)
        return 0;
    
    p = search(tree, father);
    
    if(!p || p->left)
        return 0;
    
    tNode *node = (tNode *) malloc(sizeof(tNode));
        
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    
    p->left = node;
    
    return 1;
}

int insertRight(BTree tree, int father, int data) {
    if(empty(tree))
        return 0;
    
    tNode *p = search(tree, data);
    
    if(p)
        return 0;
    
    p = search(tree, father);
    
    if(!p || p->right)
        return 0;
    
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    
    p->right = node;
    
    return 1;
}