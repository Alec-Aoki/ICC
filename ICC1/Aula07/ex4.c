#include <stdio.h>

/*
Faça um programa que leia caracteres fornecidos pelo usuário e os armazene em um vetor.
Reverta o vetor do centro para as extremidades e imprima o conteúdo. Exemplo: “abcde”
ficaria “cbdae” ou “cdbea”.
*/

int main(void){

    int n=5, cont=0;

    char poggers[n], aux[n];

    for (int i=0; i<n; i++){
        scanf(" %c", &poggers[i]);
    }

    printf("\n");

    aux[cont] = poggers[(n/2)];

    cont++;

    for (int j=1; j<=(n/2)+1; j++){
        aux[cont] = poggers[(n/2)-j];
        aux[cont+1] = poggers[(n/2)+j];
        cont = cont+2;
    }

    for (int i=0; i<n; i++){
        printf("%c\n", aux[i]);
    }

    printf("\n");

    cont = 0;

    aux[cont] = poggers[(n/2)];

    cont++;

    for (int j=1; j<=(n/2)+1; j++){
        aux[cont] = poggers[(n/2)+j];
        aux[cont+1] = poggers[(n/2)-j];
        cont = cont+2;
    }

    for (int i=0; i<n; i++){
        printf("%c\n", aux[i]);
    }

    return 0;
}