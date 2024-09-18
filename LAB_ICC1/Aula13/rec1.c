#include <stdio.h>
//Faça um programa RECURSIVO que some 2 números inteiros, NÃO negativos !!!!! Só vale com recursão.....
/*
 * soma(x, y) = {x, y=0
 *              {1+ x + (y-1), y>0
 * */
int Add(int n1, int n2){
  if (n2 == 0){
    return n1;
  }
  return (1 + Add(n1, (n2-1)));
}

int main(void){
  int n1, n2;

  scanf("%d %d", &n1, &n2);

  int res = Add(n1, n2);

  printf("%d\n", res); 

  return 0;
}
