#include <stdio.h>

//PASSAGEM (de parâmetro) POR CÓPIA:
    //-> somente copiamos os valores dos argumentos para as variáveis no parâmetro
int soma(int n1, int n2){
    int res;
    res = n1+n2;
    return (res);
}

//PASSAGEM ("") POR REFERÊNCIA:
    //-> passamos o endereço das variáveis como argumentos, os parâmetros são ponteiros
    //-> o swap por cópia não funciona (pq as variáveis nas funções não existem fora da função)
void swap (int *p1, int *p2){
    int w;
    w = *p1;
    *p1 = *p2;
    *p2 = w;
    return;
}

int main(void){
    int n3=1, n4=4, add;
    //add = soma(n3, n4); //n3 e n4 são os argumentos, que devem ser iguais aos parâmetros em ordem dos tipos e em quantidade
    printf("%d\n", soma(n3, n4));

    int x=20, y=10;
    swap(&x, &y);
    printf("%d %d\n", x, y);

    return 0;
}