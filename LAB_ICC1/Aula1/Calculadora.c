#include <stdio.h>

int main(){
    int n1, n2, soma, sub, mult, div_int;
    float div_f;

    scanf("%d\n%d", &n1, &n2);

    soma = n1+n2;
    sub = n1-n2;
    mult = n1*n2;
    div_int = n1/n2;
    div_f =(float)n1/n2; // se não falar que é um float, ele só armazena o resultado da operação em int numa var. float

    printf("Soma: %d\nSubtracao: %d\nMultiplicacao: %d\nDivisao Inteira: %d\nDivisao Racional: %.3f\n", soma, sub, mult, div_int, div_f);
    //.3 entre % e f faz delimita as casas decimais
    return 0;
}