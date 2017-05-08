/*
 *  Pilha.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Pilha Encadeada/Pilha.h"

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

char top(tStack stack) {
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

void invert(tStack *stack) {
    if(empty(*stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    tStack aux;
    init(&aux);
    
    for(; !empty(*stack);)
        push(&aux, pop(stack));
    
    *stack = aux;
    
    /* stack->top = aux.top */
}

int equals(tStack stack1, tStack stack2) {
    if(empty(stack1) || empty(stack2) || (size(stack1) != size(stack2)))
        return 0;
    
    for(tNode *p1 = stack1.top, *p2 = stack2.top; p1; p1 = p1->next, p2 = p2->next)
        if(p1->data != p2->data)
            return 0;
        
    return 1;
}

int push(tStack *stack, char data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return -1;
    
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    
    stack->size++;
    
    return 1;
}

char pop(tStack *stack) {
    if(empty(*stack))
        return 0;
    
    tNode *p   = stack->top;
    stack->top = p->next;
    
    char data = p->data;
    p->next  = NULL;
    free(p);
    
    stack->size--;
    
    return data;
}

int popValue(tStack *stack, char data) {
    if(empty(*stack))
        return 0;
    
    tStack aux;
    init(&aux);
    int c = 0;
    
    tNode *p = stack->top;
    
    for(; p; p = p->next)
        if(p->data != data) 
            push(&aux, p->data);
        else
            c++;
    
    *stack = aux;
        
    return c;
}

void destroy(tStack *stack) {
    if(empty(*stack))
        return;
    
    for(; !empty(*stack); pop(stack));
}
