/*GERANDO UMA LISTA DE NÚMEROS ALEATÓRIOS*/

/*
!!!FAZER OPÇÃO DE GRAVAR EM TEXTO OU BINÁRIO!!!
*/

/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*STRUCTS*/
typedef struct{
    int *pont; //ponteiro que aponta para a lista de numeros, alocada dinamicamente
    int tamanho; //quantidade de elementos na lista
}lista;

typedef struct{
    clock_t start;
    clock_t end;
}Timer;

/*PROTOTIPAGEM DAS FUNÇÕES*/
//void printarLista(int *pont_lista, int tam_Lista);
void escreverArquivo(lista listaAleatoria);
void start_timer(Timer *timer);
double stop_timer(Timer *timer);
void imprimirTempo(double tempo);

/*MAIN*/
int main(void){
    lista listaAleatoria;
    Timer timer;

    //gera uma seed a partir do horário (logo, é única)
    srand(time(NULL));

    printf("Digite o tamanho da lista de numeros:\n");
    scanf("%d", &listaAleatoria.tamanho);

    listaAleatoria.pont = (int *)malloc(listaAleatoria.tamanho*sizeof(int));
    if(listaAleatoria.pont == NULL) exit(1);

    start_timer(&timer);
    for(int i=0; i<listaAleatoria.tamanho; i++){
        listaAleatoria.pont[i] = rand();
    }
    imprimirTempo(stop_timer(&timer));
    
    escreverArquivo(listaAleatoria);

    free(listaAleatoria.pont);
    listaAleatoria.pont = NULL;

    return 0;
}

/*FUNÇÕES*/
// void printarLista(int *pont_lista, int tam_Lista){
//     for(int i=0; i<tam_Lista; i++){
//         printf("%d\n", pont_lista[i]);
//     }

//     return;
// }

void escreverArquivo(lista listaAleatoria){
    FILE *fp;
    fp = fopen("ListaAleatoria.bin", "wb");

    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
    }

    fwrite(listaAleatoria.pont, sizeof(int), listaAleatoria.tamanho, fp);

    fclose(fp);
    fp = NULL;
    return;
}

void start_timer(Timer *timer){
    timer->start = clock();
    return;
}

double stop_timer(Timer *timer){
    timer->end = clock();
    return((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}

void imprimirTempo(double tempo){
    printf("Tempo de execucao: %lf\n", tempo);
}