#include <stdio.h>

int main(){
    char caracter; // 1 caracter = 8 bits (ASCII) = 1 byte
    int numero; // 16 ou 32 bits; short int = 8 ou 16 bits (metade)

    //%o = imprimir em octal
    //%x = imprimir em hex

    // 1: caracter -> ascii
    // 2: int -> caracter (ascii)
    // 3: int -> oct
    // 4: int -> hex

    scanf("%c %d", &caracter, &numero);

    printf("numero correspondente: %d\ncaracter correspondente: %c\noctal: %o\nhexadecimal: %x\n", caracter, numero, numero, numero);

    return 0;
}