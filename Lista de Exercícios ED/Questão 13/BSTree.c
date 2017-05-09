/*
 *  BSTree.c
 * 
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "BSTree.h"

void init(BSTree *tree) {
    *tree = NULL;
}

int empty(BSTree tree) {
    return !tree;
}

BSTree search(BSTree tree, int data) {
    if(empty(tree))
        return NULL;
    
    if(tree->data == data)
        return tree;
    
    if(data < tree->left->data)
        return search(tree->left, data);
    else
        return search(tree->right, data);
}

void preOrder(BSTree tree) {
    if(empty(tree))
        return;
    
    printf("%d ", tree->data);
    
    preOrder(tree->left);
    
    preOrder(tree->right);
}

void inOrder(BSTree tree) {
    if(empty(tree))
        return;
    
    inOrder(tree->left);
    
    printf("%d ", tree->data);
    
    inOrder(tree->right);
}

void postOrder(BSTree tree) {
    if(empty(tree))
        return;
    
    postOrder(tree->left);
    
    postOrder(tree->right);
    
    printf("%d ", tree->data);
}

int insertRoot(BSTree *tree, int data) {
    if(!empty(*tree))
        return 0;
    
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    
    *tree = node;
    
    return 1;
}

int insert(BSTree tree, int data) {
    if(empty(tree))
        return 0;
    
    if(data < tree->data) {
        if(tree->left)
            return insert(tree->left, data);
        
        tNode *node = (tNode *) malloc(sizeof(tNode));
        
        node->data  = data;
        node->left  = NULL;
        node->right = NULL;
        
        tree->left = node;
        
        return 1;
    }
    else {
        if(tree->right)
            return insert(tree->right, data);
        
        tNode *node = (tNode *) malloc(sizeof(tNode));
        
        node->data  = data;
        node->left  = NULL;
        node->right = NULL;
        
        tree->right = node;
        
        return 1;
    }
        
}