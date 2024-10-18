/*
- Ordernar as cartas
- Aplicar a busca binária
*/
#include <stdio.h>
#include <stdlib.h>

void quicksort(unsigned long int v[], int inicio, int fim);

int main(void){
    int quantCartas, chave;
    scanf("%d %d", &quantCartas, &chave);

    unsigned long int *vetInt = (unsigned long int *)malloc(quantCartas * sizeof(unsigned long int));
    if(vetInt == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i=0; i<quantCartas; i++){
        scanf("%ld", &vetInt[i]);
        /* Hehehehe
        if(vetInt[i] == chave){
            printf("%d\n", i);
            return 0;
        }
        */
    }

    quicksort(vetInt, 0, quantCartas-1);

    for(int i=0; i<quantCartas; i++){
        printf("%ld ", vetInt[i]);
    }
    printf("\n");

    free(vetInt);

    return 0;
}

void quicksort(unsigned long int v[], int inicio, int fim){
    if(fim <= inicio) return; //caso base

    int pivot = (inicio + fim)/2;
    unsigned long int aux = v[fim];
    v[fim] = v[pivot];
    v[pivot] = aux;
    pivot = fim;

    int i = inicio-1;
    int j = inicio;

    while(j < fim){
        if(v[j] < v[fim]){
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }

        j++;
    }
    
    i++;
    aux = v[pivot];
    v[pivot] = v[i];
    v[i] = aux;

    quicksort(v, inicio, i-1);
    quicksort(v, i+1, fim);

    return;
}