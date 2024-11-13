#include "arvorebinaria.h"


#include<stdio.h>
#include<stdlib.h>


typedef struct no_ NO;


struct no_
{
    int chave;
    NO *esq, *dir;
};


struct arvore_
{
    NO *raiz;
    int tamanho;
};


// Modularização
NO* inserir(NO *raiz, int chave);
void apagar(NO **raiz);
bool pertence(NO *raiz, int chave);
NO *remover(NO* raiz, int chave);


ARVORE *arvore_criar()
{
    ARVORE *arvore = (ARVORE*) malloc(sizeof(ARVORE));
    if(arvore != NULL)
    {
        arvore->raiz = NULL;
        arvore->tamanho = 0;
    }
    return arvore;
}


void arvore_apagar(ARVORE **arvore)
{
    if(*arvore != NULL)
    {
        apagar(&((*arvore)->raiz));
        free(*arvore);
        *arvore = NULL;
    }
}


void apagar(NO **raiz)
{
    if(*raiz == NULL)
        return;
   
    apagar(&((*raiz)->esq));
    apagar(&((*raiz)->dir));


    free(*raiz);
    *raiz = NULL;
}


void arvore_inserir(ARVORE *arvore, int chave)
{
    if(arvore != NULL)
    {
        arvore->raiz = inserir(arvore->raiz, chave);
        arvore->tamanho++;
    }
}


NO* inserir(NO *raiz, int chave)
{
    // Adiciona o no quando o no NULO é encontrado.
    if (raiz == NULL) {
        NO* novo_no = (NO*) malloc(sizeof(NO));
        novo_no->chave = chave;
        novo_no->esq =  NULL;
        novo_no->dir = NULL;
        return novo_no;
    }


    // Percorra a subárvore esquerda se os dados
    // forem menores que o nó atual
    if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave);
        return raiz;
    }


    // Percorra a subárvore direita se os dados
    // forem maiores que o nó atual
    else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave);
        return raiz;
    }
    else
        return raiz;
}


// Retorna se esse elemento pertence ao arvore.
bool arvore_pertence(ARVORE *arvore, int chave)
{
    if(arvore != NULL)
    {
        return pertence(arvore->raiz, chave);
    }
    return false;
}


// Verifica se o elemento está no NO, caso não, verifica-se para os filhos.
bool pertence(NO *raiz, int chave)
{
    if (raiz == NULL)
        return false;
   
    if(raiz->chave == chave)
        return true;


    return pertence(raiz->esq, chave) || pertence(raiz->dir, chave);
}


// Retorna tamanho da árvore.
int arvore_tamanho(ARVORE *arvore)
{
    if(arvore != NULL)
    {
        return arvore->tamanho;
    }


    return -1; // ERRO.
}
