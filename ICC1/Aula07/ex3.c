#include <stdio.h>

int main(void){

    int vet[100], aux, n;

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    for (int l=0; l<n; l++){
        for (int j=1; j<n; j++){
            if (vet[j]<=vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }

    printf("\n");

    for (int k=0; k<n; k++){
        printf("%d\n", vet[k]);
    }

    return 0;
}