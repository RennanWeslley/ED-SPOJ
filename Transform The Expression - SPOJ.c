#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
}tNode;

typedef struct {
    tNode *top;
}tStack;

int push(tStack *, char);
char pop(tStack *);

int main() {
    tStack stack;
    stack.top = NULL;
    
	int t;
    int j = 0;
	char exp[400], final[400];
	
	scanf(" %d", &t);
	
	do{
		j = 0;
        
        scanf(" %s", exp);
		
		for(int i = 0; i < strlen(exp); i++) {
            if(exp[i] != '(') {
                switch(exp[i]) {
                    case '^':
                    case '*':
                    case '/':
                    case '+':
                    case '-':
                        push(&stack, exp[i]);
                        break;
                        
                    case ')':
                        final[j] = pop(&stack);
                        j++;
                        final[j] = '\0';
                        break;
                        
                    default:
                        final[j] = exp[i];
                        j++;
                        break;
                }
            }
        }
        
        printf("%s\n", final);
        
	}while(--t);
    
    return 0;
}

int push(tStack *stack, char data) {
    tNode *new = (tNode *) malloc(sizeof(tNode));
    
    new->data = data;
    new->next = stack->top;
    stack->top = new;
    
    return 1;
}

char pop(tStack *stack) {
    tNode *p = stack->top;
    char data = p->data;
    
    stack->top = stack->top->next;
    free(p);
    
    return data;
}