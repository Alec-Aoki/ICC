#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "item.h"
#include "lista.h"

typedef struct carta_{
    char naipe[3];
    char *valores;
} CARTA;

void ler_cartas(CARTA baralho[], int quantCartas, int quantValores);
void imprimir_baralho(CARTA baralho[], int quantCartas);
bool comparar_cartas(CARTA carta1, CARTA carta2, CARTA naipes[], char valores[], int quantValores); //true: carta1 < carta2
void stoogeSort(CARTA baralho[], int inicio, int fim, int quantValores, CARTA naipes[], char valores[]);
void radixSort(CARTA baralho[], int quantCartas, int quantValores, CARTA naipes[], char valores[]);

int main(void){
    /*vetores auxiliares para acharmos os valores de uma carta*/
    CARTA naipes[4];
    strcpy(naipes[0].naipe, "♦");
    strcpy(naipes[1].naipe, "♠");
    strcpy(naipes[2].naipe, "♥");
    strcpy(naipes[3].naipe, "♣");
    char valores[10];
    valores[0] = '4';
    valores[1] = '5';
    valores[2] = '6';
    valores[3] = '7';
    valores[4] = 'Q';
    valores[5] = 'J';
    valores[6] = 'K';
    valores[7] = 'A';
    valores[8] = '2';
    valores[9] = '3';

    int quantCartas, quantValores;
    scanf("%d %d", &quantCartas, &quantValores);

    CARTA baralho[quantCartas];
    ler_cartas(baralho, quantCartas, quantValores);

    //stoogeSort(baralho, 0, quantCartas-1, quantValores, naipes, valores);

    imprimir_baralho(baralho, quantCartas);

    radixSort(baralho, quantCartas, quantValores, naipes, valores);
    
    return 0;
}

void ler_cartas(CARTA baralho[], int quantCartas, int quantValores){
    for(int i=0; i<quantCartas; i++){
        baralho[i].valores = (char *)malloc((quantValores+1)*sizeof(char));
        if(baralho[i].valores == NULL) exit(1);
        scanf(" %s %s", baralho[i].naipe, baralho[i].valores);
    }

    return;
}

void imprimir_baralho(CARTA baralho[], int quantCartas){
    for(int i=0; i<quantCartas-1; i++){
        printf("%s %s;", baralho[i].naipe, baralho[i].valores);
    }
    printf("%s %s;\n", baralho[quantCartas-1].naipe, baralho[quantCartas-1].valores);

    return;
}

bool comparar_cartas(CARTA carta1, CARTA carta2, CARTA naipes[], char valores[], int quantValores){
    int naipeCarta1=0, naipeCarta2=0;
    while(strncmp(carta1.naipe, naipes[naipeCarta1].naipe, 3) != 0) naipeCarta1++;
    while(strncmp(carta2.naipe, naipes[naipeCarta2].naipe, 3) != 0) naipeCarta2++;

    if(naipeCarta1 < naipeCarta2) return true;
    else if(naipeCarta2 < naipeCarta1) return false;
    else{
        /*naipes iguais, checar os valores das cartas*/
        int valorCarta1=0, valorCarta2=0;
        for(int i=0; i<quantValores; i++){
            while(carta1.valores[i] != valores[valorCarta1]) valorCarta1++;
            while(carta2.valores[i] != valores[valorCarta2]) valorCarta2++;

            if(valorCarta1 < valorCarta2) return true;
        }
    }

    return false;
}

void stoogeSort(CARTA baralho[], int inicio, int fim, int quantValores, CARTA naipes[], char valores[]){
    if(fim >= inicio){
        return;
    }

    if(comparar_cartas(baralho[fim], baralho[inicio], naipes, valores, quantValores)){
        CARTA cartaAux = baralho[inicio];
        baralho[inicio] = baralho[fim];
        baralho[fim] = cartaAux;
    }
    //else:
    int t = fim-inicio+1;
    if(t > 2){
        t = (int)(t/3);

        stoogeSort(baralho, inicio, fim-t, quantValores, naipes, valores);
        stoogeSort(baralho, inicio+t, fim, quantValores, naipes, valores);
        stoogeSort(baralho, inicio, fim-t, quantValores, naipes, valores);
    }

    return;
}

void radixSort(CARTA baralho[], int quantCartas, int quantValores, CARTA naipes[], char valores[]){
    CARTA baralhoOrdenado[quantCartas];

    /*criando a lista de "dígitos" (valores)*/
    LISTA *vetListas[14];
    for(int i=0; i<14; i++){
        vetListas[i] = lista_criar(false);
    }

    /*analisando os valores das cartas (naipe não incluso)*/
    for(int i=quantValores-1; i>=-1; i--){
        for(int j=0; j<quantCartas; j++){
            /*encontrando o valor do dígito sendo analisado
            estamos analisando o dígito i da carta j do baralho
            esse dígito tem o valor valorCarta, que corresponde a qual lista ele deve ser inserido
            */
            int valorCarta = 0;
            if(i>=0){
                while(baralho[j].valores[i] != valores[valorCarta]) valorCarta++;
            }
            else{
                while(strncmp(baralho[j].naipe, naipes[valorCarta].naipe, 3) != 0) valorCarta++;

                valorCarta+=10;
            }

            /*adicionar a carta na lista correspondente*/
            ITEM *itemCarta = item_criar(&(baralho[j]), j);
            lista_inserir(vetListas[valorCarta], itemCarta);
        }

        int k=0;
        for(int l=0; l<14; l++){
            while(!lista_vazia(vetListas[l])){
                ITEM *itemCarta = lista_remover_inicio(vetListas[l]);
                CARTA *pontCarta = (CARTA *)item_getDado(itemCarta);
                baralhoOrdenado[k] = *pontCarta;
                
                item_apagar(&itemCarta);
                itemCarta = NULL;
                pontCarta = NULL;

                k++;
            }
        }

        for(int m=0; m<quantCartas; m++){
            baralho[m] = baralhoOrdenado[m];
        }

        if(i>=0){
            printf("Após ordenar o %d° dígito dos valores:\n", i+1);
        }
        else{
            printf("Após ordenar por naipe:\n");
        }

        imprimir_baralho(baralho, quantCartas);

    }

    for(int i=0; i<14; i++){
        lista_apagar(&(vetListas[i]));
    }

    return;
}