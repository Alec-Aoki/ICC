#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

typedef struct{
    int numero;
    int indiceOriginal;
}NO;

void quicksort(NO v[], int inicio, int fim);
int buscaBinaria(NO v[], int inicio, int fim, int chave);

int main(void){
    int quantCartas;
    int chave;
    scanf("%d %d", &quantCartas, &chave);

    NO vetNos[quantCartas];

    for(int i=0; i<quantCartas; i++){
        scanf("%d", &(vetNos[i].numero));
        vetNos[i].indiceOriginal = i;
    }

    if(chave == vetNos[0].numero){
        printf("1\n");
        return 0;
    }

    Timer tempoTimer;
    double tempoExec;
    start_timer(&tempoTimer);

    quicksort(vetNos, 0, quantCartas-1);

    int posicaoChave = buscaBinaria(vetNos, 0, quantCartas-1, chave);

    tempoExec = stop_timer(&tempoTimer);

    printf("%d\n", posicaoChave+1); //+1 pois considera que o índice começa em 1

    printf("\nTempo de execucao: %lfs\n", tempoExec);

    return 0;
}


int buscaBinaria(NO v[], int inicio, int fim, int chave){
    if((chave < v[inicio].numero) || (chave > v[fim].numero)) return -1;

    int meio = (inicio + fim)/2;

    if(v[meio].numero == chave){
        return v[meio].indiceOriginal;
    }
    else if(chave > v[meio].numero){
        return buscaBinaria(v, meio+1, fim, chave);
    }
    else{
        return buscaBinaria(v, inicio, meio, chave);
    }
}

void quicksort(NO v[], int inicio, int fim){
    if(fim <= inicio) return;

    int pivot = (inicio + fim)/2;
    NO aux = v[fim];
    v[fim] = v[pivot];
    v[pivot] = aux;
    pivot = fim;

    int i = inicio-1;
    int j = inicio;

    while(j < fim){
        if(v[j].numero <= v[fim].numero){
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }

        j++;
    }
    
    i++;
    aux = v[pivot];
    v[pivot] = v[i];
    v[i] = aux;

    quicksort(v, inicio, i-1);
    quicksort(v, i+1, fim);

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