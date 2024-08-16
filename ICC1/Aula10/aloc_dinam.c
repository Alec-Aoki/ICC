#include <stdio.h>
#include <stdlib.h>

/*EXERCÍCIO
    Fazer um programa que aloca dinamicamente um vetor de doubles com tamanho e elementos determinados pelo usuário

    Leia_Elementos
    Aloque
    Imprima_Valores
*/

/* ALOCAÇÃO DINÂMICA DE MATRIZES
-> alocar vetor de ponteiros que aí sim apontam para onde os valores estão
ex:
double **aloca(int linha, int coluna){
    double **p;
    //alocação do vetor de ponteiros:
    p = (double **)malloc(linha*sizeof(double *));
    //alocação do espaço para os valores
    for (int i=0; i<linha; linha++){
        p[i] = (double *)malloc(coluna*sizeof(double));
    }
}
return p;

obs: para usar a matriz, basta fazer p[i][j]
obs: alocação de matriz de string tem 3 dimensões, sendo uma 2x2 contendo um vetor dentro

ALOCAÇÃO DINÂMICA DE MATRIZES v2
-> alocar o vetor de ponteiros e daí alocar um vetor só para os valores, dividindo ele no número de colunas
-> aí chamamos o malloc só duas vezes, em vez da várias vezes dentro de um for
ex:
double **aloca(int linha, int coluna){
    double **p;
    p = (double **)malloc(linha*sizeof(double *));
    double *v;
    v = (double *)malloc((linha*coluna)*sizeof(double));
    for (int i=0; i<linha; i++){
        p[i] = &v[i*coluna]; // <=> p[i] = v + (i*coluna);  (aritmética de ponteiros)
    }

    return p;
}
*/

/* DESALOCAÇÃO
-> temos que desalocar o ponteiro que aponta para a matriz e o ponteiro que aponta para o vetor de ponteiros 
*/

double *Aloque(int tam){
    //como vamos retornar um endereço (ponteiro), temos que declarar a função como um ponteiro
    double *vetor_Aloque;
    vetor_Aloque = (double *) calloc(tam, sizeof(double));
    if (vetor_Aloque == NULL){
        printf("Falta de memoria\n");
        exit(1);
    }
    return vetor_Aloque;
}

void Leia_Elementos(double *vetor_Leia, int tam){
    for (int i=0; i<tam; i++){
        scanf(" %lf", &vetor_Leia[i]);
    }
    return;
}

void Imprima_Valores(double *vetor_Imprima, int tam){
    for (int i=0; i<tam; i++){
        printf("%lf ", vetor_Imprima[i]);
    }
    printf("\n");
    return;
}

int main (void){
    double *vetor_main;
    int tam;
    scanf(" %d", &tam);

    vetor_main = Aloque(tam);

    Leia_Elementos(vetor_main, tam);

    /* !!!!!!!
    o ponteiro vetor_main está guardando o endereço das variáveis na heap
    como não queremos mudar o que o vetor_main está guardando, não vamos passar ele por referência, mas por valor
    */

    Imprima_Valores(vetor_main, tam);
    free(vetor_main); //sempre libere a memória!!!
    vetor_main = NULL;

    return 0;
}