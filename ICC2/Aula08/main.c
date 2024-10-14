#include <stdio.h>

#define tam 8

void contagem_menores(int mainVet[], int tamanho);

int main(void){
    int v[] = {12, 92, 33, 25, 86, 57, 37, 48};

    contagem_menores(v, tam);

    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

void contagem_menores(int mainVet[], int tamanho){
    int auxVet_1[tamanho], auxVet_2[tamanho];

    /*contando os menores*/
    for(int i=0; i<tamanho; i++){
        auxVet_2[i] = mainVet[i];
        //copiando o vetor principal no vet2

        int quantMenores = 0;
        for(int j=0; j<tamanho; j++){
            if(mainVet[j] < mainVet[i]) quantMenores++;
        }
        auxVet_1[i] = quantMenores;
    }

    /*copiando de volta no vetor principal*/
    for(int i=0; i<tamanho; i++){
        mainVet[auxVet_1[i]] = auxVet_2[i];
    }

    return;
}