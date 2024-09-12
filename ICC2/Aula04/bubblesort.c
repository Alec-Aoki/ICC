#include <stdio.h>

/*Bubblesort melhorado*/

void bubblesort(int v[], int tam){
    int aux;

    for(int i=0; i<tam; i++){
        for(int j=0; j<(tam-1)-i; j++){
            int trocas = 0;
            
            if(v[j] > v[j+1]){
                trocas++;
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }

            if(trocas == 0) return;
        }
    }

    return;
}

int main(void){
    int v[] = {4,6,8,1,3,9,-1,7,0};

    bubblesort(v, 9);

    for(int i=0; i<9; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}