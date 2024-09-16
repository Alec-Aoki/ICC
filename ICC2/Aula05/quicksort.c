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
    if(inicio == fim) return;
    
    int pivot = (inicio + fim)/2;
    int aux;
    int i=inicio, j=fim;

    while((i < j) && (j > i)){
        
        while(v[i] < v[pivot]){
            i++;
        }
        while(v[j] > v[pivot]){
            j--;
        }

        if((i<=j) && (j>=i)){
            aux = v[j];
            v[j] = v[i];
            v[i] = aux;
            i++;
            j--;
        }

    }

    quicksort(v, inicio, j);
    quicksort(v, i, fim);

    return;
}