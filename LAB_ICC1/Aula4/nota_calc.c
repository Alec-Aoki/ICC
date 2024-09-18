#include <stdio.h>

int main (void){

    float p1, p2, plista1, plista2, plista3, plista4, nlistas, nfinal;

    scanf("%f %f %f %f %f %f", &p1, &p2, &plista1, &plista2, &plista3, &plista4);

    nlistas = (plista1 + plista2 + plista3 + plista4)/4;

    nfinal = (p1+p2+nlistas)/3;

    if (nfinal<3 || nlistas==0){
        printf("Reprovado\n");
    }
    else if (nfinal>=3 && nfinal<5){
        printf("Recuperacao\n");
    }
    else {
        printf("Aprovado\n");
    }
    return(0);
}