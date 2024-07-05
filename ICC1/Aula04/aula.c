#include <stdio.h>

/*FATORIAL*/

int main (void){

    unsigned long long int n, acum=1;

    scanf("%llu", &n);

    while (n>0){
        acum = acum*n;
        n--;
    }

    printf("%llu\n", acum);

    return (0);
}