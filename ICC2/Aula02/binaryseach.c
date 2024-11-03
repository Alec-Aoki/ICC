#include <stdio.h>

#define ERRO -1

int binarySearch(int v[], int inicio, int fim, int chave){
    if(inicio > fim) return ERRO;

    int meio = (inicio + fim)/2;

    if(v[meio] == chave){
        return meio;
    }
    else if(chave < v[meio]){
        return binarySearch(v, inicio, meio-1, chave);
    }
    else{
        return binarySearch(v, meio+1, fim, chave);
    }
}

int main(void){
    int v[] = {1, 2, 3, 5, 6, 7, 15, 18, 24, 34, 43, 423, 3323};

    for(int i=0; i<=12; i++){
        int posicaoRes = binarySearch(v, 0, 12, v[i]);
        printf("%d\n", v[posicaoRes]);
    }

    return 0;
}