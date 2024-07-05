//gcc nome.c -Wall -std=c99 -o nome
//./nome

/*

    VER SLIDES NO TIDIAE!!! (7 e 8)

    OPERADOR DE ENDEREÇO: &

    Declaração de variáveis:
        - Toma prioridade o valor da variável declarado mais internamente
        - Duas variáveis podem ter o mesmo nome, desde que em escopos diferentes -> elas ocupam espaços diferentes na memória

    Atribuição de valores a variáveis:
        - A linguagem C não tem tipagem forte
        - Se fizermos:
            float f=5.0;
            int i=1;
            i = f;
            printf("%d", i);

            Teremos como saída: 5 (pegamos só a parte inteira)

        - Se fizermos:
            char c='A';
            c = c + 1;
            printf("%c", c);

            Teremos como saída: B (adicionamos 00000001 (binário para o inteiro 1) ao binário correspondente ao caractere A em ASCII)
*/

#include <stdio.h>

int a=10;

int main(void){

    printf("%d\n", a);
    printf("%p\n", &a);

    int a;

    scanf("%d", &a);
    printf("%d\n", a);
    printf("%p\n", &a); // mostra o endereço da variável

    return 0;
}