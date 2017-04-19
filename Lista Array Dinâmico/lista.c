#include <stdio.h>
#include "lista.h"

int cria(tLista *lista) {
	lista->n = 0;
	return TRUE;
}

int vazio(tLista lista) {
	return lista.n == 0;
}

int tamanho(tLista lista) {
	return lista.n;
}

int acessa(tLista lista, int pos, int *dado) {
	if(pos <= 0 || pos > lista.n)
		return FALSE;

	*dado = lista.dados[pos-1];
	return TRUE;
}

int pesquisa(tLista lista, int dado) {
	if(vazio(lista))
		return -1;

	for(int i = 0; lista.dados[i]; i++)
		if(lista.dados[i] == dado)
			return ++i;

	return FALSE;
}

int insere(tLista *lista, int pos, int dado) {
	if(pos <= 0 || pos > lista->n+1)
		return FALSE;
	
	lista->n++;
	lista->dados = (int *) realloc(lista->dados, lista->n * sizeof(int));
	
	for(int i = lista->n; i >= pos; i--)	
		lista->dados[i] = lista->dados[i-1];
	
	lista->dados[pos-1] = dado;	

	return TRUE;
}

int exclui(tLista *lista, int pos, int *dado) {
	if(pos <= 0 || pos > lista->n)
		return FALSE;

	*dado = lista->dados[pos-1];

	for(int i = --pos; i < lista->n; i++)
		lista->dados[i] = lista->dados[i+1];

	lista->n--;
	lista->dados = (int *) realloc(lista->dados, lista->n * sizeof(int));
	
	return true;
}

int exibe(tLista lista) {
	if(vazio(lista))
		return FALSE;

	printf("\nLista: {");
	for(int i = 0; i < lista.n; i++)
		if((i+1) == lista.n)
			printf("%d}\n", lista.dados[i]);
		else
			printf("%d, ", lista.dados[i]);

	return TRUE;	
}




