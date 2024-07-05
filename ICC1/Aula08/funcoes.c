#include <stdio.h>

/* FUNÇÕES

A função main vai servir para organizar a executar (chamar) as funções, que vão conter as lógicas/algor. do programa
Quebraremos o problema em partes menores (funções)

Praxe: declar. da função -> def. da função -> main
obs: para usarmos uma função, temos que ter definido ela antes. não é obrigatório declarar elas

tipo nome(parâmetros){
    comandos;
}

parâmetros: variáveis "de fora pra dentro" da função. todas variáveis declaradas no parâmetro podem ser usadas dentro da função.
    variáveis declaradas dentro das funções e declaradas no parâmetro só existem dentro dela
tipo: se a função não retornar valores, seu tipo é void. conversões automáticas acontecem no return tmb

obs: só dá pra retornar UMA variável na função

obs: alterar o valor de um parâmetro dentro da função NÃO altera o valor da variável passada como argumento na main

obs: o comando returno sai da função, então só é possível executar ele uma vez

ARGUMENTOS PARA A MAIN
    char *argc[]: conta quantos parâmetros tem na linha de comando
    int argv: vetor de ponteiros contendo os caracteres de cada parâmetro/argumento
    o primeiro argumento é o nome do programa
*/

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