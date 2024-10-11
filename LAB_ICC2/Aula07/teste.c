#include <stdio.h>

int main(void){
    int inicio, fim;
    scanf("%d %d", &inicio, &fim);

    int tam = (fim-inicio)+1;
    int doisTercos = (int)((2*tam)/3);
    if((2*tam)%3 != 0){
        printf("Arrendondado pra cima\n");
        doisTercos++;
    }

    printf("%d\n", doisTercos);

    return 0;
}