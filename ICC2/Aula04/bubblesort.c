#include <stdio.h>

/*Bubblesort melhorado*/
void bubblesort(int v[], int tam){
    for(int i=0; i<tam; i++){
        int trocas = 0;

        for(int j=1; j<tam-i; j++){
            if(v[j] < v[j-1]){
                int aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;

                trocas++;
            }
        }

        if(trocas == 0) return;
    }

    return;
}

int main(void){
    int v[] = {4,6,3,1,3,9,-1,7,0};

    bubblesort(v, 9);

    for(int i=0; i<9; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}