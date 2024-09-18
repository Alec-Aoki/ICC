#include <stdio.h>

/*
Leia_Tab
Imprima_Tab

Escreva um programa em C, que leia um inteiro N , seguido de uma matriz N x N, que deve ser
interpretada como um tabuleiro de batalha naval, onde ”O”representa espa¸cos vazios e ”N”navios.
Ap´os isso, o programa deve ler um inteiro I, seguido por I coordenadas, cada coordenada ´e com-
posta por um caractere que representa a linha e um inteiro que representa a coluna, caso haja um navio
na coordenada deve ser impresso ”acerto!”e o ”N”deve ser substituido por um ”X”, caso contr´ario
deve ser impresso ”erro!”. Por fim, o programa deve imprimir a matriz que representa o tabuleiro.
*/

//leitura da posicao dos navios no tabuleiro
void Leia_Tab(int N, char matriz[][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
    return;
}

void Imprima_Tab(int N, char tab[][N]){
    int quant_coord, coord_num;
    char coord_letra;
    scanf(" %d", &quant_coord);

    for (int i=0; i<quant_coord; i++){
        scanf(" %c%d", &coord_letra, &coord_num);
        //como estamos lendo a letra em ASCII, transformamos ela em inteiro subtraindo seu valor em dec. na tabela
        //subtraimos 1 do numero pois ele comeca no A1 e n no A0
        if (tab[(coord_letra-65)][(coord_num-1)] == 78){
            printf("acerto!\n");
            //substituindo o N (78 em dec.) para X
            tab[(coord_letra-65)][(coord_num-1)] = 'X';
        }
        else{
            printf("erro!\n");
        }
    }
    //imprimindo o tabuleiro
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
    return;
}

int main(void){
    int N;
    scanf(" %d", &N);
    char tabuleiro[N][N];

    Leia_Tab(N, tabuleiro);

    Imprima_Tab(N, tabuleiro);

    return 0;
}