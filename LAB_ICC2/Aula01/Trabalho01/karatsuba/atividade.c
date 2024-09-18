#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "operacoes.h"

/*OBS: Tam_maxString = 100*/
#define max(a, b) ((a) >= (b) ? (a) : (b))

typedef struct{
    clock_t start;
    clock_t end;
} timer;

char *multiplicacao(const char *str1, const char *str2);
char *karatsuba(char *str1, char *str2);

void start_timer(timer *tempo);
double stop_timer(timer *tempo);

int main(void)
{
    // Inicialização
    char str1[1000], str2[1000];
    timer tempoTimer;
    double tempoExec;

    // Entrada (2 números inteiros positivos de até 10000 dígitos)
    scanf("%s", str1);
    scanf("%s", str2);

    // Execução de multiplicação convencional e medição de tempo
    start_timer(&tempoTimer);
    char *strMultiplicacao = multiplicacao(str1, str2);
    tempoExec = stop_timer(&tempoTimer);

    
    while(*strMultiplicacao == '0' && strlen(strMultiplicacao)>1){
        strMultiplicacao++;
    }
    printf("\n%s\n", strMultiplicacao);
    

    printf("%lfms\n", tempoExec);

    // Execução de Karatsuba e medição de tempo
    start_timer(&tempoTimer);
    char *strKaratsuba = karatsuba(str1, str2);
    tempoExec = stop_timer(&tempoTimer);

    
    while(*strKaratsuba == '0' && strlen(strKaratsuba)>1){
        strKaratsuba++;
    }
    printf("\n%s\n", strKaratsuba);
    

    printf("%lfms\n", tempoExec);

    return 0;
}

char *karatsuba(char *str1, char *str2){
    /*Caso base*/
    if (strlen(str1) <= 1 || strlen(str2) <= 1){
        return multiplicacao(str1, str2);
    }

    if(strlen(str1) > strlen(str2)){
        int tam = strlen(str1);
        char* tmp2 = calloc(tam + 1, sizeof(char));
        memset(tmp2, '0', tam);
        strcpy(tmp2 + (tam - strlen(str2)), str2);
        str2 = tmp2;
    }
    else if(strlen(str1) < strlen(str2)){
        int tam = strlen(str2);
        char* tmp1 = calloc(tam + 1, sizeof(char));
        memset(tmp1, '0', tam);
        strcpy(tmp1 + (tam - strlen(str1)), str1);
        str1 = tmp1;
    }

    /*Separando os números no meio*/
    int maiorTamanho = strlen(str1);
    int metade = (maiorTamanho+1) / 2; // conversão automática
    //fazemos maiorTamanho+1 para que a parte superior do número seja sempre maior que a inferior

    char *mSuperior_str1 = (char *)malloc((metade + 1) * sizeof(char)); //+1 por causa do \0
    if(mSuperior_str1 == NULL) exit(1);
    mSuperior_str1[metade] = '\0';

    char *mInferior_str1 = (char *)malloc((maiorTamanho - metade + 1) * sizeof(char));
    if(mInferior_str1 == NULL) exit(1);
    mInferior_str1[maiorTamanho - metade] = '\0';

    char *mSuperior_str2 = (char *)malloc((metade + 1) * sizeof(char)); //+1 por causa do \0
    if(mSuperior_str2 == NULL) exit(1);
    mSuperior_str2[metade] = '\0';

    char *mInferior_str2 = (char *)malloc((maiorTamanho - metade + 1) * sizeof(char));
    if(mInferior_str1 == NULL) exit(1);
    mInferior_str2[maiorTamanho - metade] = '\0';

    /*Atribuição dos números aos vetores criados*/
    for (int i = 0; i < metade; i++){
        mSuperior_str1[i] = str1[i];
        mSuperior_str2[i] = str2[i];
    }
    int contador = 0;
    for (int i = metade; i < maiorTamanho; i++){
        mInferior_str1[contador] = str1[i];
        mInferior_str2[contador] = str2[i];
        contador++;
    }

    /*Karatsuba em si*/
    char *ac = karatsuba(mSuperior_str1, mSuperior_str2);
    char *bd = karatsuba(mInferior_str1, mInferior_str2);
    char *ad_plus_bc = sub(sub(karatsuba(add(mSuperior_str1, mInferior_str1), add(mSuperior_str2, mInferior_str2)), ac), bd);

    metade = maiorTamanho/2;  //atualizamos o valor de metade pois agora queremos saber seu valor exato

    char *termo1 = potencia_de_10(ac, metade * 2);
    char *termo2 = potencia_de_10(ad_plus_bc, metade);
    char *termo3 = bd;

    free(mSuperior_str1);
    free(mSuperior_str2);
    free(mInferior_str1);
    free(mInferior_str2);

    return (add(add(termo1, termo2), termo3));
}

void start_timer(timer *tempo){
    tempo->start = clock();
    return;
}
double stop_timer(timer *tempo){
    tempo->end = clock();
    return ((double)(tempo->end - tempo->start) / CLOCKS_PER_SEC);
}