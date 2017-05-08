#include "Pilha Encadeada/Pilha.h"
#include <string.h>

int main() {
    tStack stack;
    char exp[30];
    
    init(&stack);
    
    printf("Type the expression: ");
    scanf(" %s", exp);
    
    for(int i = 0; i < strlen(exp); i++)
        switch(exp[i]) {
            case '(':
            case '[':
            case '{':
                push(&stack, exp[i]);
                break;
                
            case ')':
                if((exp[i]-1) != top(stack)) {
                    printf("Isn't a valid expression\n");
                    return 0;
                }
                
                pop(&stack);
                break;
                
            case ']':
            case '}':
                if((exp[i]-2) != top(stack)) {
                    printf("Isn't a valid expression\n");
                    return 0;
                }
                
                pop(&stack);
                break;   
        }
        
        printf("Is a valid expression\n");
        
        return 0;
}