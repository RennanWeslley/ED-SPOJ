/*
 *  Main.c
 *
 *  Created on: May 8th, 2017.
 *  Author: Rennan Weslley
 */

#include "Pilha Encadeada/Pilha.h"
#include <string.h>
#include <ctype.h>

int main() {
    tStack stack;
    char string[150];
    
    printf("Type a string: ");
    fgets(string, 150, stdin);
    string[strlen(string)-1] = '\0';
    
    for(int i = 0; i < strlen(string); i++)
        string[i] = tolower(string[i]);
    
    init(&stack);
    
    char aux1[150];
    int j = 0;
    
    for(int i = 0; i < strlen(string); i++) 
        switch(string[i]) {
            case '.':   case '!':   case '%':
            case '-':   case '@':   case '&':
            case ':':   case '#':   case ' ':
            case '_':   case '$':   case ',':
                break;
                
            default:
                aux1[j++] = string[i];
                push(&stack, string[i]);
        }
    
    char aux2[150];
    for(int i = 0; !empty(stack); aux2[i] = pop(&stack), i++);
    
    if(!strcmp(aux1, aux2))
        printf("Is palindrome\n");
    else
        printf("Isn't palindrome\n");
    
    return 0;
}
