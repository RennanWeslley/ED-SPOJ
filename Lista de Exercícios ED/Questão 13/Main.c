/*
 *  Main.c
 * 
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "BSTree.h"

int main() {
    BSTree tree;
    int data;
    
    init(&tree);
    
    insertRoot(&tree, 3);
    
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 5);
    insert(tree, 6);
    
    preOrder(tree);
    printf("\n\n");
    
    inOrder(tree);
    printf("\n\n");
    
    postOrder(tree);
    printf("\n\n");
    return 0;
}
