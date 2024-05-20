#include <stdio.h>

int main(void){

    double S, X, fat, p;
    int n, k=1, l=0, m=1;

    scanf("%lf", &X);

    p = X;

    S = X;

    for (int j=1; j<=20; j++){

        // Fatorial (fat)
        while (k<=39){

            k = k+2;

            printf("K: %d\n", k);

            n = k;
            fat = n;

            for (int i=1; i<=(n-1); i++){
                fat = fat*(n-i);
            }

            printf("Fat final: %lf\n", fat);

            break;
        }
        
        // X², X⁴, ... (p)
        while(l<=40){
            l = l+2;
            printf("L: %d\n", l);
            while(m<l){
                m++;
                p=p*X;
            }
            printf("P final: %lf\n", p);
            break;
        }

        // Sinal positivo ou negativo
        if (j%2==0){
            S = S + (p/fat);
        }
        else {
            S = S - (p/fat);
        }
    }

    printf("%lf\n", S);

    return 0;
}