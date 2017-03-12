#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int cria(tLista *lista) {
    lista->cabeca = NULL;
    lista->ponta = NULL;
    lista->tam = 0;
    
    return 1;
}

int vazio(tLista lista) {
    return lista.tam == 0;
}

int tam(tLista lista) {
    return lista.tam;
}

int acessa(tLista lista, int pos, int *dado) {
    if(pos < 1 || pos > lista.tam)
        return 0;
    
    tElemento *p;
    
    if(pos > (tam(lista)/2)) {
        pos = (tam(lista)+1) - pos;
        p = lista.ponta;
        
        for(; (pos-1); p = p->ant, pos--);
        
        *dado = p->dado;
    }
    else {
        p = lista.cabeca;
        
        for(; (pos-1); p = p->prox, pos--);
        
        *dado = p->dado;
    }
    
    return 1;
}

int pesquisa(tLista lista, int dado) {
    if(vazio(lista))
        return -1;
    
    int pos = 1;
    for(tElemento *i = lista.cabeca, *j = lista.ponta; pos <= (tam(lista)/2)+1; i = i->prox, j = j->ant, pos++) 
        if(i->dado == dado)
            return pos;
        else if(j->dado == dado)
            return (tam(lista)+1) - pos;
        
    return 0;
}

int insereInicio(tLista *lista, int dado) {
	tElemento *p = lista->cabeca;
    tElemento *new = (tElemento *) malloc(sizeof(tElemento));
    if(!new)
        return 0;
    
    new->dado = dado;
    if(!tam(*lista)) {
    	new->prox = NULL;
    	new->ant = NULL;
    	lista->cabeca = new;
    	lista->ponta = new;
    }
    else {
		new->ant = NULL;
		new->prox = p;
		p->ant = new;
		lista->cabeca = new;
    }
    
    p = lista->cabeca;
	for(; p->prox; p = p->prox);
		lista->ponta = p;
    
    lista->tam++;
    
    return 1;
}

int insereIndx(tLista *lista, int pos, int dado) {
    if(pos < 1 || pos > lista->tam+1)
        return 0;
    if(vazio(*lista) || pos == 1)
        return insereInicio(lista, dado);
    
    tElemento *p = lista->cabeca;
    
    tElemento *new = (tElemento *) malloc(sizeof(tElemento));
    if(!new)
        return -1;
    
    new->dado = dado;
    
    if(pos > tam(*lista)/2) {
        pos = (tam(*lista)+1) - pos;
        p = lista->ponta;
        
        for(; (pos-1) > 0; p = p->ant, pos--);
        
        new->ant = p->ant;
        p->ant->prox = new;
        p->ant = new;
        new->prox = p;
    }
    else {
		for(; (pos-2) > 0; p = p->prox, pos--);
		
		new->prox = p->prox;
		p->prox->ant = new;
		p->prox = new;
		new->ant = p;
    }
        
    lista->tam++;
    
    return 1;
}

int exibe(tLista lista) {
    if(vazio(lista)) {
        printf("\nLista vazia.\n\n");
        return 0;
    }
    
    printf("Lista: {");
    for(tElemento *p = lista.cabeca; p; p = p->prox)
        if(!p->prox)
            printf("%d}\n\n", p->dado);
        else
            printf("%d, ", p->dado);
        
    return 1;
}

//Função para testar o caminho inverso da lista.
int exibeA(tLista lista) {
    if(vazio(lista)) {
        printf("\nLista vazia.\n\n");
        return 0;
    }
    
    printf("Lista: {");
    for(tElemento *p = lista.ponta; p; p = p->ant)
        if(!p->ant)
            printf("%d}\n\n", p->dado);
        else
            printf("%d, ", p->dado);
        
    return 1;
}
