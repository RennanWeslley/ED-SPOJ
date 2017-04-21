#include <stdio.h>
#include <stdlib.h>

#define MAX 8001

typedef struct node {
    int data;
    struct node *right;
    struct node *left;
}tNode;

typedef tNode *BinaryTree;

int pre[MAX];
int post[MAX];
int in[MAX];
int auxPost[MAX];

int search(int, int, int);
void postOrder(BinaryTree);
BinaryTree build(int, int);

int main() {
    int n;
    
    scanf(" %d", &n);
    
    for(int i = 0; i < n; scanf(" %d", &pre[i]), i++);
    for(int i = 0; i < n; scanf(" %d", &post[i]), i++);
    for(int i = 0; i < n; scanf(" %d", &in[i]), i++);
    
    BinaryTree tree = build(0, (n-1));
    
    postOrder(tree);
    
    int flag = 1;
    int i;
    
    for(i = 0; i < n; i++)
        if(post[i] != auxPost[i]) {
            flag = 0;
            break;
        }
    
    if(flag)
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}

int search(int first, int last, int data) {
    for(int i = first; i <= last; i++)
        if(in[i] == data)
            return i;
        
    return 0;
}

void postOrder(BinaryTree tree) {
    if(!tree)
        return;
    
    int static add = 0;
    
    postOrder(tree->left);
    
    postOrder(tree->right);
    
    auxPost[add++] = tree->data;
}

BinaryTree build(int first, int last) {
    static int add = 0;
    
    if(first > last)
        return NULL;
    
    /*PUSH*/
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data  = pre[add++];
    new->right = NULL;
    new->left  = NULL;
    /*END PUSH*/
    
    /*If is a leaf*/
    if(first == last)
        return new;
    
    /*Search the Preorder root in Inorder array*/
    int i = search(first, last, new->data);
    
    /*If the root isn't in Inorder array*/
    if(!i)
        return NULL;
    
    /*Nodes in left of current root, are actually in left of tree*/
    new->left  = build(first, (i-1));
    
    /*Nodes in right of current root, are actually in right of tree*/
    new->right = build((i+1), last);
    
    /*At last recursive iterator, return the root of tree*/
    return new;
}