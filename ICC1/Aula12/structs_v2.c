#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTS
-> uma coleção de variáveis (elementos/campos, que podem ser de tipos diferentes), organizadas em um único conjunto
exemplo:
    struct pessoa{
        char nome[30];
        int idade;
    };
    int main(void){
        struct pessoa Joao;
        strcpy(Joao.nome, "Joao");
        Joao.idade = 18;
        return 0;
    }
-> o tamanho de uma variável do tipo da struct é a soma do tamanho das variáveis que a struct tem
-> exemplo usando typedef:
    typedef struct{
        int nome[30];
        int idade;
    }pessoa;
    int main (void){
        pessoa Joao;
        return 0;
    }
-> podemos retornar structs (exemplo abaixo)
-> podemos declarar structs dentro de structs
-> exemplo:
    struct ponto{
        int x;
        int y;
    };
    struct linha{
        struct ponto p1;
        struct ponto p2;
    }Linha;
    int main (void){
        Linha.p1.x = 0;
        Linha.p1.y = 0;
        Linha.p2.x = 5;
        Linha.p2.y = 3;
        //P1(0,0)
        //P2(5,3)
        return 0;
    }
-> structs podem ser declaradas dentro delas mesmas

STRUCTS DE PONTEIROS
-> um ponteiro do tipo de uma struct aponta para uma variável do tipo dessa struct
-> exemplo:
    struct ponto *ponteiro_ponto; ponteiro que aponta para variáveis do tipo "struct ponto"
*/

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