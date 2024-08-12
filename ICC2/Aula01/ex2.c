#include <stdio.h>

/*Função recursiva que some todos os elementos de um vetor*/

int somaElementos(int v[], int i){
    if(i == 1)
        return v[0]; //somaElementos = v[0];
    
    return (v[i-1] + somaElementos(v, i-1));
}

int main(void){
    int v[] = {1, 2, 3, 4};

    printf("%d\n", somaElementos(v, 4));

    return 0;
}