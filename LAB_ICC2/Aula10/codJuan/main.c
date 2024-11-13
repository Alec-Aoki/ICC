#include "hash.h"


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer){
    timer->start = clock();
    return;
}
double stop_timer(Timer *timer){
    timer->end = clock();
    return((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}

// Modularização.
int achar_sequencia(hash_t *hash, int chave);


int main(void){
    int tamanho;


    scanf("%d", &tamanho);

    Timer tempoTimer;
    double tempoExec;
    start_timer(&tempoTimer);


    int *vetor = (int*) malloc(tamanho*sizeof(int));
    hash_t *hashmap = hash_criar(tamanho);


    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
        hash_inserir(hashmap, vetor[i]);
    }


    int maior_seq = 0;


    for(int i = 0; i < tamanho; i++){
        // Guarde possivel maior sequencial.
        int aux = achar_sequencia(hashmap, vetor[i]);
        if(maior_seq < aux){
            maior_seq = aux;
        }
    }

    tempoExec = stop_timer(&tempoTimer);


    printf("%d\n", maior_seq);
    printf("\nTempo de execucao: %lfs\n", tempoExec);


    // Desalocação de memória.
    // hash_apagar(&hashmap);
    free(vetor);
    vetor = NULL;


    return 0;
}


int achar_sequencia(hash_t *hash, int chave){
    // Verificar se é o primeiro da sequencia.
    if(hash_busca(hash, chave-1))
        return -1; // Elemento neutro.
    else{
        int seq = 0; // Guarda tamanho sequencia.
        do{
            chave++; // Checar se existe sucessor.
            seq++; // Aumenta 1 elemento na sequencia.
        }while(hash_busca(hash, chave));
        return seq;
    }
}
