#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

void radixsort(CARTA *baralho,int tam_baralho, int valor);
int expo(int base, int pot);
CARTA *ler_baralho(int tam_baralho, int carta);
int pos_carta(char valor);

int main(){
    int tam_baralho, valores; // Quantidade de quartas e quantidade de valores em uma carta.
    scanf("%d %d", &tam_baralho, &valores);

    CARTA *baralho = ler_baralho(tam_baralho, valores);

    /*
    for(int i = 0; i < tam_baralho; i++){
        printf("%s %s;", baralho[i].naipe, baralho[i].valor);
    }
    printf("\n");*/

    //Orderna o vetor pelos valores e naipes.

    Timer tempoTimer;
    double tempoExec;
    start_timer(&tempoTimer);

    radixsort(baralho, tam_baralho, valores);

    tempoExec = stop_timer(&tempoTimer);
    printf("\nTempo de execucao: %lfs\n", tempoExec);

    return 0;
}

CARTA *ler_baralho(int tam_baralho, int carta){
    CARTA *baralho = (CARTA *) malloc(tam_baralho*sizeof(CARTA));
    char naipe[10];
    for(int i = 0; i < tam_baralho; i++){
        // Alocar espaço para o valor + o \0.
        baralho[i].valor = (char*) malloc((carta + 1)*sizeof(char));
        scanf("%s", naipe);
        baralho[i].naipe = (char*) malloc((strlen(naipe) + 1)*sizeof(char));
        strcpy(baralho[i].naipe, naipe);
        scanf(" %s", baralho[i].valor);
    }

    return baralho;

}

void radixsort(CARTA *baralho,int tam_baralho, int valor){
    // Valor equivale ao numero de valores em cada carta.
    // Filas para guardar as cartas pelos seus valores.
    QUEUE **queue = (QUEUE**) malloc(10*sizeof(QUEUE*));
    for(int i = 0; i < 10; i++){
        queue[i] = queue_generate();
    }
    
    // Adicionar os numeros as filas pelos valores, começando pelo menos significativo.
    for(int i = 0; i < valor; i++){
        for(int j = 0; j < tam_baralho; j++){
            // Adiciona a carta na fila do seu valor correspondente na posicao valor-i-1(LSD).
            // Note que i-1 é o mais significativo. logo o valor-i-1 é o menos significativo.
            queue_push(queue[pos_carta((baralho[j].valor)[valor-i-1])], baralho[j]);
        }
        // Variavel para atualizar o vetor ao descarregar as filas.
        int index = 0; 
        for(int j = 0; j < 10; j++){
            while(!queue_empty(queue[j])){
                baralho[index] = queue_pop(queue[j]);
                index++;
            }
        }

        printf("Após ordenar o %d° dígito dos valores:\n", valor-i); 
        for(int i = 0; i < tam_baralho; i++){
            printf("%s %s;", baralho[i].naipe, baralho[i].valor);
        }
        printf("\n");
    }

    for(int i = 0; i < tam_baralho; i++){
        int posicao;
        if(strcmp(baralho[i].naipe, "♦") == 0)
            posicao = 0;     
        else if(strcmp(baralho[i].naipe, "♠") == 0)
            posicao = 1;     
        else if(strcmp(baralho[i].naipe, "♥") == 0)
            posicao = 2;     
        else
            posicao = 3;

        queue_push(queue[posicao], baralho[i]);     
    }

    // Variavel para atualizar o vetor ao descarregar as filas.
    int index = 0; 
    for(int j = 0; j < 4; j++){
        while(!queue_empty(queue[j])){
            baralho[index] = queue_pop(queue[j]);
            index++;
        }
    }
    printf("Após ordenar por naipe:\n");
    for(int i = 0; i < tam_baralho; i++){
        printf("%s %s;", baralho[i].naipe, baralho[i].valor);
    }

    //Desalocação de memoria.
    for(int i = 0; i < 10; i++){
        queue_erase(&queue[i]);
    }
    free(queue);
    queue = NULL;
}

int expo(int base, int pot){
    int exp = 1;
    for(int i = 0; i < pot; i++) exp = exp*base;
    return exp;
}

int pos_carta(char valor){
    switch(valor){
        case '4':
            return 0;
        case '5':
            return 1;
        case '6':
            return 2;
        case '7':
            return 3;
        case 'Q':
            return 4;
        case 'J':
            return 5;
        case 'K':
            return 6;
        case 'A':
            return 7;
        case '2':
            return 8;
        case '3':
            return 9;
    }
}

void start_timer(Timer *timer){
    timer->start = clock();
    return;
}

double stop_timer(Timer *timer){
    timer->end = clock();
    return((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}