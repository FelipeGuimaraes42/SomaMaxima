#include <stdio.h>
#define MIN 3
#define MAX 20

int somamax(short int n,  int *vet, short int *ini, short int *fim){
    //max_final é o valor a ser retornado e max_atual é a soma total daquele laço
    int max_final= 0;
    int max_atual;
    short int i, j;
    for(i=0; i<n; i++){
        max_atual= 0;
        for(j=i; j<n; j++){
            //Se os índices da soma máxima são os extremos, não há necessidade de calcular outras somas
            if((*ini==0) && (*fim==n-1))
                break;
            max_atual+= vet[j];
            if(max_atual>max_final){
                max_final= max_atual;
                *ini= i;
                *fim= j;
            }
        }
        
    }
    return max_final;
}

int main(){
    short int n, i, indice_inical, indice_final;
    int max_final;
    //Faz a validação da entrada
    do{
        printf("\nInsira o tamanho do vetor, entre %d e %d: ", MIN, MAX);
        scanf("%hi", &n);
    }while(n<MIN || n>MAX);
    int vet[n];
    printf("\nInsira os %d valores separados por espaco: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);
    max_final= somamax(n, vet, &indice_inical, &indice_final);
    if(max_final>0)
        printf("\nSoma: %d\nIndices: %hi a %hi\n\n", max_final, indice_inical+1, indice_final+1);
    else
        printf("\nSoma: %d\n\n", max_final);
    return 0;
}
