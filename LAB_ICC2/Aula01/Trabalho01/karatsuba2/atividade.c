#include "operacoes.h"

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

//Estrutura para armezenar tempo de execução.
typedef struct {
    clock_t start;
    clock_t end;
}   timer;

char *multiplicacao(const char *str1, const char *str2);
char *karatsuba(char *str1, char *str2);

void start_timer(timer *tempo);
double stop_timer(timer *tempo);

/*Função principal - entrada de dados e exibição de respostas*/
int main(void) {
    // Inicialização.
    char *str1, *str2;
    timer tempoTimer;
    long double tempoExec;
    str1 = (char*) malloc(sizeof(char)*100+1);
    if(str1 == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    str2 = (char*) malloc(sizeof(char)*100+1);
    if(str2 == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }
    // Entrada. (2 números inteiros positivos de até 10000 dígitos)
    scanf("%s %s", str1, str2); 

    // Execução de multiplicação convencional e medição de tempo.
   
    start_timer(&tempoTimer);    
    char *resultado = multiplicacao(str1, str2);
    tempoExec = stop_timer(&tempoTimer);
    
    printf("%s\n", resultado);
   
    // //Tempo de execução da multiplicação comum.
    printf("%LFms\n", tempoExec);
    
    // Execução de Karatsuba e medição de tempo.
   
    start_timer(&tempoTimer);    
    char *result_karatsuba = karatsuba(str1,str2);

    // Tira os zeros a esquerda do número.
    while(*result_karatsuba == '0' && strlen(result_karatsuba)>1) result_karatsuba++;
    
    tempoExec = stop_timer(&tempoTimer);

    printf("%s\n", result_karatsuba);
    
    //Tempo de execução karatsuba.
    printf("%LFms\n", tempoExec);
    
    //Desalocação de memória.
    if(str1 != NULL) free(str1);
    str1 = NULL; //Boa prática.
    
    if(str2 != NULL) free(str2);
    str2 = NULL;

    return 0;
}

//Inicializa o timer.
void start_timer(timer *timer){
    timer->start = clock();
}
//Para o timer.
double stop_timer(timer *timer){
    timer->end = clock();
    return ((double) (timer->end - timer->start))/ CLOCKS_PER_SEC * 1000;
}

/*Função que implementa o algortimo karatsuba - karatsuba()*/
char* karatsuba(char* str1, char* str2){
    //Caso base
    if(strlen(str1) == 1 || strlen(str2) == 1){
        return multiplicacao(str1, str2);
    }
    //Caso str1 seja menor, troca-se str1 por str2.
    if(strlen(str1) < strlen(str2)){
        char *aux = str1;
        str1 = str2;
        str2 = aux;
    }
    //Iguala o tamanho das strings.
    char *tmp = NULL;
    if(strlen(str1) > strlen(str2)){
        int tam = strlen(str1);
        tmp = calloc(tam + 1, sizeof(char)); //Adiciona o '\0'.
        memset(tmp, '0', tam);
        strcpy(tmp + (tam - strlen(str2)), str2);
        str2 = tmp;
    }
    
    int tam_max = strlen(str1); //É garantido que str1 é maior ou igual a str2.
    int meio = (tam_max+1)/2; //Garante que a metade superior seja maior em caso de impares.(Nivela por cima)
    
    /*Alocação dinamica de strings que comecam no primeiro parametro e andam n quant. de bytes*/
    // n bytes da origem são copiados para uma nova memoria.
    // Aloca dinamicamente(malloc) e aponta para o que foi copiada.
    // Tem como retorno a memoria alocada.(ponteiro para inicio).
    char *metade_superior1 = strndup(str1, meio);
    if(metade_superior1 == NULL) exit(1);

    char *metade_superior2 = strndup(str2, meio);
    if(metade_superior2 == NULL) exit(1);

    char *metade_inferior1 = strndup(str1 + meio, tam_max - meio);
    if(metade_inferior1 == NULL) exit(1);

    char *metade_inferior2 = strndup(str2 + meio, tam_max - meio);
    if(metade_inferior2 == NULL) exit(1);
    
    char *z0 = karatsuba(metade_inferior1, metade_inferior2);
    char *z1 = karatsuba(add(metade_inferior1,metade_superior1), add(metade_inferior2,metade_superior2));
    char *z2 = karatsuba(metade_superior1, metade_superior2);

    //Desalocação de memória.
    free(metade_inferior1);
    metade_inferior1 = NULL;

    free(metade_inferior2);
    metade_inferior2 = NULL;

    free(metade_superior1);
    metade_superior1 = NULL;

    free(metade_superior2);
    metade_superior2 = NULL;
    
    //Desalocação de memoria usada para igualar os tamanhos.(Caso tenha ocorrido)
    if(tmp != NULL) free(tmp);
    tmp = NULL;
    
    //Nova média para o cálculo da potência.(É preciso nivelar por baixo por conta da formula)
    meio = tam_max/2;
    
    //Operações em ordem de precendencia.
    char *subs = sub(sub(z1,z2), z0);
    char *pot1 = potencia_de_10(z2,meio*2);
    char *pot2 = potencia_de_10(subs, meio);
    char *add1 = add(pot1,pot2);
    char *resultado = add(add1, z0);

    return resultado;
}  


