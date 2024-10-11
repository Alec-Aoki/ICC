#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct carta_{
    char naipe[3];
    char *valores;
} CARTA;

void ler_cartas(CARTA baralho[], int quantCartas, int quantValores);
void imprimir_baralho(CARTA baralho[], int quantCartas);
bool comparar_cartas(CARTA carta1, CARTA carta2, CARTA naipes[], char valores[]); //true: carta1 < carta2

int main(void){
    /*vetores auxiliares para compararmos duas cartas*/
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

    imprimir_baralho(baralho, quantCartas);
    
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
    for(int i=0; i<quantCartas; i++){
        printf("%s %s\n", baralho[i].naipe, baralho[i].valores);
    }

    return;
}

bool comparar_cartas(CARTA carta1, CARTA carta2, CARTA naipes[], char valores[]){
    int naipeCarta1=0, naipeCarta2=0;
    while(strncmp(carta1.naipe, naipes[naipeCarta1].naipe, 3) != 0) naipeCarta1++;
    while(strncmp(carta2.naipe, naipes[naipeCarta2].naipe, 3) != 0) naipeCarta2++;

    if(naipeCarta1 < naipeCarta2) return true;
    else{
        /*checar os valores das cartas*/
    }
}