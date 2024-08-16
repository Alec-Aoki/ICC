#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numerador;
    int denominador;
}fracao;

fracao soma_fracao(int numerador_a, int denominador_a, int numerador_b, int denominador_b){
    fracao res;
    res.numerador = (numerador_a*denominador_b)+(numerador_b*denominador_a);
    res.denominador = denominador_a*denominador_b;
    return res;
}

int main (void){
    fracao a, b;
    printf("Digite o numerador da primeira fracao: ");
    scanf("%d", &a.numerador);
    printf("Digite o denominador da primeira fracao: ");
    scanf("%d", &a.denominador);
        
    printf("Digite o numerador da segunda fracao: ");
    scanf("%d", &b.numerador);
    printf("Digite o denominador da segunda fracao: ");
    scanf("%d", &b.denominador);

    fracao res;
    res = soma_fracao(a.numerador, a.denominador, b.numerador, b.denominador);
    printf("%d / %d\n", res.numerador, res.denominador);

    return 0;
}