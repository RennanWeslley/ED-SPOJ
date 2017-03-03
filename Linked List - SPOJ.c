#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int dado;
    struct elemento *prox;
}tElemento;

typedef struct {
    tElemento *cabeca;
    int tam;
}tLista;

int vazio(tLista);
int tamanho(tLista);
int insereInicio(tLista *, int);
int insereIndx(tLista *, int, int);
int excluiInicio(tLista *);
int excluiIndx(tLista *, int);
int exibe(tLista);

int main() {
    tLista lista;
    lista.cabeca = NULL;
    lista.tam = 0;
    char op;
    int pos;
    int dado;
    
    while(1) {
        //printf("Digite a opção: ");
        scanf(" %c", &op);
        
        switch(op) {
            case 'f':
                //printf("Digite o valor: ");
                scanf(" %d", &dado);
                
                insereIndx(&lista, 0, dado);
                break;
            case 'i':
                //printf("Digite a posição e o valor: ");
                scanf(" %d %d", &pos, &dado);
                
                insereIndx(&lista, pos, dado);
                break;
            case 'r':
                excluiIndx(&lista, 0);
                break;
            case 'd':
                //printf("Digite a posição: ");
                scanf(" %d", &pos);
                
                excluiIndx(&lista, pos);
                break;
            case 'q':
                return 1;
        }
        
        exibe(lista);
        printf("\n");
            
    }
}

int vazio(tLista lista) {
    return lista.tam == 0;
}

int tamanho(tLista lista) {
    return lista.tam;
}

int insereInicio(tLista *lista, int dado) {
    tElemento *p = (tElemento *) malloc(sizeof(tElemento));
    
    p->dado = dado;
    p->prox = lista->cabeca;
    lista->cabeca = p;
    lista->tam++;
    
    return 1;
}

int insereIndx(tLista *lista, int pos, int dado) { 
    if(vazio(*lista) || !pos)
        return insereInicio(lista, dado);
    
    tElemento *p = lista->cabeca;
    
    if(pos >= lista->tam)
        pos = lista->tam;
    
    for(; (pos-1); p = p->prox, pos--);
    
    tElemento *new = (tElemento *) malloc(sizeof(tElemento));
    
    new->dado = dado;
    new->prox = p->prox;
    p->prox = new;
    lista->tam++;
    
    return 1;
}

int excluiInicio(tLista *lista) {
    if(vazio(*lista)) 
        return 0;
    
    tElemento *p = lista->cabeca;
    lista->cabeca = lista->cabeca->prox;
    free(p);
    lista->tam--;
    
    return 1;
}

int excluiIndx(tLista *lista, int pos) {
    if(pos > lista->tam)
        return 0;
    else if(pos == 0)
        return excluiInicio(lista);
    
    tElemento *p = lista->cabeca;
    tElemento *aux;
    
    for(; (pos-1); p = p->prox, pos--);
    
    aux = p->prox->prox;
    free(p->prox);
    p->prox = aux;
    lista->tam--;
    
    return 1;
}

int exibe(tLista lista) {
    if(vazio(lista)) {
        printf("empty");
        return 0;
    }
    
    for(tElemento *p = lista.cabeca; p; p = p->prox)
        printf("%d ", p->dado);
    
    return 1;
}
