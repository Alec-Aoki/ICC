#include <stdio.h>

int main(void){

    int n, *p, **po;

    scanf("%d", &n);

    printf("Valor inicial da variavel: %d\n", n);
    p = &n;
    printf("Valor do ponteiro antes do incremento: %d\n", *p);
    po = &p;
    *p = *p+10;
    printf("Valor do ponteiro depois do incremento: %d\n", *p);
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **po);
    **po = **po + 10;
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", **po);
    printf("Valor final da variavel: %d\n", n);

    return 0;
}