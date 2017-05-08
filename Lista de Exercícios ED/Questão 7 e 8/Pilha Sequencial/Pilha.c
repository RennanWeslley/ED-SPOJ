/*
 *  Pilha.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Pilha.h"

void init(tStack *stack) {
    stack->top = -1;
}

int size(tStack stack) {
    return (stack.top+1);
}

int full(tStack stack) {
    return !(stack.top < MAX);
}

int empty(tStack stack) {
    return stack.top == -1;
}

int top(tStack stack) {
    return stack.data[stack.top];
}

void print(tStack stack) {
    if(empty(stack)) {
        printf("Empty\n");
        return;
    }
    
    printf("Stack: {");
    
    for(int i = stack.top; i > -1; i--)
        if(i == 0)
            printf("%d}\n", stack.data[i]);
        else
            printf("%d, ", stack.data[i]);
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
}

int equals(tStack stack1, tStack stack2) {
    if(empty(stack1) || empty(stack2) || (size(stack1) != size(stack2)))
        return 0;
    
    for(int i = 0; i < size(stack1); i++)
        if(stack1.data[i] != stack2.data[i])
            return 0;
        
    return 1;
}

int push(tStack *stack, int data) {
    if(full(*stack))
        return 0;
    
    stack->top++;
    stack->data[stack->top] = data;
    
    return 1;
}

int pop(tStack *stack) {
    if(empty(*stack))
        return 0;
    
    int data = stack->data[stack->top];
    stack->top--;
    
    return data;
}

int popValue(tStack *stack, int data) {
    if(empty(*stack))
        return 0;
    
    tStack aux;
    init(&aux);
    int c = 0;
    
    for(int i = 0; i < size(*stack); i++)
        if(stack->data[i] != data)
            push(&aux, stack->data[i]);
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