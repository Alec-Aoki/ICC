#include <stdio.h>

int main (void){

    int bits1, bits2, valor=0;
    int dec1=0, dec2=0;
    float casa = 0.5;
    
    scanf("%d %d", &bits1, &bits2);

    for (int i=bits1; i>0; i--){
        casa = casa*2;
    }

    for(int i=casa; i>=1; i=i/2){
        scanf("%d", &valor);
        dec1 = dec1 + valor*i;
    }

    casa = 0.5;

    for (int i=bits2; i>0; i--){
        casa = casa*2;
    }

    for(int i=casa; i>=1; i=i/2){
        scanf("%d", &valor);
        dec2 = dec2 + valor*i;
    }

    printf("%d\n", dec1+dec2);

    return(0);
}