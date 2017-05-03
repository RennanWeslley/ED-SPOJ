#ifndef TREE_H
#define TREE_H

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}tNode;

typedef tNode *BinaryTree;

void init(BinaryTree *);
int empty(BinaryTree);
BinaryTree search(BinaryTree, int);
int pushRoot(BinaryTree *, int);
int pushRight(BinaryTree, int, int);
int pushLeft(BinaryTree, int, int);

void preOrder(BinaryTree);
void inOrder(BinaryTree);
void postOrder(BinaryTree);

#endif //TREE_H