#include <stdio.h>

/*
Implemente um programa em C que recebe um inteiro N e um inteiro M, que ser˜ao as dimens˜oes
de 2 matrizes quadradas. Seu programa deve imprimir as duas matrizes, checar se a matriz 1 e a
matriz 2 s˜ao ou n˜ao matrizes diagonais, e, por fim, imprimir a matriz resultante da multiplica¸c˜ao de
ambas as matrizes !!!(se poss´ıvel)!!! seguido por uma quebra de linha.

main:
-> receber M e N

-> Leitura_Matriz 1
-> Leitura_Matriz 2

-> imprimir Matriz 1
-> imprimir Matriz 2

-> Checar_Diagonal 1
-> Checar_Diagonal 2

-> dá pra mutliplicar?
    -> sim: Multiplicar_Matriz

Leitura_Matriz:
-> ler os elementos da matriz por um ponteiro

Checar_Diagonal:
-> se i!=j (nao estamos na diagonal) && matriz[i][j] != 0, nao eh diagonal -> return 1

Multiplicar_Matriz:
-> segue o jeito matematico de resolver matrizes
*/

void Leitura_Matriz(int tam, int *ponteiro_Leitura){
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            scanf(" %d", ponteiro_Leitura);
            ponteiro_Leitura++;
        }
    }
}

int Checar_Diagonal(int tam, int matriz[][tam]){
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            if ((j!=i) && (matriz[i][j]!=0)){
                return 1;
            }
        }
    }
    return 0;
}

void Multiplicar_Matriz(int M, int matriz1[][M], int matriz2[][M]){
    int num=0;
    /*
    Vamos pegar como exemplo uma matriz 3x3, os índices se referem a:
      j       l
    i 0 0 0 i 0 0 0   0 0 0
      0 0 0 . 0 0 0 = 0 0 0
      0 0 0   0 0 0   0 0 0
    */
    for (int i=0; i<M; i++){
        for (int l=0; l<M; l++){
            for (int j=0; j<M; j++){
                num += matriz1[i][j]*matriz2[j][l];
            }
            if (((l-(M-1))%M)!=0){
                printf("%d ", num);
            }
            else {
                printf("%d\n", num);
            }
            num=0;
        }
    }
    return;
}

int main(void){
    int M, N;
    scanf(" %d %d", &M, &N);

    // Leitura_Matriz 1:
    int matriz1[M][M];
    Leitura_Matriz(M, &matriz1[0][0]);
    // Leitura_Matriz 2:
    int matriz2[N][N];
    Leitura_Matriz(N, &matriz2[0][0]);

    //imprirmir matrizes 1 e 2
    printf("Matrizes:\n");
    for (int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            if (j!=(M-1)){
                printf("%d ", matriz1[i][j]);
            }
            else {
                printf("%d\n", matriz1[i][j]);  
            }
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (j!=(N-1)){
                printf("%d ", matriz2[i][j]);
            }
            else {
                printf("%d\n", matriz2[i][j]);  
            }
        }
    }

    // Checar_Diagonal 1:
    if (Checar_Diagonal(M, matriz1) == 0){
        printf("A matriz 1 eh diagonal\n");
    }
    else {
        printf("A matriz 1 nao eh diagonal\n");
    }
    // Checar_Diagonal 2:
    if (Checar_Diagonal(N, matriz2) == 0){
        printf("A matriz 2 eh diagonal\n");
    }
    else {
        printf("A matriz 2 nao eh diagonal\n");
    }

    // vendo se as matrizes sao multiplicaveis
    if (M == N){
        printf("Matriz multiplicada:\n");
        Multiplicar_Matriz(M, matriz1, matriz2);
    }
    else {
        printf("Matrizes de tamanho incompativel\n");
    }

}