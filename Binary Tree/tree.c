#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(BinaryTree *tree) {
    *tree = NULL;
}

int empty(BinaryTree tree) {
    return tree == NULL;
}

BinaryTree search(BinaryTree tree, int data) {
    if(!tree)
        return NULL;
    
    if(tree->data == data)
        return tree;
    
    BinaryTree aux = search(tree->left, data);
    
    if(!aux)
        aux = search(tree->right, data);
    
    return aux;
}

int pushRoot(BinaryTree *tree, int data) {
    if(!empty(*tree))
        return 0;
    
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data  = data;
    new->right = NULL;
    new->left  = NULL;
    
    *tree = new;
    
    return 1;
}

int pushRight(BinaryTree tree, int father, int data) {
    if(empty(tree))
        return 0;
    
    tNode *aux = search(tree, data);
    
    if(aux)
        return 0;
    
    aux = search(tree, father);
    
    if(aux && !(aux->right)) {
        tNode *new = (tNode *) malloc(sizeof(tNode));
        
        new->data  = data;
        new->right = NULL;
        new->left  = NULL;
        
        aux->right = new;
        
        return 1;
    }
    
    return 0;
}

int pushLeft(BinaryTree tree, int father, int data) {
    if(empty(tree))
        return 0;
    
    tNode *aux = search(tree, data);
    
    if(aux)
        return 0;
    
    aux = search(tree, father);
    
    if(aux && !(aux->left)) {
        tNode *new = (tNode *) malloc(sizeof(tNode));
        
        new->data  = data;
        new->right = NULL;
        new->left  = NULL;
        
        aux->left = new;
        
        return 1;
    }
    
    return 0;
}

void preOrder(BinaryTree tree) {
    if(empty(tree))
        return;
    
    if(!tree)
        return;
    
    printf("%d ", tree->data);
    
    preOrder(tree->left);
    
    preOrder(tree->right);
}

void inOrder(BinaryTree tree) {
    if(empty(tree))
        return;
    
    if(!tree)
        return;
    
    inOrder(tree->left);
    
    printf("%d ", tree->data);
    
    inOrder(tree->right);
}

void postOrder(BinaryTree tree) {
    if(empty(tree))
        return;
    
    if(!tree)
        return;
    
    postOrder(tree->left);
    
    postOrder(tree->right);
    
    printf("%d ", tree->data);
}