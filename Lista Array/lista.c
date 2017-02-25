#include <stdio.h>
#include "lista.h"

int cria(tLista *lista) {
    lista->n = 0;
    return TRUE;
}

int vazio(tLista lista) {
    return lista.n == 0;
}

int cheio(tLista lista) {
    return lista.n > MAX;
}

int tamanho(tLista lista) {
	return lista.n;
}

int acessa(tLista lista, int pos, int *dado) {
    if(pos < 1 || pos > lista.n)
        return FALSE;

    *dado = lista.dados[pos-1];
    return TRUE;
}

int pesquisa(tLista lista, int dado) {
    if(vazio(lista))
        return -1;

    int i = 1;

    for(int *p = lista.dados; *p; p++, i++)
        if(*p == dado)
            return i;

    return FALSE;
}

int insere(tLista *lista, int pos, int dado) {
    if(cheio(*lista) || pos < 1 || (pos-1) > lista->n)
        return FALSE;

    for(int i = tamanho(*lista)+1; i >= pos; i--)
        lista->dados[i] = lista->dados[i-1];

    lista->dados[pos-1] = dado;
    lista->n++;

    return TRUE;
}

int exclui(tLista *lista, int pos) {
    if(pos < 1 || pos > lista->n)
        return FALSE;

    for(int i = --pos; i < lista->n; i++)
        lista->dados[i] = lista->dados[i+1];

    lista->n--;

    return TRUE;
}

int exibe(tLista lista) {
	if(vazio(lista))
		return FALSE;
		
	printf("Lista: {");
	for(int i = 0; i < tamanho(lista); i++) {
		if((i+1) >= tamanho(lista))
			printf("%d}", lista.dados[i]);
		else
			printf("%d, ", lista.dados[i]);
	}
}
