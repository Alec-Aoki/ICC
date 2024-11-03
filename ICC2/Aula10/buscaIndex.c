#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERRO -1

typedef struct indice_ INDICE;

struct indice_{
  int chave;
  int posOrig;
};

void bubblesort(int v[], int tam);
void criar_indice(INDICE indice[], int tamIndice, int v[], int tamV);
int busca_sequencial_indexada(int v[], int tamV, INDICE indice[], int tamIndice, int chave);
int busca_sequencial(int v[], int tam, int inicio, int fim, int chave);

int main(void){
  int v[] = {89, 54, 23, 76, 12, 45, 90, 32, 15, 69, 92, 83, 47, 31, 62};
  int tamV = sizeof(v)/sizeof(v[0]);
    
  bubblesort(v, tamV);
    
  printf("Sorted array: ");
  for(int i = 0; i < tamV; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
    
  int tamIndice = tamV/3 + 1;  // Size of index array
  INDICE* indice = (INDICE*)malloc(tamIndice * sizeof(INDICE));
  if(indice == NULL) {
    printf("Memory allocation failed!\n");
    return EXIT_FAILURE;
  }
    
  criar_indice(indice, tamIndice, v, tamV);
    
  printf("\nIndex array:\n");
  for(int i = 0; i < tamIndice; i++) {
    printf("Key: %d, Original Position: %d\n", 
    indice[i].chave, indice[i].posOrig);
  }
    
  int test_values[] = {45, 92, 15, 100};  // Last value shouldn't be found
  int num_tests = sizeof(test_values)/sizeof(test_values[0]);
    
  printf("\nPerforming searches:\n");
  for(int i = 0; i < num_tests; i++) {
    int result = busca_sequencial_indexada(v, tamV, indice, tamIndice, test_values[i]);
    if(result == ERRO) {
      printf("Value %d not found\n", test_values[i]);
    }
    else {
      printf("Value %d found at position %d\n", test_values[i], result);
    }
  }
  
  free(indice);
  return EXIT_SUCCESS;
}

int busca_sequencial(int v[], int tam, int inicio, int fim, int chave){
  if(fim > tam) return ERRO;

  for(int i = inicio; i < fim; i++){
    if(v[i] == chave) return i;
    if(chave < v[i]) break;
  }

  return ERRO;
}

void criar_indice(INDICE indice[], int tamIndice, int v[], int tamV){
  int k = tamV/tamIndice;
  int i = 0, j = 0;
  while((i < tamIndice) && (j < tamV)){ //Para preencher o vetor indice[]
    indice[i].chave = v[j];
    indice[i].posOrig = j;
    i++;
    j += k;
  }

  return;
}

int busca_sequencial_indexada(int v[], int tamV, INDICE indice[], int tamIndice, int chave){
  if(chave < indice[0].chave) return ERRO;
  if(chave > v[tamV - 1]) return ERRO;

  for(int i = 0; i < tamIndice; i++){
    if(chave == indice[i].chave){
      return indice[i].posOrig;
    }

    if(chave < indice[i].chave){
      return busca_sequencial(v, tamV, indice[i - 1].posOrig, indice[i].posOrig, chave);
    }
  }

  return busca_sequencial(v, tamV, indice[tamIndice - 1].posOrig, tamV, chave);
}

void bubblesort(int v[], int tam){
  for(int i=0; i<tam; i++){
    int trocas = 0;
    for(int j=1; j<tam-i; j++){
      if(v[j] < v[j-1]){
        int aux = v[j-1];
        v[j-1] = v[j];
        v[j] = aux;
        trocas++;
      }
    }
    if(trocas == 0) return;
  }
  return;
}