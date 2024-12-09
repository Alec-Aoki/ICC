/*
4 3
CUASO 2 CidadeAdhemar 1 Butanta 1 Sertaozinho 4
CUASO 2
Butanta 4
Sertaozinho 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no_ NO;

struct no_
{
    NO *proximo;
    char *local;
};

// Modularização código
NO *ler_dados(int quant_no);
void cidade_destino(int quant_no, NO *grafo, int passos, char *buffer);
void desalocar_memoria(int quant_no,NO **grafo);

// Função principal.
int main(void)
{
    int quant_no, quant_passeios;
    scanf("%d %d", &quant_no, &quant_passeios);

    NO *grafo = ler_dados(quant_no);

    // Verificar passeios
    for(int i = 0; i < quant_passeios; i++)
    {
        // Armazenar cidade de início.
        char buffer[100];
        // Passos a serem percorridos
        int passos; 
    
        scanf(" %s %d", buffer, &passos);
        cidade_destino(quant_no, grafo, passos, buffer);
    }

    desalocar_memoria(quant_no, &grafo);

    return 0;
}

// Le e guarda a informações dos nós do grafo.
NO *ler_dados(int quant_no)
{
    NO *grafo = (NO*) malloc(quant_no*sizeof(NO));
    if(grafo != NULL)
    {
        for(int i = 0; i < quant_no; i++)
        {
            // Ler nome do teclado e destino do teclado.
            int destino;
            char buffer[100];
            scanf(" %s %d", buffer, &destino);
            destino--; // Ajuste para base 0.

            // Ajusta tamanho para guardar nome(+ 1 para o \0).
            grafo[i].local = (char*) malloc(sizeof(char)*(strlen(buffer) + 1)); 
            strcpy(grafo[i].local, buffer);

            // Conectar local com seu destino.
            grafo[i].proximo = &grafo[destino];
        }
    }

    return grafo;
}

// Encontra cidade de destino de imprimi ela.
void cidade_destino(int quant_no, NO *grafo, int passos, char *buffer)
{
    // Posição da cidade no vetor
    // que se inicia o percurso.
    int origem = -1;
    // Procura-se cidade no grafo.
    for(int i = 0; i < quant_no; i++)
    {
        // strcmp retorna 0 se encontrar cidade.
        if(strcmp(buffer, grafo[i].local) == 0)
        {
            // Salva ponto de partida.
            origem = i;
            break;
        }
    }
    // Caso não seja encontrado.
    if(origem == -1)
    {
        printf("Cidade não está no grafo\n");
        return;
    }
    
    // Realizar o percurso com ponteiro.
    NO *estado_atual = &grafo[origem];
    for(int i = 0; i < passos; i++)
    {
        estado_atual = estado_atual->proximo;
    }
    // Imprimi destino.
    printf("%s\n", estado_atual->local);
    return;
}

// Função para desalocação de memória.
void desalocar_memoria(int quant_no,NO **grafo)
{
    for(int i = 0; i < quant_no; i++)
    {
        // Desalocar memória dos locais.
        free((*grafo)[i].local);
        (*grafo)[i].local = NULL;
    }
    // Desalocar memoria alocada para o grafo.
    free(*grafo);
    *grafo = NULL;
}

