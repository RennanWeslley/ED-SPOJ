 /*
 *  Main.c
 *
 *  Created on: May 6th, 2017.
 *  Author: Rennan Weslley
 */

#include "Lista Dinamica.h"
#include <stdio.h>

int main() {
    tList list;
    
    init(&list);
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    
    insert(&list, 1, 2);
    print(list);
    
    insert(&list, 2, 3);
    print(list);
    
    insert(&list, 1, 1);
    print(list);
    
    insert(&list, 4, 4);
    print(list);
    
    insert(&list, 30, 5);
    print(list);
    
    /* empty(list)? printf("Sim\n") : printf("Não\n"); */
    
    printf("\n");
    
    int dado = search(list, 6);
    
    if(dado)
        printf("Encontrado na posição %d.\n", dado);
    else
        printf("Dado não encontrado na lista.\n");
    
    printf("Valor %d.\n", visit(list, 5));
    
    del(&list, 5, &dado);
    print(list);
    
    del(&list, 1, &dado);
    print(list);
    
    del(&list, 2, &dado);
    print(list);
    
    return 0;
}
