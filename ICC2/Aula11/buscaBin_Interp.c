#include <stdio.h>
#include <stdlib.h>

#define ERRO -1;

int buscaBinariaRecursiva(int v[], int inicio, int fim, int chave){
  if(inicio > fim) return ERRO; //chave não encontrada

  int meio = (inicio + fim)/2;
  if(v[meio] == chave){
    return meio;
  }
  else if(chave < v[meio]){
    return buscaBinariaRecursiva(v, inicio, meio-1, chave);
  }
  else{
    return buscaBinariaRecursiva(v, meio+1, fim, chave);
  }
}

int buscaBinariaIterativa(int v[], int tam, int chave){
  int inicio = 0;
  int fim = tam-1;

  while(inicio <= fim){
    int meio = (inicio + fim)/2;
    if(v[meio] == chave) return meio;
    if(chave < v[meio]) fim = meio - 1;
    if(chave > v[meio]) inicio = meio + 1;
  }

  return ERRO;
}

int buscaInterpolacao(int v[], int tam, int chave){
  int inicio = 0;
  int fim = tam-1;

  while(inicio <= fim){
    int meio = inicio + (fim - inicio) * ((chave - v[inicio]) / (v[fim] - v[inicio]));
    if(v[meio] == chave) return meio;
    if(chave < v[meio]) fim = meio - 1;
    if(chave > v[meio]) inicio = meio + 1;
  }

  return ERRO;
}

int main(void){
  int v[] = {1, 3, 5, 7, 9, 11, 13};

  printf("%d\n", buscaBinariaRecursiva(v, 0, 6, 11));
  printf("%d\n", buscaBinariaIterativa(v, 7, 11));
  printf("%d\n", buscaInterpolacao(v, 7, 11));

  return EXIT_SUCCESS;
}