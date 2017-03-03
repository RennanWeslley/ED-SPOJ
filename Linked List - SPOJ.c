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
int insere(tLista *, int, int);
int exclui(tLista *, int);
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
                
                insere(&lista, 0, dado);
                break;
            case 'i':
                //printf("Digite a posição e o valor: ");
                scanf(" %d %d", &pos, &dado);
                
                insere(&lista, pos, dado);
                break;
            case 'r':
                exclui(&lista, 0);
                break;
            case 'd':
                //printf("Digite a posição: ");
                scanf(" %d", &pos);
                
                exclui(&lista, pos);
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

int insere(tLista *lista, int pos, int dado) { 
	tElemento *new = (tElemento *) malloc(sizeof(tElemento));
	
    if(vazio(*lista) || !pos) {
		new->dado = dado;
		new->prox = lista->cabeca;
		lista->cabeca = new;
		lista->tam++;
		
		return 1;
    }
    
    tElemento *p = lista->cabeca;
    
    if(pos >= lista->tam)
        pos = lista->tam;
    
    for(; (pos-1); p = p->prox, pos--);
    
    new->dado = dado;
    new->prox = p->prox;
    p->prox = new;
    lista->tam++;
    
    return 1;
}

int exclui(tLista *lista, int pos) {
    if(pos > lista->tam || vazio(*lista))
        return 0;
    
    tElemento *p = lista->cabeca;
    
    if(pos == 0) {
		lista->cabeca = lista->cabeca->prox;
		free(p);
		lista->tam--;
		
		return 1;
    }
    
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
