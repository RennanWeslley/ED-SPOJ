#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int m;
    int flag;
    
    //Digite a quantidade de elementos da primeira sequencia.
    scanf(" %d", &n);
    
    int *p1 = (int *) malloc(n * sizeof(int));
    
    for(int i = 0; i < n; i++) 
        //Digite o n-ésimo elemento.
        scanf(" %d", &p1[i]);
    
    //Digite a quantidade de elementos da segunda sequencia.
    scanf(" %d", &m);
    
	int *p2 = (int *) malloc(m * sizeof(int));
    
    for(int i = 0; i < m; i++)
        //Digite o m-ésimo elemento.
        scanf(" %d", &p2[i]);

    for(int i = 0; i < n; i++) {
        flag = 1; //Inicia o flag como true a cada iteração.
        
        for(int j = 0; j < m; j++)
        //Se o número for menor, por se tratar de sequencias ordenadas, o mesmo não está presente em ambas as listas ao mesmo tempo. 
            if(p1[i] < p2[j]) {
                flag = 0;
                printf(" %2d ", p1[i]);
                break; //Saída do laço para evitar comparações desnessárias.
            }
            else if(p1[i] == p2[j]) { //Se o número tiver presente nas duas, flag é setado para false.
                flag = 0;
                break; //Saída do laço para evitar comparações desnessárias.
            }
        
        
        if(flag) //Exibe o valor dependendo da flag.
            printf(" %2d ", p1[i]);
    }
            
    return 0;
}
