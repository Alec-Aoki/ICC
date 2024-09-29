#include <stdio.h>
#include <stdlib.h>

void quicksort(int v[], int inicio, int fim);

int main(void){
    int v[] = {25, 33, 35, 12, 37, 86, 92, 57};

    quicksort(v, 0, 7);

    for(int i=0; i<8; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int v[], int inicio, int fim){
    if(fim <= inicio) return; //caso base

    int pivot = (inicio + fim)/2;
    int aux = v[fim];
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