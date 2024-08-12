#include <stdio.h>

/*Função recursiva para achar o maior elemento em um vetor*/

int maiorElemento(int v[], int i){
    if(i == 1)
        return v[0];

    int aux = maiorElemento(v, i-1); //checa o elemento anterior

    if(aux > v[i-1])
        return aux;
    else
        return v[i-1];
}

int main(void){
    int v[] = {3, 2, 5, 4, 2, 1, 1};

    printf("%d\n", maiorElemento(v, 7));

    return 0;
}