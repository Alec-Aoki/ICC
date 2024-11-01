#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ABB.h"

int main(void){
  ABB *arvore = abb_criar();

  int quantElementos;
  scanf("%d", &quantElementos);

  for(int i = 0; i < quantElementos; i++){
    int elemento;
    scanf("%d", &elemento);
    abb_inserir(arvore, elemento);
  }

  int chave;
  scanf("%d", chave);
  printf("%d\n", abb_busca(arvore, chave));

  return 0;
}