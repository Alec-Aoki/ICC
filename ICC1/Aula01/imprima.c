#include <stdio.h>

/*
como 0 <= n <= 18446744073709551615, iremos usar um unsigned long long int, que comporta exatamente esse espectro de valores
*/

int main(void){

    unsigned long long int n;

    scanf("%llu", &n);

    printf("%llu\n", n);

    return (0);
}