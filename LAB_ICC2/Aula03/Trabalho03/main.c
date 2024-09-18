
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "./pilha/item.h"
#include "./pilha/pilhaEncadeada.h"

typedef struct jogador_ JOGADOR;
struct jogador_{
    char nome[51];
    int nota;
};

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

PILHA *algoritmo_selecao(JOGADOR *vetJogadores, int quantJogadores);

/*Main*/
int main(void){
    Timer tempoTimer;
    double tempoExec;

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

    start_timer(&tempoTimer);
    PILHA *pilha = algoritmo_selecao(vetJogadores, quantJogadores);
    tempoExec = stop_timer(&tempoTimer);

    JOGADOR *jogadorAux;

    printf("\n");

    for(int i=0; i<quantJogadores; i++){
        jogadorAux = (JOGADOR *)item_getDado(pilha_desempilhar(pilha));
        printf("%s %d\n", jogadorAux->nome, jogadorAux->nota);
    }

    printf("\n%lfms\n", tempoExec);

    pilha_apagar(&pilha);

    return 0;
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
