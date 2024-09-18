#include <stdio.h>

int main(){

    int dias, mes, ano;

    scanf("%2d%2d%4d", &dias, &mes, &ano);
    printf("%.2d/%.2d/%.4d\n", dias, mes, ano); //colocar o . para ele aceitar o zero

    //char d1, d2, m1, m2, a1, a2, a3, a4;
    //scanf("%c%c%c%c%c%c%c%c", &d1, &d2, &m1, &m2, &a1, &a2, &a3, &a4);
    //printf("%c%c/%c%c/%c%c%c%c\n", d1, d2, m1, m2, a1, a2, a3, a4);

    return 0;
}