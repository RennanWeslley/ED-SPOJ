#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int childrens;
    struct node *next;
}tNode;

typedef struct {
    tNode *top;
}tStack;

int empty(tStack);
int push(tStack *, char);
int pop(tStack *);
int height(tStack, char *);

int main() {
    tStack stack;
    stack.top = NULL;
    
    char preOrder[20];
    int n;
    
    scanf(" %d", &n);
    
    do {
        scanf(" %s", preOrder);
        
        printf("%d\n", height(stack, preOrder));
        
        strcpy(preOrder, "");
    }while(--n);
    
    return 0;
}

int empty(tStack stack) {
    return stack.top == NULL;
}

int push(tStack *stack, char data) {
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data = data;
    new->childrens = 0;
    new->next = stack->top;
    stack->top = new;
    
    return 1;
}

int pop(tStack *stack) {
    if(empty(*stack))
        return 0;
    
    tNode *p = stack->top;
    
    stack->top = stack->top->next;
    free(p);
    
    return 1;
}

int height(tStack stack, char *preOrder) {
    int size = 0;
    
    for(int i = 0; i < strlen(preOrder); i++) {
        if(!empty(stack)) 
            if(stack.top->childrens >= 2) {
                pop(&stack);
            
                if(!empty(stack) && stack.top->data == 'n')
                    stack.top->childrens++;
            }
            
        push(&stack, preOrder[i]);
        
        if(preOrder[i] == 'l') {
            pop(&stack);
            
            if(!empty(stack) && stack.top->data == 'n')
                stack.top->childrens++;
            
            size++;
        }
    }
    
    return --size;
}



