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

NO *inserirABB(NO *noRaiz, NO *noNovo);
NO *removeRaizABB(NO *noRaiz);
NO *no_criar(int chave, NO *noEsq, NO *noDir);
void no_apagar(NO **no);

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
}

void abb_imprimir(ABB *arvore);

bool abb_busca(ABB *arvore, int chave);

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
