#include <stdio.h>

int main(void){

    int num_perg, vet_primos[1500000], num;

    for (int i=0; i<1500000; i++){
        vet_primos[i] = 0;
    }

    vet_primos[1] = 1;

    scanf("%d", &num_perg);

    // Crivo de Naoseioq :(
    for (int i=2; i<=1500000; i++){
        if (vet_primos[i] == 0){ //1 n eh primo, 0 eh primo
            for (int j=2; j*i<=1500000; j++){
                vet_primos[i*j] = 1;
            }
        }
    }

    //receber cada pergunta
    for (int i=0; i<num_perg; i++){
        scanf("%d", &num);
        if (vet_primos[num] == 0){
            printf("Sim\n");
        }
        else {
            printf("Nao\n");
        }
    }

    return 0;
}