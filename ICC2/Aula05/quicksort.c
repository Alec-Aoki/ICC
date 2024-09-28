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


    return;
}