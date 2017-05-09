/*
 *  Main.c
 * 
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "BTree.h"

int main() {
    BTree tree;
    int data;
    
    init(&tree);
    
    insertRoot(&tree, 1);
    
    insertLeft(tree, 1, 2);
    insertRight(tree, 1, 3);
    
    insertLeft(tree, 2, 4);
    
    insertLeft(tree, 3, 5);
    insertRight(tree, 3, 6);
    
    preOrder(tree);
    printf("\n\n");
    
    inOrder(tree);
    printf("\n\n");
    
    postOrder(tree);
    printf("\n\n");
    
    printf("Number of nodes %d\n", nodesNumber(tree));
    
    printf("\n");
    
    return 0;
}