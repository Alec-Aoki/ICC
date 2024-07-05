#include <stdio.h>

    /*
    Se a palavra tiver uma quantidade par de caracteres:
        verificar se cada caractere tem um par/correspondente
            se sim: Sim
            se nao: Nao
    Senão (quant. impar de carac.):
        verificar se cada caractere tem um par/correspondente
        verificar se ha somente um desses caracteres que eh imapr
    */

int main(void){

    int quant_car, temp, letras[26], cont=0;
    char str[100000];

    for (int i=0; i<26; i++){
        letras[i] = 0;
    }

    scanf("%d", &quant_car);
    temp = quant_car;

    for (int i=0; i<quant_car; i++){
        scanf(" %c", &str[i]);
        letras[str[i]-97]++;
    }

    if (quant_car%2==0){
        //par
        for (int i=0; i<26; i++){
            if (letras[i]%2!=0){ //temos uma letra com quant. de ocorrencias impar, entao nao forma palindromo
                printf("Nao\n");
                return 0;
            }
        }
        printf("Sim\n"); //como ja saimos do programa caso fosse Nao, qualquer outro caso eh Sim
    }
    else {
        //impar
        for (int i=0; i<26; i++){
            if (letras[i]%2!=0){
                cont++; //cont so pode ser 1 para ser palindromo (else abaixo)
            }
        }
        if (cont>1){ //se tem mais de uma letra com ocorrencias impar, nao pode ser palindromo
            printf("Nao\n");
        }
        else {
            printf("Sim\n"); 
        }
    }

    return 0;
}