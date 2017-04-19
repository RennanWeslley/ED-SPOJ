#include <stdlib.h>

#ifndef LISTA_H
#define LISTA_H

#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct lista {
	int *dados = (int *) malloc(sizeof(int));
	int n;
} tLista;

int cria(tLista *);
int vazio(tLista);
int tamanho(tLista);
int acessa(tLista, int, int *);
int pesquisa(tLista, int);
int insere(tLista *, int, int);
int exclui(tLista *, int, int *);
int exibe(tLista);

#endif //LISTA_H
