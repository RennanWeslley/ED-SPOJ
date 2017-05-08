#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void init(tStack *stack) {
    stack->top  = NULL;
    stack->size = 0;
}

int size(tStack stack) {
    return stack.size;
}

int empty(tStack stack) {
    return !stack.top;
}

int top(tStack stack) {
    return stack.top->data;
}

void print(tStack stack) {
    if(empty(stack)) {
        printf("Empty\n");
        return;
    }
    
    printf("Stack: {");
    
    for(tNode *p = stack.top; p; p = p->next)
        if(!p->next)
            printf("%d}\n", p->data);
        else
            printf("%d, ", p->data);       
}

int push(tStack *stack, int data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return -1;
    
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    
    stack->size++;
    
    return 1;
}

int pop(tStack *stack) {
    if(empty(*stack))
        return 0;
    
    tNode *p   = stack->top;
    stack->top = p->next;
    
    int data = p->data;
    p->next  = NULL;
    free(p);
    
    stack->size--;
    
    return data;
}