/*
 *  Lista Dinamica.c
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista Dinamica.h"
#include <stdio.h>
#include <stdlib.h>

void init(tList *list) {
    list->head = NULL;
    list->size = 0;
}

int size(tList list) {
    return list.size;
}

int empty(tList list) {
    return !list.head;
}

int visit(tList list, int pos) {
    if(pos < 1 || empty(list))
        return 0;
    
    if(pos > list.size)
        pos = list.size;
    
    tNode *p = list.head;
    
    for(int i = 1; p; p = p->next, i++)
        if(i == pos)
            return p->data;
}

int search(tList list, int data) {
    tNode *p = list.head;
    
    for(int i = 1; p; p = p->next, i++)
        if(p->data == data)
            return i;
        
    return 0;
}

void print(tList list) {
    if(empty(list)) {
        printf("Empty\n\n");
        return;
    }
    
    tNode *p = list.head;
    
    printf("List: {");
    for(; p; p = p->next)
        if(!p->next)
            printf("%d}\n", p->data);
        else
            printf("%d, ", p->data);
}

int insert(tList *list, int pos, int data) {
    if(pos < 1)
        return 0;
    
    if((pos-1) > list->size)
        pos = list->size;
    
    if(empty(*list) || pos == 1)
        return insertHead(list, data);
    
    if(pos >= list->size)
        return insertBack(list, data);
    
    return insertIndx(list, pos, data);
}

int insertHead(tList *list, int data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return 0;
    
    node->data = data;
    node->next = list->head;
    list->head = node;
    
    list->size++;
    
    return 1;
}

int insertIndx(tList *list, int pos, int data) {
    tNode *p = list->head;
    
    for(int i = 2; p; p = p->next, i++)
        if(i == pos)
            break;
        
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return 0;
    
    node->data = data;
    node->next = p->next;
    p->next    = node;
    
    list->size++;
    
    return 1;
}

int insertBack(tList *list, int data) {
    tNode *p = list->head;
    
    for(; p->next; p = p->next);
    
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return 0;
    
    node->data = data;
    node->next = NULL;
    p->next    = node;
    
    list->size++;
    
    return 1;
}

int del(tList *list, int pos, int *data) {
    if(pos < 1)
        return 0;
    
    if((pos-1) > list->size)
        pos = list->size;
    
    if(empty(*list))
        return 0;
    
    if(pos == 1)
        return delHead(list, data);
    
    return delIndx(list, pos, data);
}

int delHead(tList *list, int *data) {
    tNode *p   = list->head;
    list->head = p->next;
    
    *data = p->data;
    free(p);
    
    list->size--;
    
    return 1;
}

int delIndx(tList *list, int pos, int *data) {
    tNode *p = list->head,
          *aux;
    
    for(int i = 2; p; p = p->next, i++)
        if(i == pos)
            break;
    
    aux     = p->next;
    p->next = aux->next;
    
    aux->next = NULL;
    *data = aux->data;
    free(aux);
    
    list->size--;
    
    return 1;
}
