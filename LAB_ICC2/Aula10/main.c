#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int buscaBinaria(int v[], int inicio, int fim, int chave);
void intercala(int esquerda[], int tamEsq, int direita[], int tamDir, int v[]);
void mergesort(int v[], int tam);
int tamSeqContinua(int v[], int tam);
void buscaRecursiva(int v[], int tam, int chave, int *tamTemp);

int main(void){
  int quantProd;
  scanf("%d", &quantProd);
  int vetProd[quantProd];

  for(int i = 0; i < quantProd; i++){
    int prod;
    scanf("%d", &prod);
    vetProd[i] = prod;
  }

  mergesort(vetProd, quantProd);

  printf("%d\n", tamSeqContinua(vetProd, quantProd));

  return EXIT_SUCCESS;
}

int tamSeqContinua(int v[], int tam){
  int tamRes = 1;

  for(int i = 0; i < tam; i++){
    int tamTemp = 1;
    buscaRecursiva(v, tam, v[i]-1, &tamTemp);
    if(tamTemp > tamRes) tamRes = tamTemp;
  }

  return tamRes;
}

void buscaRecursiva(int v[], int tam, int chave, int *tamTemp){
  if(buscaBinaria(v, 0, tam-1, chave) == ERRO) return;

  //else:
  (*tamTemp)++;
  buscaRecursiva(v, tam, chave - 1, tamTemp);

  return;
}

void intercala(int esquerda[], int tamEsq, int direita[], int tamDir, int v[]){
  int i=0, e=0, d=0;

  /*escrevendo de volta no vetor v*/
  while((e < tamEsq) && (d < tamDir)){
    if(esquerda[e] < direita[d]){
      v[i] = esquerda[e];
      e++;
    }
    else{
      v[i] = direita[d];
      d++;
    }
    i++;
  }

  /*caso não sobre elementos em um vetor para compararmos*/
  while(e < tamEsq){
    v[i] = esquerda[e];
    e++;
    i++;
  }
  while(d < tamDir){
    v[i] = direita[d];
    d++;
    i++;
  }

  return;
}

void mergesort(int v[], int tam){
  if(tam == 1){
    return;
  }

  int meio = tam/2;
  int esquerda[meio], direita[tam-meio];

  /*dividindo o vetor v[] em dois (esquerda[] e direita[]), e passando os valores pra cada um*/
  int e=0, d=0;
  for(int i=0; i<tam; i++){
    if(i < meio){
      esquerda[e] = v[i];
      e++;
    }
    else{
      direita[d] = v[i];
      d++;
    }
  }

  mergesort(esquerda, meio); //note que v[] é o vetor esquerda[]!
  mergesort(direita, tam-meio);
  intercala(esquerda, meio, direita, tam-meio, v);

  return;
}

int buscaBinaria(int v[], int inicio, int fim, int chave){
  if(inicio > fim) return ERRO;

  int meio = (inicio + fim)/2;

  if(v[meio] == chave){
    return meio;
  }
  else if(chave < v[meio]){
    return buscaBinaria(v, inicio, meio-1, chave);
  }
  else{
    return buscaBinaria(v, meio+1, fim, chave);
  }
}
