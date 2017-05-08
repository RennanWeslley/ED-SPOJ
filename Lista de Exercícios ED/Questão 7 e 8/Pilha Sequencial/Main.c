/*
 *  Main.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Pilha.h"

int main() {
    int data;
    tStack stack;
    init(&stack);
    
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 4);
    push(&stack, 5);
    
//  F
    
    print(stack);
    
    printf("\n");
    
//  G
    
    invert(&stack);
    print(stack);
    
    printf("Invertendo de volta:\n");
    invert(&stack);
    print(stack);
    
    printf("\n");
    
//  H
    
    data = popValue(&stack, 4);
    
    data? printf("Valor informado eliminado %d vezes, nova pilha:\n", data) : printf("Valor não encontrado na pilha\n");
    
    print(stack);
    
    pop(&stack);
    printf("Adicionado novamente o valor 4.\n");
    push(&stack, 4);
    /* print(stack); */
    push(&stack, 5);
    
    printf("\n");
    
//  I
    
    tStack stack2;
    init(&stack2);
    stack2 = stack;
    
    /* push(&stack2, 6); */
    
    data = equals(stack, stack2);
    
    data? printf("Pilhas iguais\n") : printf("Pilhas Diferentes\n");
    
    printf("\n");
    
//  J
    
    destroy(&stack);
    empty(stack)? printf("Pilha destruída com sucesso\n") : printf("Falha na destruição da pilha\n");
    
    printf("\n");
    
    return 0;
}