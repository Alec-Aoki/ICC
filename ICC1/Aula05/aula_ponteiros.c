#include <stdio.h>

int main(void){

    int *p;

    {
        int a=2024;
        p = &a; //p recebe o endereço de a
    }

    printf("%d\n", *p); //escreve o conteúdo armazenado no endereço que está armazenado em p

    return (0);
}