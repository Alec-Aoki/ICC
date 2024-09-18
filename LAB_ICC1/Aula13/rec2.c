#include <stdio.h>

/*
 * Faça um programa que gere TODAS as palavras (de 'a' --- 'z' - minúsculas) de M caracteres.
 * A entrada é o valor de M. A saída, todas as palavras.. 1 por linha !!!!
 *
 * palavras(3) = _ _ _
 * */

void todas_palavras(int tam, char vet[tam], int index){
  
}

int main(void){
  int num_car; //quant. de caracteres
  
  scanf("%d", &num_car);

  char vet[num_car];

  for (int i=0; i<num_car; i++){
    vet[i] = 'a';
  }

  todas_palavras(num_car, vet, 0);

  return 0;
}
