#include <stdio.h>

void selectionSort(int v[], int tam){
    int posicao_menor = 0, aux;

    for(int i=0; i<tam-1; i++){
        posicao_menor = i;

        for(int j=i+1; j<tam; j++){
            if(v[j] < v[posicao_menor]){
                posicao_menor = j;
            }
        }

        if(posicao_menor != i){
            aux = v[i];
            v[i] = v[posicao_menor];
            v[posicao_menor] = aux;
        }
    }
}

int main(void){
    int v[7] = {6,5,4,7,8,3,2};

    selectionSort(v, 7);

    for(int i=0; i<6; i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[6]);

    return 0;
}