#include <stdio.h>

int main (void){

    long long int n1, n2;

    scanf("%lld %lld", &n1, &n2);

    if (n1%2==0){ //n1 par
        printf("O primeiro número é par\n");
        if (n2%2==0){ //n2 par
            printf("O segundo número é par\n");
            printf("O número é %lld, que é par\n", n1*n2);
        }

        else{ //n2 impar
            printf("O segundo número é ímpar\n");
            printf("O número é %lld, que é ímpar\n", n1+n2);
        }

    }

    else { //n1 impar
        printf("O primeiro número é ímpar\n");
        if (n2%2==0){ //n2 par
            printf("O segundo número é par\n");
            printf("O número é %lld, que é ímpar", n1+n2);
        }

        else { // n2 impar
            printf("O segundo número é ímpar\n");
            printf("O número é %lld, que é par", n1*n2);
        }
    }

    return 0;
}