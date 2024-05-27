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
        -> obs: como não podemos invadir memória, vamos ter que verificar se o X está na borda e agir de acordo
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
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            scanf(" %c", &pont_vet_pont[i][j]);
        }
    }
    return;
}

void Cheque_Matriz(char **pont_vet_pont, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            if (pont_vet_pont[i][j] == 'X'){
                //verificando se X está na borda pelo i:
                if (i==0){
                    //não podemos acessar [i-1][j]
                    if (pont_vet_pont[i+1][j] == '.'){
                        pont_vet_pont[i+1][j] = '1'; 
                    }
                    else if (pont_vet_pont[i+1][j] != 'X'){
                        pont_vet_pont[i+1][j]++;
                    }
                }
                else if (i==(linhas-1)){
                    //não podemos acessar [i+1][j]
                    if (pont_vet_pont[i-1][j] == '.'){
                        pont_vet_pont[i-1][j] = '1'; 
                    }
                    else if (pont_vet_pont[i-1][j] != 'X'){
                        pont_vet_pont[i-1][j]++;
                    }
                }
                else {
                    //podemos acessar [i+1][j] e [i-1][j]
                    if (pont_vet_pont[i+1][j] == '.'){
                        pont_vet_pont[i+1][j] = '1'; 
                    }
                    else if (pont_vet_pont[i+1][j] != 'X'){
                        pont_vet_pont[i+1][j]++;
                    }
                    if (pont_vet_pont[i-1][j] == '.'){
                        pont_vet_pont[i-1][j] = '1'; 
                    }
                    else if (pont_vet_pont[i-1][j] != 'X'){
                        pont_vet_pont[i-1][j]++;
                    }
                }
                //verificando se X está na borda pelo j:
                if (j==0){
                    //não podemos acessar [i][j-1]
                    if (pont_vet_pont[i][j+1] == '.'){
                        pont_vet_pont[i][j+1] = '1'; 
                    }
                    else if (pont_vet_pont[i][j+1] != 'X'){
                        pont_vet_pont[i+1][j]++;
                    }
                }
                else if (j==(colunas-1)){
                    //não podemos acessar [i][j+1]
                    if (pont_vet_pont[i][j-1] == '.'){
                        pont_vet_pont[i][j-1] = '1'; 
                    }
                    else if (pont_vet_pont[i][j-1] != 'X'){
                        pont_vet_pont[i-1][j]++;
                    }
                }
                else {
                    //podemos acessar [i][j-1] e [i][j+1]
                    if (pont_vet_pont[i][j+1] == '.'){
                        pont_vet_pont[i][j+1] = '1'; 
                    }
                    else if (pont_vet_pont[i][j+1] != 'X'){
                        pont_vet_pont[i+1][j]++;
                    }
                    if (pont_vet_pont[i][j-1] == '.'){
                        pont_vet_pont[i][j-1] = '1'; 
                    }
                    else if (pont_vet_pont[i][j-1] != 'X'){
                        pont_vet_pont[i-1][j]++;
                    }
                }
            }
        }
    }
    return;
}

void Imprima_Matriz(char **pont_vet_pont, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            if (j!=(colunas-1)){
                printf("%c", pont_vet_pont[i][j]);
            }
            else {
                printf("%c\n", pont_vet_pont[i][j]);
            }
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

    Cheque_Matriz(pont_vet_pont, linhas, colunas);

    Imprima_Matriz(pont_vet_pont, linhas, colunas);

    free(*pont_vet_pont);
    free(pont_vet_pont);
    return 0;
}