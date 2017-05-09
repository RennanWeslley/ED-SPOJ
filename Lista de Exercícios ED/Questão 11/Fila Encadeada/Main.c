/*
 *  Main.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Fila.h"

int main() {
    tQueue queue;
    int data;
    
    init(&queue);
    
    for(int i = 1; i < 6; i++)
        insert(&queue, i);
    
    print(queue);
    
    printf("\n");
    
    data = search(queue, 5);
    data? printf("Dado encontrado na posição %d\n", data) : printf("Dado não encontrado na fila\n");
    
    printf("\n");
    
    tQueue queue2;
    tQueue queue3;
    
    init(&queue2);
    init(&queue3);
    
    for(int i = 1; i < 6; i++)
        insert(&queue2, i);
    
    intercalate(queue, queue2, &queue3);
    
    print(queue3);
    
    for(int i = 1; i < 6; i++)
        del(&queue2);
    
    printf("\n");
    
    invert(queue, &queue2);
    
    print(queue2);
    
    printf("\n");
    
    return 0;
}
