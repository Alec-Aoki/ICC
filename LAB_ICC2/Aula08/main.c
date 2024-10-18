/*
- Ordernar as cartas
- Aplicar a busca binária
Como ordenamos as cartas para aplicar a busca binária, "perdemos" seu índice original
Solução:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned long int numero;
    int indiceOriginal;
}NO;

void quicksort(NO v[], int inicio, int fim);
unsigned long int buscaBinaria(unsigned long int v[], int inicio, int fim, unsigned long int chave);

int main(void){
    int quantCartas;
    unsigned long int chave;
    scanf("%d %ld", &quantCartas, &chave);

    NO vetNos[quantCartas];

    for(int i=0; i<quantCartas; i++){
        scanf("%ld", &(vetNos[i].numero));
        vetNos[i].indiceOriginal = i;
    }

    quicksort(vetNos, 0, quantCartas-1);

    /*for(int i=0; i<quantCartas; i++){
        printf("%ld ", vetInt[i]);
    }
    printf("\n");*/

    printf("%ld\n", buscaBinaria(vetInt, 0, quantCartas-1, chave) + 1);

    free(vetInt);

    return 0;
}


unsigned long int buscaBinaria(unsigned long int v[], int inicio, int fim, unsigned long int chave){
    int meio = (inicio + fim)/2;

    if(v[meio] == chave){
        return meio;
    }
    else if(chave > v[meio]){
        return buscaBinaria(v, meio+1, fim, chave);
    }
    else{
        return buscaBinaria(v, inicio, meio-1, chave);
    }
}

void quicksort(NO v[], int inicio, int fim){
    if(fim <= inicio) return;

    int pivot = (inicio + fim)/2;
    NO aux = v[fim];
    v[fim] = v[pivot];
    v[pivot] = aux;
    pivot = fim;

    int i = inicio-1;
    int j = inicio;

    while(j < fim){
        if(v[j].numero < v[fim].numero){
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