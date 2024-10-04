#include <stdio.h>

int main(void){
    int quant_Elementos;
    scanf("%d", &quant_Elementos);
    int vet[quant_Elementos];
    
    /*lendo a entrada e jogando no vetor*/
    for(int i=0; i<quant_Elementos; i++){
        scanf("%d", &vet[i]);
    }

    /*verificando se é uma heap max*/
    for(int i=1; i<quant_Elementos; i++){
        int indicePai = (i-1)/2;

        if(vet[indicePai] < vet[i]){
            printf("Não eh uma heap max\n");
            return 0;
        }
    }

    printf("Eh uma heap max\n");

    return 0;
}