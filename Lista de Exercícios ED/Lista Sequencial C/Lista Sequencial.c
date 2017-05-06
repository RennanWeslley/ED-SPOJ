 /*
 *  Lista Sequencial.c
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista Sequencial.h"
#include <stdio.h>

void init(tList *list) {
    list->size = 0;
}

int size(tList list) {
    return list.size;
}

int empty(tList list) {
    return list.size == 0;
}

int full(tList list) {
    return list.size >= MAX;
}

int visit(tList list, int pos) {
    if(pos < 1 || empty(list))
        return 0;
    
    pos--;
    
    if(pos > list.size)
        pos = list.size;
    
    return list.data[pos];
}

int search(tList list, int data) {
    if(empty(list))
        return 0;
    
    for(int i = 0; i < list.size; i++)
        if(list.data[i] == data)
            return ++i;
        
    return 0;
}

void print(tList list) {
    if(empty(list)) {
        printf("Empty.\n");
        return;
    }
    
    printf("List: {");
    for(int i = 0; i < list.size; i++)
        if((i+1) == list.size)
            printf("%d}\n", list.data[i]);
        else
            printf("%d, ", list.data[i]);
}

int insert(tList *list, int pos, int data) {
    if(full(*list) || pos < 1)
        return 0;
    
    pos--;
    
    if(pos > list->size)
        pos = list->size;
    
    for(int i = (list->size + 1); i > pos; i--)
        list->data[i] = list->data[i-1];
    
    list->data[pos] = data;
    list->size++;
    
    return 1;
}

int del(tList *list, int pos, int *data) {
    if(empty(*list) || pos < 1)
        return 0;
    
    pos--;
    
    if(pos > list->size)
        pos = list->size;
    
    *data = list->data[pos];
    
    for(int i = pos; i < list->size; i++)
        list->data[i] = list->data[i+1];
    
    list->size--;
    
    return 1;
}