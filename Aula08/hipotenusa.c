#include <stdio.h>

float hipotenusa(float n1, float n2){
    float res;
    for (res=0.00001; res*res <= (n1*n1) + (n2*n2); res=res+0.00001){
        ;
    }

    return res;
}

int main (void){
    float l1, l2;

    scanf("%f %f", &l1, &l2);

    printf("%.4f\n", hipotenusa(l1, l2));

    return 0;
}