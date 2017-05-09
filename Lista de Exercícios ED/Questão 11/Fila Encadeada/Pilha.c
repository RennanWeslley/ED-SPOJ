/*
 *  Pilha.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(tStack *stack) {
    stack->top  = NULL;
    stack->size = 0;
}

int emptyStack(tStack stack) {
    return !stack.top;
}

int push(tStack *stack, int data) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    
    if(!node)
        return -1;
    
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    
    stack->size++;
    
    return 1;
}

int pop(tStack *stack) {
    if(emptyStack(*stack))
        return 0;
    
    node_t *p   = stack->top;
    stack->top = p->next;
    
    int data = p->data;
    p->next  = NULL;
    free(p);
    
    stack->size--;
    
    return data;
}
