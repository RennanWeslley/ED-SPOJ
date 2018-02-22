/*
*	Universidade Federal da Paraíba - UFPB
*	Sanidade 8o Contest Noturno - SPOJ
*	Autor: Rennan Weslley
*	Matr : 11515025
*	Data : 15/03/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	unsigned long long int id;
	unsigned long long int prox;
	unsigned long long int ant;
}tNo;

int main() {
	tNo ptr1, ptr2;
	tNo *atual = (tNo *) malloc(sizeof(tNo));
	int cont = 0;
	int flag;
	
	unsigned long long int id, ant, prox;
	
	//LEITURA
	//Lendo os nós até que as variáveis alteradas pelo scanf seja diferente de 3.
	while(scanf(" %llx %llx %llx", &id, &ant, &prox) == 3) {
		cont++;
		atual = (tNo *) realloc(atual, cont * sizeof(tNo));
		
		atual[cont-1].id = id;
		atual[cont-1].ant = ant;
		atual[cont-1].prox = prox;
		
		//Setando o PTR1 e o PTR2 dependendo do valor de cont
		if(cont == 1)
			ptr1 = atual[cont-1];
		else if(cont == 2)
			ptr2 = atual[cont-1];	
	}
	//LEITURA
	
	//COMPARAÇÃO
	for(tNo aux = ptr1; aux.id != ptr2.id;) {
		flag = 0; //Partindo do princípio de que a lista é insana.
		for(int i = 0; i < cont; i++) {
			//Verifica se o anterior do próximo é igual ao atual.
			if(aux.prox == atual[i].id && atual[i].ant == aux.id) {
				aux = atual[i];
				flag = 1; //Se um valor deu "match", logo a lista ainda não pode ser considerada insana.
				break;
			}		
		}
		if(!flag) //Se flag continuar 0, a lista é de fato insana.
			break;
	}
	//COMPARAÇÃO
		
	if(flag)
		printf("sana\n");
	else
		printf("insana\n"); 
	
	return 0;
}
