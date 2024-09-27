#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct prato_ PRATO;
struct prato_{
    char nome[51];
    int prioridade;
    int tempoPreparo;
};

void bubblesort(PRATO v[], int tam);
void quicksort(PRATO v[], int inicio, int fim);
void imprimir_pratos(PRATO v[], int tam);

int main(void){
    int quantPratos = 0;
    scanf("%d", &quantPratos);

    PRATO vetPratos[quantPratos];
    for(int i=0; i<quantPratos; i++){
        scanf("%d %d %s", &vetPratos[i].prioridade, &vetPratos[i].tempoPreparo, vetPratos[i].nome);
        vetPratos[i].nome[strlen(vetPratos[i].nome)] = '\0';
    }

    //bubblesort(vetPratos, quantPratos);
    //quicksort(vetPratos, 0, quantPratos-1);

    imprimir_pratos(vetPratos, quantPratos);

    return 0;
}

void bubblesort(PRATO vetorPratos[], int tam){

    return;
}

void quicksort(PRATO v[], int inicio, int fim){
    
    return;
}

void imprimir_pratos(PRATO v[], int tam){
    for(int i=0; i<tam; i++){
        printf("%s\n", v[i].nome);
    }

    return;
}

/*
Implemente os métodos de ordenação Bubble sort e Quicksort. Você receberá 0 < 𝑘 < 3 ⋅ 10^5
pratos. Ordene em ordem decrescente de acordo com a prioridade, se a prioridade for a mesma,
o de menor tempo deverá ser priorizado. Nenhum prato tem a mesma prioridade E tempo de
preparo.
A prioridade é um inteiro 0 < 𝑝 < 10^4, o tempo de preparo (em minutos) é um inteiro 0 < 𝑡 <
10^3, o nome é uma string de no máximo 50 caracteres, sem espaço.
*/