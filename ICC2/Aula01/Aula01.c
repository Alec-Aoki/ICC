#include <stdio.h>
#include <time.h>

// void imprimirRec(int vetor[], int tamanho, int i){
//     if(i < 0)
//         return;
//     printf("%d ", vetor[i]);
//     imprimirRec(vetor, tamanho, i-1);
// }

// unsigned long int fatorial(unsigned long int n){
//     if((n == 1) || (n == 0))
//         return 1;
//     return (n*fatorial(n-1));
// }

unsigned long int fibonacci(unsigned long int n){
    if(n < 2)
        return 1;

    return(fibonacci(n-1) + fibonacci(n-2));
}

int main(void){
    clock_t inicio, fim;

    //Imprimir
    //int v[] = {1, 2, 3};
    //imprimirRec(v, 3, 2);
    //printf("\n");

    //Fatorial
    // inicio = clock();
    // printf("%ld\n", fatorial(20));
    // fim = clock();
    // printf("Tempo de execucao: %lfms\n", (double)(fim-inicio)/CLOCKS_PER_SEC);

    inicio = clock();
    printf("%ld\n", fibonacci(40));
    fim = clock();

    printf("Tempo de execucao: %lfms\n", (double)(fim-inicio)/CLOCKS_PER_SEC);

    return 0;
}