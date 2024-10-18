/*
- Ordernar as cartas
- Aplicar a busca binária
Como ordenamos as cartas para aplicar a busca binária, "perdemos" seu índice original
Solução:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int numero;
    int indiceOriginal;
}NO;

void quicksort(NO v[], int inicio, int fim);
int buscaBinaria(NO v[], int inicio, int fim, int chave);

int main(void){
    int quantCartas;
    int chave;
    scanf("%d %d", &quantCartas, &chave);

    NO vetNos[quantCartas];

    for(int i=0; i<quantCartas; i++){
        scanf("%d", &(vetNos[i].numero));
        vetNos[i].indiceOriginal = i;
    }

    quicksort(vetNos, 0, quantCartas-1);

    /*for(int i=0; i<quantCartas; i++){
        printf("%ld ", vetInt[i]);
    }
    printf("\n");*/

    //printf("%d\n", buscaBinaria(vetNos, 0, quantCartas-1, chave) + 1);

    free(vetNos);

    return 0;
}


int buscaBinaria(NO v[], int inicio, int fim, int chave){
    int meio = (inicio + fim)/2;

    if(v[meio].numero == chave){
        return v[meio].indiceOriginal;
    }
    else if(chave > v[meio].numero){
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