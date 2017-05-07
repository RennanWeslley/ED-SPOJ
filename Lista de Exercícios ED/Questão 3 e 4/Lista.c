#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void init(tList *list) {
    list->head = NULL;
    list->back = NULL;
    list->size = 0;
}

int size(tList list) {
    return list.size;
}

int empty(tList list) {
    return !list.head;
}

int visit(tList list, int pos) {
    if(empty(list) || pos < 1)
        return 0;
    
    tNode *p;
    int half = (list.size/2);
    
    if(pos > half) {
        p = list.back;
        
        for(int i = list.size; i >= half; p = p->prev, i--)
            if(i == pos)
                return p->data;
    }
    else {
        p = list.head;
        
        for(int i = 1; i <= half; p = p->next, i++)
            if(i == pos)
                return p->data;
    }
}

int search(tList list, int data) {
    if(empty(list))
        return 0;
    
    int half = (list.size/2);
    
    tNode *nex = list.head,
          *pre = list.back;
          
    for(int i = 1, j = list.size; i <= half; nex = nex->next, pre = pre->prev, i++, j--)
        if(nex->data == data)
            return i;
        else if(pre->data == data)
            return j;
         
    return 0;
}

void print(tList list) {
    if(empty(list)) {
        printf("Empty.\n");
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

void printBack(tList list) {
    if(empty(list)) {
        printf("Empty.\n");
        return;
    }
    
    tNode *p = list.back;
    
    printf("List: {");
    for(; p; p = p->prev)
        if(!p->prev)
            printf("%d}\n", p->data);
        else
            printf("%d, ", p->data);
}

int insert(tList *list, int pos, int data) {
    if(pos < 1)
        return 0;
    
    if(empty(*list) || pos == 1)
        return insertHead(list, data);
    
    if(pos >= list->size)
        return insertBack(list, data);
    
    return insertIndx(list, pos, data);
}

int insertHead(tList *list, int data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return -1;
    
    node->data = data;
    node->prev = NULL;
    
    if(!list->size) {
        node->next = NULL;
        list->head = node;
        list->back = node;
    }
    else {
        node->next       = list->head;
        list->head->prev = node;
        list->head       = node;
    }
    
    list->size++;
    
    return 1;
}

int insertIndx(tList *list, int pos, int data) {
    int    half = (list->size/2);
    tNode *node = (tNode *) malloc(sizeof(tNode)),
          *p;
          
    if(!node)
        return -1;
    
    node->data = data;
    
    if(pos > half) {
        p = list->back->prev;
        
        for(int i = (list->size-1); i >= half; p = p->prev ,i--)
            if(i == pos)
                break;
        
        node->next    = p;
        p             = p->prev;
        node->prev    = p;
        p->next->prev = node;
        p->next       = node;
        
        list->size++;
    }
    else {
        p = list->head->next;
        
        for(int i = 1; i <= half; p = p->next, i++)
            if(i == pos)
                break;
        
        node->next    = p;
        p             = p->prev;
        node->prev    = p;
        p->next->prev = node;
        p->next       = node;
        
        list->size++;
    }
    
    return 1;
}

int insertBack(tList *list, int data) {
    tNode *node = (tNode *) malloc(sizeof(tNode));
    
    if(!node)
        return -1;
    
    node->data       = data;
    node->next       = NULL;
    node->prev       = list->back;
    list->back->next = node;
    list->back       = node;
    
    list->size++;
}

int del(tList *list, int pos, int *data) {
    if(empty(*list) || pos < 1)
        return 0;
    
    if(pos == 1)
        return delHead(list, data);
    
    if(pos >= list->size)
        return delBack(list, data);
    
    return delIndx(list, pos, data);
}

int delHead(tList *list, int *data) {
    tNode *p = list->head;
    
    *data            = p->data;
    list->head       = p->next;
    list->head->prev = NULL;
    
    p->next = NULL;
    free(p);
    
    list->size--;
}

int delIndx(tList *list, int pos, int *data) {
    tNode *p,
          *aux;
    int half = (list->size/2);
    
    if(pos > half) {
        p = list->back->prev;
        
        for(int i = (list->size-1); i >= half; p = p->prev, i--)
            if(i == pos)
                break;
        
        *data           = p->data;
        aux             = p;
        p               = p->prev;
        p->next         = aux->next;
        aux->next->prev = p;
        
        aux->next = NULL;
        aux->prev = NULL;
        free(aux);
        
        list->size--;
    }
    else {
        p = list->head->next;
        
        for(int i = 1; i <= half; p = p->next, i++)
            if(i == pos)
                break;
        
        *data           = p->data;
        aux             = p;
        p               = p->prev;
        p->next         = aux->next;
        aux->next->prev = p;
        
        aux->next = NULL;
        aux->prev = NULL;
        free(aux);
        
        list->size--;
    }
    
    return 1;
}

int delBack(tList *list, int *data) {
    tNode *p = list->back;
    
    *data            = p->data;
    list->back       = p->prev;
    list->back->next = NULL;
    
    p->prev = NULL;
    free(p);
    
    list->size--;
    
    return 1;
}