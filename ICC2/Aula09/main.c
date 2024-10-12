#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"
#include "lista.h"

#define tam 8

/*not working*/

int getDigito(int num, int posicaoDigito){
    for(int i=0; i<posicaoDigito; i++){
        num = (int)(num/10);
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

    if(maior > 9) quantDigitosMax = 2;
    else if(maior > 99) quantDigitosMax = 3;
    else if(maior > 999) quantDigitosMax = 4;
    else if(maior > 9999) quantDigitosMax = 5;

    LISTA *vetFilas[10];
    for(int i=0; i<10; i++){
        vetFilas[i] = lista_criar(false);
    }

    for(int i=0; i<quantDigitosMax; i++){
        for(int j=0; j<tam; j++){
            int digito = getDigito(v[j], i);
            ITEM *item = item_criar(NULL, v[j]);
            lista_inserir(vetFilas[digito], item);
        }
        
        int k=0;
        for(int m=0; m<10; m++){
            while(!lista_vazia(vetFilas[m])){
                ITEM *itemTemp = lista_remover_inicio(vetFilas[m]);
                v[k] = item_getChave(itemTemp);
                k++;
            }
        }

    }
    
    for(int i=0; i<tam-1; i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[tam-1]);

    return 0;
}