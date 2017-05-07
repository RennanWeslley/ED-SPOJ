 /*
 *  Listas Questões 3 e 4.c
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista.h"
#include <stdio.h>

int main() {
    tList list;
    init(&list);
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    insert(&list, 1, 2);
    print(list);
    printBack(list);
    printf("\n");
    
    insert(&list, 2, 3);
    print(list);
    printBack(list);
    printf("\n");
    
    insert(&list, 1, 1);
    print(list); 
    printBack(list);
    printf("\n");
    
    insert(&list, 4, 4);
    print(list);
    printBack(list);
    printf("\n");
    
    insert(&list, 30, 5);
    print(list);
    printBack(list);
    printf("\n");
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    
    printf("\n");
    
    int dado = search(list, 6);
    
    if(dado)
        printf("Encontrado na posição %d.\n", dado);
    else
        printf("Dado não encontrado na lista.\n");
    
    printf("Valor %d.\n", visit(list, 3));
    
    printf("\n");

    
    del(&list, 5, &dado);
    print(list);
    printBack(list);
    printf("\n");
    
    del(&list, 1, &dado);
    print(list);
    printBack(list);
    printf("\n");
    
    del(&list, 2, &dado);
    print(list);
    printBack(list);
    printf("\n");
    
    return 0;
}
