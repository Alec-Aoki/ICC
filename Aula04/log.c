#include <stdio.h>

int main(void){

    double x, k=1;
    int n=0;

    scanf("%lf", &x);

    while (k<x){
        k=k*2;
        n++;
    }

    printf("%d\n", n);

    return(0);
}