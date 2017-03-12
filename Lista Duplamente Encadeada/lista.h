#ifndef LISTA_H
#define LISTA_H

typedef struct elemento {
    int dado;
    struct elemento *prox;
    struct elemento *ant;
}tElemento;

typedef struct {
    tElemento *cabeca;
    tElemento *ponta;
    int tam;
}tLista;

int cria(tLista *);
int vazio(tLista);
int tam(tLista);
int acessa(tLista, int, int *);
int pesquisa(tLista, int);
int insereInicio(tLista *, int);
int insereIndx(tLista *, int, int);
int insere(tLista *, int);
int excluiInicio(tLista *, int *);
int excluiIndx(tLista *, int, int *);
int exclui(tLista *, int *);
int exibe(tLista);
int exibeA(tLista);

#endif //LISTA_H
