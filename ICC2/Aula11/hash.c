#include <stdio.h>
#include <stdlib.h>

#define TAM_TABELA 11
#define ERRO -1
#define CONST1 2
#define CONST2 3

typedef struct h{
  int chave;
  int valor;
} hash_t;

hash_t tabela[TAM_TABELA];

/*Função hash*/
int h(int chave, int i){
  return (chave + i) % TAM_TABELA;
}

void inserir(int chave, int valor){
  for(int i = 0; i < TAM_TABELA; i++){
    int posicao = h(chave, i);

    if(tabela[posicao].chave == ERRO){
      tabela[posicao].chave = chave;
      tabela[posicao].valor = valor;

      return;
    }
    if(tabela[posicao].chave == chave){
      printf("Elemento já inserido\n");

      return;
    }
    /*else{
      //Sondagem linear
      //posicao = (posicao + 1) % TAM_TABELA;
      //Sondagem quadrádica
      posicao = (posicao + CONST1 * i + CONST2 * i * i) % TAM_TABELA;
    }*/
  }

  return;
}

int busca(int chave){
  for(int i = 0; i < TAM_TABELA; i++){
    int posicao = h(chave, i);
    if(tabela[posicao].chave == chave){
      return tabela[posicao].valor;
    }
    if(tabela[posicao].chave == ERRO) break;
    /*else{
      //posicao = (posicao + 1) % TAM_TABELA;
      posicao = (posicao + CONST1 * i + CONST2 * i * i) % TAM_TABELA;
    }*/
  }

  printf("Chave não encontrada\n");
  return ERRO;
}

void remover(int chave){
  for(int i = 0; i < TAM_TABELA; i++){
    int posicao = h(chave, i);

    if(tabela[posicao].chave == chave){
      tabela[posicao].valor = 0;
      tabela[posicao].chave = ERRO;

      return;
    }
    /*else{
      posicao = (posicao + 1) % TAM_TABELA;
    }*/
  }

  return;
}

void imprimir(void){
  for(int i = 0; i < TAM_TABELA; i++){
    printf("Indice: %d Valor: %d Chave: %d\n", i, tabela[i].valor, tabela[i].chave);
  }

  return;
}

int main(void){
  /*Inicializando a tabela*/
  for(int i = 0; i < TAM_TABELA; i++){
    tabela[i].chave = ERRO;
  }

  inserir(1, 100);
  inserir(2, 10);
  inserir(3, 30);
  inserir(4, 100);
  inserir(5, 50);
  inserir(6, 1999);
  inserir(7, 12);
  inserir(8, 513);

  imprimir();
  printf("\n");

  inserir(1, 200);
  inserir(9, 100);
  inserir(9, 200);

  imprimir();
  printf("\n");

  remover(8);

  imprimir();
  printf("\n");

  busca(50);

  return EXIT_SUCCESS;
}