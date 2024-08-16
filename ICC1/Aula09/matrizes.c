#include <stdio.h>

int main(void){
    int soma=0, matriz[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        }; // == {1,2,3,4,5,6,7,8,9,10,11,12}

    for (int linha=0; linha<3; linha++){
        for (int coluna=0; coluna<4; coluna++){
            soma = soma + matriz[linha][coluna];
        }
    }
    printf("%d\n", soma);

    return 0;
}