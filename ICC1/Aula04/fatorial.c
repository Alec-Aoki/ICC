#include <stdio.h>

/*
Ler N;
Dividir N por 5;
Pegar a parte inteira;
Contador = Contador + parte inteira;
Repetir até parte inteira == 0;
*/

int main (void){

    unsigned int N, contador=0;


    scanf("%u", &N);

    while (N!=0){
        N = N/5;
        contador = contador + N;
    }
    printf("%u\n", contador);

    return(0);
}