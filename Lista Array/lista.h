#ifndef LISTA_H
#define LISTA_H

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    int dados[MAX];
    int n;
}tLista;

int cria(tLista *);
int vazio(tLista);
int cheio(tLista);
int tamanho(tLista);
int acessa(tLista, int, int *);
int pesquisa(tLista, int);
int insere(tLista *, int, int);
int exclui(tLista *, int);
int exibe(tLista);

#endif // LISTA_H
