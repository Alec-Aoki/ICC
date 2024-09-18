#include <stdio.h>

/*
A primeira linha da entrada possui a dimens˜ao da matriz a ser lida, com N linhas e M colunas.
• As N linhas seguintes contˆem M valores, que podem ser ”c” para cosplayer, ”f” para f˜a sem
cosplay e ”v” para vazio.
• 2 ≤ N ≤ 20 e 2 ≤ M ≤ 20.
• O seu programa dever´a imprimir uma matriz das mesmas dimens˜oes da matriz de entrada,
colocando ”o” nos lugares poss´ıveis de Ze sentar e ”x” onde ele n˜ao puder sentar.
• Caso n˜ao haja lugares para Ze sentar, seu programa deve imprimir ”Eh um dia triste para
os mono Yasuo”.

Leia_Matriz:
    -> leitura padrão de matriz

Cheque_Assentos:
    -> se o elemento for c, percorrer sua linha e coluna trocando por x 
    -> se o elemento for f, transformar essa posicao em x
    -> se o elemento for v, transformar em o


                if (assentos_original[i][j] == 'c'){
                //percorrendo toda a linha i trocando ela por x
                    for (int k=0; k<N; k++){
                        assentos_final[i][k] = 'x';
                    }
                //percorrendo toda a coluna j trocando ela por x
                    for (int k=0; k<M; k++){
                        assentos_final[k][j] = 'x';
                    }
            }
*/

void Leia_Matriz(int M, int N, char *ponteiro_Leia){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            scanf(" %c", ponteiro_Leia);
            ponteiro_Leia++;
        }
    }
    return;
}

void Escreva_Matriz(int M, int N, char matriz[][N]){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (j!=(N-1)){
                printf("%c ", matriz[i][j]);
            }
            else {
                printf("%c\n", matriz[i][j]);
            }
        }
    }
    return;
}

int Cheque_Assentos(int M, int N, char assentos_original[][N], char assentos_final[][N]){
    //temos que usar duas matrizes, senao corremos o risco de substituir um c por x e nao preencher a linha com x
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (assentos_original[i][j] == 'v'){
                assentos_final[i][j] = 'o';
            }
            else if (assentos_original[i][j] == 'f'){
                assentos_final[i][j] = 'x';
            }
        }
    }
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (assentos_original[i][j] == 'c'){
                //percorrendo toda a linha i trocando ela por x
                for (int k=0; k<N; k++){
                    assentos_final[i][k] = 'x';
                }
                //percorrendo toda a coluna j trocando ela por x
                for (int k=0; k<M; k++){
                    assentos_final[k][j] = 'x';
                }
            }
        }
    }
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (assentos_final[i][j] == 'o'){
                return 1;
            }
        }
    }
    return 0;
}

int main (void){
    int M, N;
    scanf(" %d %d", &M, &N);
    char assentos_original[M][N];
    char assentos_final[M][N];

    Leia_Matriz(M, N, &assentos_original[0][0]);

    if (Cheque_Assentos(M, N, assentos_original, assentos_final) == 1){
        Escreva_Matriz(M, N, assentos_final);
    }
    else {
        printf("Eh um dia triste para os mono Yasuo\n");
    }

    return 0;
}