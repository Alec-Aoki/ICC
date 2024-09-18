#include <stdio.h>
#include <string.h>

/*
Implemente um programa em C que recebe um inteiro n, seguido de n palavras. Vocˆe deve
implementar uma fun¸c˜ao que cheque se cada palavra ´e ou n˜ao um palindromo, e imprimir na sa´ıda da
maneira demonstrada a seguir seguido por uma quebra de linha.
*/

int eh_palindromo(int tamanho, char *palavra_local){
    //palavra local vai apontar para o inicio de cada palavra no vetor
    for (int i=1; i<=tamanho; i=i+2){ //como o ponteiro anda 1 pra frente, o i tem que voltar sempre ele+2 pra trás
    //pra chegar no caractere espelhado
        if (*palavra_local == *(palavra_local+(tamanho-i))){
            //checa se caracteres espelhados de cada lado do vetor sao iguais
            palavra_local++;
        }
        else{
            return 1; // se caracteres espelhados de cada lado do vetor forem diferentes, ele ja nao eh palindromo
        }
    }
    return 0; //se ele nao caiu no return 1 ate o fim do loop, ent ele eh palindromo
}


int main(void){
    int n, tamanho; //n=numero de palavras
    char palavra[100];

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        //leitura da palavra (so uma)
        scanf("%s", palavra);
        tamanho = strlen(palavra);

        if (eh_palindromo(tamanho, palavra) == 1){
            printf("%s nao eh um palindromo\n", palavra);
        }
        else {
            printf("%s eh um palindromo\n", palavra);
        }
    }
    return 0;
}