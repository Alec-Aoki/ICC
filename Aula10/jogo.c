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
    -> se acharmos um X, vamos verificar [i][j-1], [i][j+1], [i-1][j] e [i+1][j]
        -> se uma dessas posições for um '.', vamos o trocar por '1'
        -> se essa posição não for '.' ou um 'X' (ou seja, é um número), vamos somar 1 a seu valor
    -> vamos passar pela matriz novamente
        -> se o caractere for diferente de '.' ou 'X' (ou seja, é um número), vamos verificar sua paridade
            -> se for par, trocar por '*'
            -> se for ímpar, trocar por '.'
    -> note que, usando esse método, teríamos uma invasão de memória nas bordas da matriz
    -> para corrigir isso, vamos somar 1 à quantidade de colunas e linhas antes de qualquer operação
    -> criamos assim o espaço necessário para fazer essas alterações sem ter que levar em conta cada exceção
    -> como adicionamos uma linha para cima e para baixo, e uma coluna para a esquerda e a direita, sempre que usarmos os...
    -> ...índices na matriz vamos ter que somar 1 a [i] e [j], para pegarmos somente a parte da matriz que queremos...
    -> ... (isto é, o centro dela, ou seja, a matriz original)
-> Imprima_Matriz();
*/

char **Crie_Matriz(int linhas, int colunas){
    //ponteiro que aponta para o vetor de ponteiros:
    char **pont_vet_pont;
    pont_vet_pont = (char **)malloc(linhas*sizeof(char *));
    if (pont_vet_pont == NULL){
        exit(1);
    }

    //vetor grandão que vai servir de matriz:
    char *pont_matriz;
    pont_matriz = (char *)malloc((linhas*colunas)*sizeof(char));
    if (pont_matriz == NULL){
        exit(1);
    }

    //atribuindo cada parte do vetor grandão a um ponteiro do vetor de ponteiros:
    for (int i=0; i<colunas; i++){
        pont_vet_pont[i] = &pont_matriz[i*colunas];
    }

    return pont_vet_pont;
}

void Preencha_Matriz(char **pont_vet_pont, int linhas, int colunas){
    for (int i=0; i<(linhas-2); i++){
        for (int j=0; j<(colunas-2); j++){
            scanf(" %c", &pont_vet_pont[i+1][j+1]);
        }
    }
    return;
}

void Cheque_Matriz(char **pont_vet_pont, int linhas, int colunas){
    for (int i=0; i<(linhas-2); i++){
        for (int j=0; j<(colunas-2); j++){
            if(pont_vet_pont[i+1][j+1] == 'X'){
                printf("X em %d %d\n", i, j);
                //[i][j-1]:
                if(pont_vet_pont[i+1][j]=='.'){
                    pont_vet_pont[i+1][j] = '1';
                }
                else if ((pont_vet_pont[i+1][j]!='.') && (pont_vet_pont[i+1][j]!='X')){
                    pont_vet_pont[i+1][j]++;
                }
                //[i][j-1]:
                if(pont_vet_pont[i+1][j+2]=='.'){
                    pont_vet_pont[i+1][j+2] = '1';
                }
                else if ((pont_vet_pont[i+1][j+2]!='.') && (pont_vet_pont[i+1][j+2]!='X')){
                    pont_vet_pont[i+1][j+2]++;
                }
                //[i-1][j]:
                if(pont_vet_pont[i][j+1]=='.'){
                    pont_vet_pont[i][j+1] = '1';
                }
                else if ((pont_vet_pont[i][j+1]!='.') && (pont_vet_pont[i][j+1]!='X')){
                    pont_vet_pont[i][j+1]++;
                }
                //[i+1][j]:
                if(pont_vet_pont[i+2][j+1]=='.'){
                    pont_vet_pont[i+2][j+1] = '1';
                }
                else if ((pont_vet_pont[i+2][j+1]!='.') && (pont_vet_pont[i+2][j+1]!='X')){
                    pont_vet_pont[i+2][j+1]++;
                }
            }
        }
    }
}

int main(void){
    int linhas, colunas;
    scanf(" %d %d", &linhas, &colunas);
    linhas += 2;
    colunas += 2;

    char **pont_vet_pont;
    pont_vet_pont = Crie_Matriz(linhas, colunas);
    //pont_vet_pont agora aponta para o começo do vetor de ponteiros na heap

    Preencha_Matriz(pont_vet_pont, linhas, colunas);

    printf("Entrando cheque\n");
    Cheque_Matriz(pont_vet_pont, linhas, colunas);
    printf("Cheque feito\n");

    for (int i=0; i<(linhas-2); i++){
        for (int j=0; j<(colunas-2); j++){
            if ((j+1)!=(colunas-2)){
                printf("%c", pont_vet_pont[i+1][j+1]);
            }
            else {
                printf("%c\n", pont_vet_pont[i+1][j+1]);
            }
        }
    }

    return 0;
}