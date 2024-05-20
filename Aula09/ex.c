#include <stdio.h>

/*
Realizar a soma dos elementos da matriz MxN que foram maiores que um dado numero
*/

// leitura dos elementos da matriz
double Leia_Matriz(int M, int N, double *ponteiro_Leia){
    double limite;
    printf("Digite o valor limite:\n");
    scanf(" %lf", &limite);
    printf("Digite os elementos da matriz:\n");
    for (int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            scanf(" %lf", ponteiro_Leia);
            ponteiro_Leia++;
        }
    }
    return limite;
}

//Checagem de quais valores sao maiores que o limite e soma desses valores
double Soma_Matriz(double limite, int M, int N, double matriz[][N]){
    double soma=0;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (matriz[i][j]>=limite){
                soma += matriz[i][j];
            }
        }
    }
    return soma;
}

int main(void){
    double limite, res;
    int M, N;
    printf("Digite as linhas e colunas da matriz:\n");
    scanf(" %d %d", &M, &N);
    double matriz[M][N];
    
    limite = Leia_Matriz(M, N, &matriz[0][0]);
    res = Soma_Matriz(limite, M, N, matriz);
    
    printf("Soma:\n");
    printf("%lf\n", res);
    return 0;
}