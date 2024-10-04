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

bool comparar_pratos(PRATO prato1, PRATO prato2);
void imprimir_pratos(PRATO *pontVetPratos, int tam);

int main(void){

    int quantPratos = 0;
    scanf("%d", &quantPratos);

    PRATO *pontVetPratos = (PRATO *)calloc(quantPratos, sizeof(PRATO));
    if(pontVetPratos == NULL) exit(1);

    for(int i=0; i<quantPratos; i++){
        scanf("%d %d %s", &pontVetPratos[i].prioridade, &pontVetPratos[i].tempoPreparo, pontVetPratos[i].nome);
        pontVetPratos[i].nome[strlen(pontVetPratos[i].nome)] = '\0';
    }

    free(pontVetPratos);

    return 0;
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
        //printf("%d %d %s\n", v[i].prioridade, v[i].tempoPreparo, v[i].nome);
        printf("%s\n", pontVetPratos[i].nome);
    }

    return;
}