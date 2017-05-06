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

void evenOrOdd(tList list, tList *pair, tList *odd) {
    if(empty(list) || !empty(*pair) || !empty(*odd))
        return;
    
    for(int i = 0, pa = 1, od = 1; i < list.size; i++)
        if(list.data[i] % 2 == 0) {
            insert(pair, pa, list.data[i]);
            pa++;
        }
        else {
            insert(odd, od, list.data[i]);
            od++;
        }
}

void catenate(tList list1, tList list2, tList *newList) {
    if(empty(list1) || empty(list2) || !empty(*newList))
        return;
    
    int i = 0;
    
    for(; i < list1.size; i++)
        insert(newList, (i+1), list1.data[i]);
    
    for(int j = 0; j < list2.size; j++, i++) 
        insert(newList, (i+1), list2.data[j]);
}

int changeValue(tList *list, int pos, int data) {
    if(empty(*list) || pos < 1)
        return 0;
    
    pos--;
    
    if(pos > list->size)
        pos = list->size;
    
    list->data[pos] = data;
    
    return 1;
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

int delValue(tList *list, int data, int *aux) {
    if(empty(*list))
        return 0;
    
    int pos = search(*list, data);
    
    if(!pos)
        return -1;
    
    return del(list, pos, aux);
}