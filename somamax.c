#include <stdio.h>
#define MIN 3
#define MAX 20

int somamax(short int n,  int *vet, short int *ini, short int *fim){
    int max_final= 0;
    int max_atual;
    short int i, j;
    short int cont= 0;
    for(i=0; i<n; i++){
        max_atual= 0;
        for(j=i; j<n; j++){
            if((*ini==0) && (*fim==n-1))
                break;
            max_atual+= vet[j];
            cont++;
            if(max_atual>max_final){
                max_final= max_atual;
                *ini= i;
                *fim= j;
            }
        }
        
    }
    printf("Somas: %d\n", cont);
    return max_final;
}

int main(){
    short int n, i, indice_inical, indice_final;
    int max_final;
    do{
        printf("Insira o tamanho do vetor, entre %d e %d: ", MIN, MAX);
        scanf("%hi", &n);
    }while(n<MIN || n>MAX);
    int vet[n];
    printf("Insira os %d valores separados por espaco: ", n);
    for(i=0; i<n; i++)
        scanf("%d", &vet[i]);
    max_final= somamax(n, vet, &indice_inical, &indice_final);
    if(max_final>0)
        printf("Soma: %d\nIndices: %hi a %hi\n", max_final, indice_inical+1, indice_final+1);
    else
        printf("Soma: %d", max_final);
    return 0;
}
