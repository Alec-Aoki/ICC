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
    /*
    OBSERVAÇÃO:
        A busca binária sempre realiza a comparação com o elemento no meio do vetor. Sendo assim, no caso 11 do runcodes (todos os números iguais), a saída produzida seria o índice do meio do vetor. Como queremos detectar a primeira ocorrência, esse resultado estaria errado. Uma forma de prevenir isso seria, a cada chamada da busca binária, conferir se o primeiro elemento é o procurado. Caso não fosse, realizaríamos a busca como normal. Note, no entanto, que isso tornaria o caso 1 incorreto, pois como ordenamos o vetor estaticamente, o primeiro elemento seria aquele com índice 2, sendo que a primeira ocorrência do número 1 está no índice 1. Portanto, temos que checar se o primeiro número do vetor é o procurado antes de realizar qualquer operação de ordenação ou busca. Note também que não há nenhum algoritmo de ordenação com complexidade menor que O(n), portanto, nossa solução completa não terá complexidade de O(log(n)), já que temos que ordernar o vetor antes de realizar a busca. A busca binária por si só, no entanto, tem essa complexidade.
    */

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
        return buscaBinaria(v, inicio, meio-1, chave);
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