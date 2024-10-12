#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"
#include "filaDinamica.h"

#define tam 8

/*not working :)*/

int getDigito(int num, int posicaoDigito){
    for(int i=0; i<posicaoDigito; i++){
        num = num/10;
    }

    return num%10;
}

int main(void){
    int v[] = {12, 92, 33, 25, 86, 57, 37, 48};

    int quantDigitosMax = 1;
    int maior = -1;

    for(int i=0; i<tam; i++){
        if(v[i] > maior) maior = v[i];
    }
    printf("Maior numero encontrado\n");

    if(maior > 9) quantDigitosMax = 2;
    else if(maior > 99) quantDigitosMax = 3;
    else if(maior > 999) quantDigitosMax = 4;
    else if(maior > 9999) quantDigitosMax = 5;

    printf("Quant. max. de digitos definida\n");

    FILA *vetFilas[10];
    for(int i=0; i<10; i++){
        vetFilas[i] = fila_criar();
    }
    printf("Filas criadas\n");

    for(int i=0; i<quantDigitosMax; i++){
        for(int j=0; j<tam; j++){
            int digito = getDigito(v[j], i);
            ITEM *item = item_criar(NULL, v[j]);
            fila_inserir(vetFilas[digito], item);
        }
        printf("Todos os itens inseridos\n");

        int k=0;
        for(int m=0; m<tam; m++){
            while(!fila_vazia(vetFilas[m])){
                printf("Fila nao vazia\n");
                ITEM *itemTemp = fila_remover(vetFilas[m]);
                printf("Item removido da fila\n");
                v[k++] = item_getChave(itemTemp);
                printf("Chave inserida no vetor\n");
            }
        }
        printf("Todos os itens removidos\n");
    }

    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}