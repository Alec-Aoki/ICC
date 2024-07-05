#include <stdio.h>

int main(void){

    long int n, vet[100000], *p;

    p = &vet; //ponteiro apontando para vet[0]

    scanf(" %ld", &n);

    // preenchimento do vetor:
    for (long int i=0; i<n; i++){
        scanf(" %ld", p);
        p++;
    }

    p -= 1; //ponteiro apontando para vet[n] (-=1 por causa do p++ no for de cima)

    //imprimir o vetor ao contrario
    for (long int i=n; i>0; i--){
        printf("%ld ", *p);
        p--;
    }
    printf("\n");

    return 0;
}