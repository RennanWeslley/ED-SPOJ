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
    
    insertRoot(&tree, 5);
    
    insertLeft(tree, 5, 3);
    insertRight(tree, 5, 13);
    
    insertLeft(tree, 13, 11);
    insertRight(tree, 13, 19);
    
    insertLeft(tree, 11, 7);
    
    insertLeft(tree, 19, 17);
    insertRight(tree, 19, 23);
    
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
