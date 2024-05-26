#include <stdio.h>
#include <stdlib.h>

/*
Programa:
-> receber linhas e colunas
-> Crie_Matriz();
-> Preencha_Matriz();
    -> preenche a matriz de acordo com a entrada
-> Cheque_Matriz();
    -> define que posições podem ou não ser ocupadas
    -> para cada '.', checar [i][j+1] (em cima), [i][j-1] (embaixo), [i-1][j] (esquerda) e [i+1][j] (direita)
        -> se o caracter for igual a X, add. 1 a um contador
    -> se a quant. final no contador NÃO for ímpar, trocar '.' por '*'
-> Imprima_Matriz();
*/

char **Crie_Matriz(int linhas, int colunas){
    //ponteiro que aponta para o vetor de ponteiros:
    char **pont_vet_pont;
    pont_vet_pont = (char **)malloc(linhas*sizeof(char *));
    if (pont_vet_pont == NULL){
        printf("Deu ruim aqui\n");
        exit(1);
    }

    //vetor grandão que vai servir de matriz:
    char *pont_matriz;
    pont_matriz = (char *)malloc((linhas*colunas)*sizeof(char));

    //atribuindo cada parte do vetor grandão a um ponteiro do vetor de ponteiros:
    for (int i=0; i<colunas; i++){
        pont_vet_pont[i] = &pont_matriz[i*colunas];
    }

    return pont_vet_pont;
}

void Preencha_Matriz(char **pont_vet_pont, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            scanf(" %c", &pont_vet_pont[i][j]);
        }
    }

    return;
}

int main(void){
    int linhas, colunas;
    scanf(" %d %d", &linhas, &colunas);

    char **pont_vet_pont;
    pont_vet_pont = Crie_Matriz(linhas, colunas);
    //pont_vet_pont agora aponta para o começo do vetor de ponteiros na heap

    Preencha_Matriz(pont_vet_pont, linhas, colunas);

    return 0;
}