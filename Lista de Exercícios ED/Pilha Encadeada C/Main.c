#include "Pilha.h"

int main() {
    tStack stack;
    init(&stack);
    
    push(&stack, 1);
    print(stack);
    
    push(&stack, 2);
    print(stack);
    
    push(&stack, 3);
    print(stack);
    
    push(&stack, 4);
    print(stack);
    
    push(&stack, 5);
    print(stack);
    
    pop(&stack);
    print(stack);
    
    pop(&stack);
    print(stack);
    
    pop(&stack);
    print(stack);
    
    pop(&stack);
    print(stack);
    
    return 0;
}