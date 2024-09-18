#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "item.h"
#include "pilhaEncadeada.h"

typedef struct jogador_ JOGADOR;
struct jogador_{
    char nome[51];
    int nota;
};

PILHA *algoritmo_selecao(JOGADOR *vetJogadores, int quantJogadores);

/*Main*/
int main(void){
    int quantJogadores;
    scanf(" %d", &quantJogadores);

    JOGADOR *vetJogadores = (JOGADOR *)malloc(quantJogadores*sizeof(JOGADOR));
    if(vetJogadores == NULL){
        printf("Erro ao alocar vetJogadores\n");
        return 1;
    }

    char nomeAux[51];

    for(int i=0; i<quantJogadores; i++){
        scanf("%s %d", nomeAux, &(vetJogadores[i].nota));
        strcpy(vetJogadores[i].nome, nomeAux);
    }

    PILHA *pilha = algoritmo_selecao(vetJogadores, quantJogadores);

    JOGADOR *jogadorAux;

    for(int i=0; i<quantJogadores; i++){
        jogadorAux = (JOGADOR *)item_getDado(pilha_desempilhar(pilha));
        printf("%s %d\n", jogadorAux->nome, jogadorAux->nota);
    }

    return 0;
}


/*Função Insertion Sort*/
PILHA *algoritmo_selecao(JOGADOR *vetJogadores, int quantJogadores){
    PILHA *pilha = pilha_criar();
    ITEM *vetItens[quantJogadores];

    JOGADOR jogadorMenorNota, jogadorAux;
    jogadorMenorNota.nota = 121;
    int index_jogadorMenorNota=-1;

    int i=0, j=0;
    for(; i<quantJogadores; i++){

        /*loop para achar a menor nota entre os jogadores*/
        for(j=i; j<quantJogadores; j++){

            if(vetJogadores[j].nota < jogadorMenorNota.nota){
                jogadorMenorNota = vetJogadores[j];
                index_jogadorMenorNota = j;
            }
            else if(vetJogadores[j].nota == jogadorMenorNota.nota){
                /*dois jogadores têm notas iguas, desempate por ordem alfabética*/
                if(strcmp(jogadorMenorNota.nome, vetJogadores[j].nome) < 0){
                    jogadorMenorNota = vetJogadores[j];
                    index_jogadorMenorNota = j;
                }
            }

        }

        /*swap jogador menor nota e posição i*/
        jogadorAux = vetJogadores[i];
        vetJogadores[i] = vetJogadores[index_jogadorMenorNota];
        vetJogadores[index_jogadorMenorNota] = jogadorAux;

        vetItens[i] = item_criar(&vetJogadores[i], i); //jogadorMenorNota, depois do swap, está em vetJogadores[i]

        pilha_empilhar(pilha, vetItens[i]);

        jogadorMenorNota.nota = 121;
        index_jogadorMenorNota = -1;

    }


    return pilha;
}