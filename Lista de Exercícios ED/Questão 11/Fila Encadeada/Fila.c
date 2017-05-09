/*
 *  Fila.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Fila.h"
#include "Pilha.h"

void init(tQueue *queue) {
    queue->front = NULL;
    queue->back  = NULL;
    queue->size  = 0;
}

int size(tQueue queue) {
    return queue.size;
}

int empty(tQueue queue) {
    return !queue.front;
}

void print(tQueue queue) {
    if(empty(queue)) {
        printf("Empty\n");
        return;
    }
    
    printf("Queue: {");
    
    for(tNode *p = queue.front; p; p = p->next)
        if(!p->next)
            printf("%d}\n", p->data);
        else
            printf("%d, ", p->data);
}

int search(tQueue queue, int data) {
    if(empty(queue))
        return 0;
    
    tNode *p = queue.front;
    
    for(int i = 1; p; p = p->next, i++)
        if(p->data == data)
            return i;
        
    return 0;
}

void intercalate(tQueue queue1, tQueue queue2, tQueue *newQueue) {
    if((size(queue1) != size(queue2)) || empty(queue1) || !empty(*newQueue))
        return;
          
    for(tNode *p1 = queue1.front, *p2 = queue2.front; p1; p1 = p1->next, p2 = p2->next) {
        insert(newQueue, p1->data);
        insert(newQueue, p2->data);
    }
}

void invert(tQueue queue, tQueue *newQueue) {
    if(empty(queue) || !empty(*newQueue))
        return;
    
    tStack stack;
    
    initStack(&stack);
    
    for(tNode *p = queue.front; p; p = p->next)
        push(&stack, p->data);
    
    for(; !emptyStack(stack); insert(newQueue, pop(&stack)));
}

int insert(tQueue *queue, int data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return -1;
    
    node->data = data;
    node->next = NULL;
    
    if(empty(*queue))
        queue->front = node;
    else
        queue->back->next = node; 
        
    queue->back = node;
    
    queue->size++;
    
    return 1;
}

int del(tQueue *queue) {
    if(empty(*queue))
        return 0;
    
    tNode *p = queue->front;
    queue->front = p->next;
    
    int data = p->data;
    p->next  = NULL;
    free(p);
    
    if(queue->size == 1)
        queue->front = NULL;
    
    queue->size--;
    
    return data;
}
