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

/*funções base*/
bool comparar_pratos(PRATO prato1, PRATO prato2);
void imprimir_pratos(PRATO *pontVetPratos, int tam);

/*funcões mergesort*/
void intercala(PRATO esquerda[], int tam_esq, PRATO direita[], int tam_dir, PRATO *v);
void mergesort(PRATO *v, int tam);

/*funções do timer*/
typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

int main(void){

    int quantPratos = 0;
    scanf("%d", &quantPratos);

    PRATO *pontVetPratos = (PRATO *)calloc(quantPratos, sizeof(PRATO));
    if(pontVetPratos == NULL) exit(1);

    /*lendo a entrada*/
    for(int i=0; i<quantPratos; i++){
        scanf("%d %d %s", &pontVetPratos[i].prioridade, &pontVetPratos[i].tempoPreparo, pontVetPratos[i].nome);
        pontVetPratos[i].nome[strlen(pontVetPratos[i].nome)] = '\0';
    }

    Timer tempoTimer;
    double tempoExec;

    start_timer(&tempoTimer);

    mergesort(pontVetPratos, quantPratos);

    tempoExec = stop_timer(&tempoTimer);
    printf("\nTempo de execucao: %lfms\n", tempoExec);

    //imprimir_pratos(pontVetPratos, quantPratos);

    free(pontVetPratos);

    return 0;
}

/*mergesort*/
/*função para intercalar dois vetores ordenadamente (ordem crescente de prioridade)*/
void intercala(PRATO esquerda[], int tam_esq, PRATO direita[], int tam_dir, PRATO *v){
    int i=0, e=0, d=0;

    /*escrevendo de volta no vetor v*/
    while((e < tam_esq) && (d < tam_dir)){
        /*vendo qual prato tem menor prioridade*/
        if(comparar_pratos(esquerda[e], direita[d])){
            v[i] = esquerda[e];
            e++;
        }
        else{
            v[i] = direita[d];
            d++;
        }
        i++;
    }

    /*caso não sobre elementos em um vetor para compararmos, escrevemos o restante no vetor v*/
    while(e < tam_esq){
        v[i] = esquerda[e];
        e++;
        i++;
    }
    while(d < tam_dir){
        v[i] = direita[d];
        d++;
        i++;
    }

    return;
}

void mergesort(PRATO *v, int tam){
    if(tam == 1){ //caso base
        return;
    }

    int meio = tam/2;
    PRATO *esquerda, *direita;
    esquerda = (PRATO *)calloc(meio, sizeof(PRATO));
    direita = (PRATO *)calloc((tam-meio), sizeof(PRATO));
    
    /*dividindo o vetor v[] em dois (esquerda e direita), e copiando os valores pra cada um*/
    int e=0, d=0;
    for(int i=0; i<tam; i++){
        if(i < meio){
            esquerda[e] = v[i];
            e++;
        }
        else{
            direita[d] = v[i];
            d++;
        }
    }

    /*chamando o mersort recursivamente, até tam == 1*/
    mergesort(esquerda, meio); //note que v[] é o vetor esquerda[]!
    mergesort(direita, tam-meio);
    /*intercalando os vetores sucessivamente*/
    intercala(esquerda, meio, direita, tam-meio, v);

    free(esquerda);
    free(direita);

    return;
}

//Retorna true se o prato1 deve ter maior prioridade que o prato2
bool comparar_pratos(PRATO prato1, PRATO prato2){
    if(prato1.prioridade < prato2.prioridade) return true;
    else if(prato1.prioridade == prato2.prioridade){
        if(prato1.tempoPreparo > prato2.tempoPreparo) return true;
    }
    
    return false;
}

void imprimir_pratos(PRATO *pontVetPratos, int tam){
    for(int i=0; i<tam; i++){
        //printf("%d %d %s\n", pontVetPratos[i].prioridade, pontVetPratos[i].tempoPreparo, pontVetPratos[i].nome);
        printf("%s\n", pontVetPratos[i].nome);
    }

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