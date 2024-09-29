#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct prato_ PRATO;
struct prato_{
    char nome[51];
    int prioridade;
    int tempoPreparo;
};

bool comparar_pratos(PRATO prato1, PRATO prato2);
void bubblesort(PRATO *pontVetPratos, int tam);
void quicksort(PRATO *pontVetPratos, int inicio, int fim);
void imprimir_pratos(PRATO *pontVetPratos, int tam);

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

int main(void){
    int quantPratos = 0;
    scanf("%d", &quantPratos);

    PRATO *pontVetPratos = (PRATO *)malloc(quantPratos*sizeof(PRATO));
    if(pontVetPratos == NULL) exit(1);

    for(int i=0; i<quantPratos; i++){
        scanf("%d %d %s", &pontVetPratos[i].prioridade, &pontVetPratos[i].tempoPreparo, pontVetPratos[i].nome);
        pontVetPratos[i].nome[strlen(pontVetPratos[i].nome)] = '\0';
    }

    //bubblesort(pontVetPratos, quantPratos);
    quicksort(pontVetPratos, 0, quantPratos-1);

    imprimir_pratos(pontVetPratos, quantPratos);

    free(pontVetPratos);

    return 0;
}

//Retorna true se prato1 > prato2 (prioridade, tempo de preparo)
bool comparar_pratos(PRATO prato1, PRATO prato2){
    if(prato1.prioridade > prato2.prioridade) return true;
    else if(prato1.prioridade == prato2.prioridade){
        if(prato1.tempoPreparo < prato2.tempoPreparo) return true;
    }
    
    return false;
}

void bubblesort(PRATO *pontVetPratos, int tam){
    for(int i=0; i<tam; i++){
        int trocas = 0;

        for(int j=1; j<tam-i; j++){
            if(comparar_pratos(pontVetPratos[j-1], pontVetPratos[j])){
                PRATO aux = pontVetPratos[j-1];
                pontVetPratos[j-1] = pontVetPratos[j];
                pontVetPratos[j] = aux;

                trocas++;
            }
        }

        if(trocas == 0) return;
    }

    return;
}

void quicksort(PRATO *pontVetPratos, int inicio, int fim){
    if(fim <= inicio) return; //caso base

    int pivot = (inicio + fim)/2;
    PRATO aux = pontVetPratos[fim];
    pontVetPratos[fim] = pontVetPratos[pivot];
    pontVetPratos[pivot] = aux;
    pivot = fim;

    int i = inicio-1;
    int j = inicio;

    while(j < fim){
        if(comparar_pratos(pontVetPratos[fim], pontVetPratos[j])){
            i++;
            aux = pontVetPratos[i];
            pontVetPratos[i] = pontVetPratos[j];
            pontVetPratos[j] = aux;
        }

        j++;
    }
    
    i++;
    aux = pontVetPratos[pivot];
    pontVetPratos[pivot] = pontVetPratos[i];
    pontVetPratos[i] = aux;

    quicksort(pontVetPratos, inicio, i-1);
    quicksort(pontVetPratos, i+1, fim);

    return;
}

void imprimir_pratos(PRATO *pontVetPratos, int tam){
    for(int i=0; i<tam; i++){
        //printf("%d %d %s\n", v[i].prioridade, v[i].tempoPreparo, v[i].nome);
        printf("%s\n", pontVetPratos[i].nome);
    }

    return;
}

/*Funções do timer*/
void start_timer(Timer *timer){
    timer->start = clock();
    return;
}
double stop_timer(Timer *timer){
    timer->end = clock();
    return((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}

/*
Implemente os métodos de ordenação Bubble sort e Quicksort. Você receberá 0 < 𝑘 < 3 ⋅ 10^5
pratos. Ordene em ordem decrescente de acordo com a prioridade, se a prioridade for a mesma,
o de menor tempo deverá ser priorizado. Nenhum prato tem a mesma prioridade E tempo de
preparo.
A prioridade é um inteiro 0 < 𝑝 < 10^4, o tempo de preparo (em minutos) é um inteiro 0 < 𝑡 <
10^3, o nome é uma string de no máximo 50 caracteres, sem espaço.
*/