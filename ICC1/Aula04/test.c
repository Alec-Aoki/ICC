#include <stdio.h>

int main(void){

    int X, p, l=0, m=1;

    scanf("%d", &X);

    p = X;

    while(l<=40){
            l = l+2;
            printf("L: %d\n", l);
            while (m<l){
                m++;
                printf("M: %d\n", m);
                p=p*X;
                printf("P: %d\n", p);
            }
            printf("P final: %d\n", p);
        }

    return (0);
}