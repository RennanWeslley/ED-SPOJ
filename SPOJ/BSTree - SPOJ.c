#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}tNode;

typedef tNode *BSTree;

long long c = 0;

void insertRoot(BSTree *, int);
void insert(BSTree, int);

int main() {
    BSTree tree;
    tree = NULL;
    
    int     n,
        value;
    
    scanf(" %d", &n);
    
    scanf(" %d", &value);
    insertRoot(&tree, value);
    printf("%lld\n", c);
    
    n--;
    
    do {
        scanf(" %d", &value);
        insert(tree, value);
        printf("%lld\n", c);
    }while(--n);
    
    return 0;
}

void insertRoot(BSTree *tree, int data) {
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data  = data;
    new->left  = NULL;
    new->right = NULL;
    
    *tree = new;
}

void insert(BSTree tree, int data) {
    c++;
    
    if(data < tree->data) {
        if(tree->left)
            return insert(tree->left, data);
        
        tNode *new = (tNode *) malloc(sizeof(tNode));
        
        new->data  = data;
        new->left  = NULL;
        new->right = NULL;
        
        tree->left = new;
        
        return;
    }
    else {
        if(tree->right)
            return insert(tree->right, data);
        
        tNode *new = (tNode *) malloc(sizeof(tNode));
        
        new->data  = data;
        new->left  = NULL;
        new->right = NULL;
        
        tree->right = new;
        
        return;
    }
}
