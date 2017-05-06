 /*
 *  Main.c
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista Sequencial.h"
#include <stdio.h>

int main() {
    tList list;
    int data;
    
    init(&list);
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    
    for(int i = 1; i <= 10; i++)
        insert(&list, i, i);
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    
    //A)
    printf("Exibindo Lista:\n");
    print(list);
    printf("\n");
    
    //B)
    tList pair,
           odd;
           
    init(&pair);
    init(&odd);
           
    evenOrOdd(list, &pair, &odd);
    
    printf("Lista Par:\n");
    print(pair);
    printf("Lista Ímpar:\n");
    print(odd);
    printf("\n");
    
    
    //C)
    tList newList;
    
    init(&newList);
    
    catenate(pair, odd, &newList);
    
    printf("Concatenando as listas Par e Ímpar:\n");
    print(newList);
    printf("\n");
    
    //D)
    changeValue(&newList, size(newList), 90);
    
    printf("Mudando o último valor para 90:\n");
    print(newList);
    printf("\n");
    
    //E
    printf("Deletando o primeiro valor 90 da lista:\n");
    delValue(&newList, 90, &data);
    print(newList);
    
    return 0;
}
