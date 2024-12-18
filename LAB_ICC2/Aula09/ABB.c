#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ABB.h"

#define ERRO -1
#define NA 0
#define ESQ 1
#define DIR 2

typedef struct no_ NO;

struct no_{
  int chave;
  NO *noEsq;
  NO *noDir;
};

struct abb_{
  NO *raiz;
  int tamanho;
};

NO *buscaBinaria(NO *noRaiz, int chave);
NO *inserirABB(NO *noRaiz, NO *noNovo);
NO *removeRaizABB(NO *noRaiz);
void imprimirOrdenada(NO *noRaiz);
void imprimirNaoOrdenada(NO *noRaiz);
NO *no_criar(int chave, NO *noEsq, NO *noDir);
void no_apagar(NO **no);
void no_apagar_recursivo(NO *no);

ABB *abb_criar(void){
  ABB *arvore = (ABB *) malloc(sizeof(ABB));
  if(arvore == NULL){
    printf("Erro em abb_criar: arvore == NULL\n");
    return NULL;
  }

  arvore->raiz = NULL;
  arvore->tamanho = 0;
  return arvore;
}

void abb_apagar(ABB **arvore){
  if(*arvore == NULL) return;

  no_apagar_recursivo((*arvore)->raiz);

  free(*arvore);
  *arvore = NULL;
}

bool abb_inserir(ABB *arvore, int elemento){
  if(arvore == NULL){
    printf("Erro 1 em abb_inserir: arvore == NULL\n");
    return false;
  }

  NO *noNovo = no_criar(elemento, NULL, NULL);

  arvore->raiz = inserirABB(arvore->raiz, noNovo);
  if(arvore->raiz == NULL){
    printf("Erro 2 em abb_inserir: arvore->raiz == NULL\n");
    return false;
  }

  arvore->tamanho++;
  return true;
}

int abb_remover(ABB *arvore, int chave){
  if(arvore == NULL){
    printf("Erro em abb_remover: arvore == NULL\n");
    return ERRO;
  }
  if(arvore->raiz == NULL){
    printf("Erro em abb_remover: arvore->raiz == NULL\n");
    return ERRO;
  }

  if(chave == arvore->raiz->chave){
    NO *raizVelha = arvore->raiz;
    int elemRemovido = raizVelha->chave;

    arvore->raiz = removeRaizABB(raizVelha);
    arvore->tamanho--;

    return elemRemovido;
  }

  NO *noPai = NULL;
  NO *noPercorrerArvore = arvore->raiz;
  int posicao = NA;

  while((noPercorrerArvore != NULL) && (noPercorrerArvore->chave != chave)){
    posicao = NA;
    noPai = noPercorrerArvore;
    if(noPercorrerArvore->chave > chave){
      noPercorrerArvore = noPercorrerArvore->noEsq;
      posicao = ESQ;
    }
    else{
      noPercorrerArvore = noPercorrerArvore->noDir;
      posicao = DIR;
    }
  }

  if(noPercorrerArvore == NULL) return ERRO; //Elemento não encontrado

  int elemRemovido = noPercorrerArvore->chave;
  if(posicao == ESQ){
    noPai->noEsq = removeRaizABB(noPai->noEsq);
  }
  else{
    noPai->noDir = removeRaizABB(noPai->noDir);
  }

  arvore->tamanho--;
  return elemRemovido;
}

void abb_imprimir(ABB *arvore, bool ordenada){
  if(arvore == NULL){
    printf("Erro em abb_imprimir: arvore == NULL\n");
    return;
  }

  if(ordenada){
    imprimirOrdenada(arvore->raiz);
    printf("\n");
  }
  else{
    imprimirNaoOrdenada(arvore->raiz);
    printf("\n");
  }

  return;
}

int abb_busca(ABB *arvore, int chave){
  if(arvore == NULL){
    printf("Erro em abb_busca: arvore == NULL\n");
    return ERRO;
  }

  NO *noChave = buscaBinaria(arvore->raiz, chave);
  if(noChave == NULL) return ERRO;

  return noChave->chave;
}

NO *buscaBinaria(NO *noRaiz, int chave){
  if((noRaiz == NULL) || (noRaiz->chave == chave)){
    return noRaiz;
  }

  if(noRaiz->chave > chave){
    return buscaBinaria(noRaiz->noEsq, chave);
  }
  else{
    return buscaBinaria(noRaiz->noDir, chave);
  }
}

NO *inserirABB(NO *noRaiz, NO *noNovo){
  if(noRaiz == NULL){
    return noNovo;
  }

  if(noRaiz->chave > noNovo->chave){
    noRaiz->noEsq = inserirABB(noRaiz->noEsq, noNovo); 
  }
  else{
    noRaiz->noDir = inserirABB(noRaiz->noDir, noNovo);
  }

  return noRaiz;
}

NO *removeRaizABB(NO *noRaiz){
  if(noRaiz == NULL){
    printf("Erro em removeRaizABB: noRaiz == NULL\n");
    return NULL;
  }

  NO *noAuxP, *noAuxQ;
  if(noRaiz->noEsq == NULL){
    noAuxQ = noRaiz->noDir;

    noRaiz->noDir = NULL;
    no_apagar(&noRaiz);

    return noAuxQ;
  }
  if(noRaiz->noDir == NULL){
    noAuxQ = noRaiz->noEsq;

    noRaiz->noEsq = NULL;
    no_apagar(&noRaiz);

    return noAuxQ;
  }
  
  noAuxP = noRaiz;
  noAuxQ = noRaiz->noEsq;
  while(noAuxQ->noDir != NULL){
    noAuxP = noAuxQ;
    noAuxQ = noAuxQ->noDir;
  }

  if(noAuxP != noRaiz){
    noAuxP->noDir = noAuxQ->noEsq;
    noAuxQ->noEsq = noRaiz->noEsq;
  }
  noAuxQ->noDir = noRaiz->noDir;

  noRaiz->noDir = NULL;
  noRaiz->noEsq = NULL;
  no_apagar(&noRaiz);

  return noAuxQ;
}

void imprimirNaoOrdenada(NO *noRaiz){
  if(noRaiz != NULL){
    printf("%d ", noRaiz->chave);
    imprimirNaoOrdenada(noRaiz->noEsq);
    imprimirNaoOrdenada(noRaiz->noDir);
  }

  return;
}

void imprimirOrdenada(NO *noRaiz){
  if(noRaiz != NULL){
    imprimirOrdenada(noRaiz->noEsq);
    printf("%d ", noRaiz->chave);
    imprimirOrdenada(noRaiz->noDir);
  }

  return;
}

NO *no_criar(int chave, NO *noEsq, NO *noDir){
  NO *noNovo = (NO *) malloc(sizeof(NO));
  if(noNovo == NULL){
    printf("Erro em noCriar: noNovo == NULL\n");
    return NULL;
  }

  noNovo->chave = chave;
  noNovo->noEsq = noEsq;
  noNovo->noDir = noDir;
  return noNovo;
}

void no_apagar(NO **no){
  if(*no == NULL) return;

  free(*no);
  *no = NULL;
  return;
}

void no_apagar_recursivo(NO *no){
  if(no == NULL) return;

  no_apagar_recursivo(no->noEsq);
  no_apagar_recursivo(no->noDir);
  no_apagar(&no);

  return;
}