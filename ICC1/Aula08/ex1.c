#include <stdio.h>

void leia_e_ordene(int *num1, int *num2, int *num3){
    int vet[3], aux;
    scanf("%d %d %d", num1, num2, num3);
    vet[0] = *num1;
    vet[1] = *num2;
    vet[2] = *num3;
    //Bubble sort para ordenação do vetor:
    for (int i=0; i<=3; i++){
        for (int j=1; j<3; j++){
            if(vet[j]<vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }
    *num1 = vet[0];
    *num2 = vet[1];
    *num3 = vet[2];

    return;
}

int main(void){
    int n1, n2, n3;

    leia_e_ordene(&n1, &n2, &n3);

    printf("%d %d %d\n", n1, n2, n3);

    return 0;
}