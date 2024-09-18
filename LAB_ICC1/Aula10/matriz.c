#include <stdio.h>
#include <stdlib.h>

/*
Implemente um programa em C que recebe um inteiro N que representa a quantidade de elementos
de uma matriz, vocˆe dever´a alocar uma matriz dinamicamente para receber esses n elementos, e
desenvolver fun¸c˜oes para preenche-la, e depois printa-la na tela

main:
-> receber n
-> Aloque();
-> Receba();
-> Imprima();

Aloque:
-> receber n
-> sqrt(n) = linha = coluna;
-> criar vetor de ponteiros que vão apontar para a matriz:
    -> **p = (int **)malloc(linha*sizeof(int *));
-> criar o vetor que vai servir de matriz:
    -> *v = (int *)malloc((linha*coluna)*sizeof(int));
-> dar o endereço do início de cada coluna a cada ponteiro no vetor de ponteiros:
    -> for(int i=0; i<linha; i++){
        p[i] = &v[i*coluna];
    }
-> retornar p;

Receba:
//loop para receber valores (n sei de vai dar certo):
-> for (int i=0; i<linha; i++){
    for (int j=0; j<coluna; j++){
        scanf(" %d", p[i][j]);
    }
}
return;

Imprima:
//loop para imprimir os valores (tmb n sei se funciona):
-> for (int i=0; i<linha; i++){
    for (int j=0; j<coluna; j++){
        printf("%d", *p[i][j]);
        //colocar aquele if macabro pra printar bonitinho
    }
}
return.
*/

int **Aloque(int *linha_p, int *coluna_p, int tam_Aloque){
    int coluna, linha;

    //achando a raiz quadrada to tamanho da matriz
    int raiz_Aloque;
    for (int i=0; i*i <= tam_Aloque; i++){
        raiz_Aloque = i;
    }

    //pegando a quant. de linhas e colunas (a matriz é quadrada)
    coluna = linha = raiz_Aloque;
    *linha_p = linha;
    *coluna_p = coluna;

    //criação do vetor de ponteiros
    int **vet_pont;
    vet_pont = (int **)malloc(linha*sizeof(int *));

    //criação do vetor grandão que é a matriz em si
    int *vet;
    vet = (int *)malloc((linha*coluna)*sizeof(int));

    //atribuição do endereço de cada coluna a cada ponteiro do vetor de ponteirsos
    for (int i=0; i<linha; i++){
        vet_pont[i] = &vet[i*coluna];
    }

    return vet_pont;
}

void Receba(int *ponteiro_Receba, int tam){
    for (int i=0; i<tam; i++){
        scanf(" %d", &ponteiro_Receba[i]);
    }
    return;
}

void Imprima(int **ponteiro_Imprima, int linha, int coluna){
    for (int i=0; i<linha; i++){
        for (int j=0; j<coluna; j++){
            if (j!=(coluna-1)){
                printf("%d ", ponteiro_Imprima[i][j]);
            }
            else {
                printf("%d\n", ponteiro_Imprima[i][j]);
            }
        }
    }
    return;
}

int main(void){
    int **pont_matriz, tam_m, linha, coluna;
    //recebendo o tamanho da matriz
    scanf(" %d", &tam_m);

    //alocação da matriz na  heap:
    pont_matriz = (int **)Aloque(&linha, &coluna, tam_m);
    //pont_matriz aponta para o início do vetor de ponteiros

    //leitura dos elementos da matriz:
    Receba(*pont_matriz, tam_m);

    //impresão dos elementos da matriz:
    Imprima(pont_matriz, linha, coluna);

    //desalocação:
    free(*pont_matriz);
    free(pont_matriz);
    return 0;
}