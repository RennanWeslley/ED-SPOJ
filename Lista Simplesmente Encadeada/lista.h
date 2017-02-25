#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int dado;
    struct no *prox;
}tElemento;

typedef struct {
    tElemento *cabeca;
    int tam;
}tLista;

int criaLista(tLista *);
int vazio(tLista);
int tamanho(tLista);
int acessa(tLista, int, int *);
int pesquisa(tLista, int);
int insereInicio(tLista *, int);
int insereIndx(tLista *, int, int);
int insere(tLista *, int);
int excluiInicio(tLista *);
int excluiIndx(tLista *, int);
int exclui(tLista *, int);
int exibe(tLista);

#endif //LISTA_H
