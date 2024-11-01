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

};

NO *noCriar(int chave, NO *noEsq, NO *noDir){
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

bool noApagar(NO **no){
  if(*no == NULL) return true;

  free(*no);
  *no = NULL;

  return true;
}

ABB *abb_criar(void);
bool abb_apagar(ABB **arvore);
ABB *abb_inserir(ABB *arvore, int elemento);
int abb_remover(ABB *arvore, int elemento);
void abb_imprimir(ABB *arvore);
bool abb_busca(ABB *arvore, int chave);