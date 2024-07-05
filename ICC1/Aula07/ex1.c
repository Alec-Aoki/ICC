#include <stdio.h>

/*
 Desenvolva um programa que encontre o maior elemento em um vetor com n números reais,
positivos. n e os elementos devem ser fornecidos pelo usuário em uma etapa anterior à
procura pelo maior elemento. Imprima o maior elemento.
*/

int main(void){

    int n, vet[20];

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    for (int j=1; j<n; j++){
        if (vet[j] <= vet[j-1]){
            vet[j] = vet[j-1];
        }
    }

    printf("%d\n", vet[n-1]);

    return 0;
}