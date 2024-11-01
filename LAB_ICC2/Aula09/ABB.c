#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ABB.h"

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

bool no_apagar(NO **no){
  if(*no == NULL) return true;

  free(*no);
  *no = NULL;
  return true;
}

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

  while((*arvore)->tamanho > 0){
    abb_remover(*arvore, (*arvore)->raiz->chave);
  }

  free(*arvore);
  *arvore = NULL;
}

bool abb_inserir(ABB *arvore, int elemento){
  if(arvore == NULL){
    printf("Erro em abb_inserir: arvore == NULL\n");
    return false;
  }

  return true;
}

int abb_remover(ABB *arvore, int chave);

void abb_imprimir(ABB *arvore);

bool abb_busca(ABB *arvore, int chave);