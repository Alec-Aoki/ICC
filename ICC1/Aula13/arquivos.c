#include <stdio.h>
#include <stdlib.h>

int main (void){
    FILE *fp;
    fp = fopen("arquivo_daora.txt", "w+");
    if (fp == NULL){
        printf("Deu ruim no fopen\n");
        exit(1);
    }

    //Ler caracteres do teclado e jogar eles no arquivo:
    char caractere='0';
    while (caractere!='$'){
        scanf("%c", &caractere);
        //if (caractere!='$'){ //não vai printar o $
            fprintf(fp, "%c", caractere);
        //}
    }

    rewind(fp); //faz o ponteiro voltar para o início do arquivo
    caractere = '0';
    
    //Ler caracteres do arquivo e jogar eles na tela:
    while(caractere!='$'){ //enquanto não tiver chegado no fim do arquivo
    //note que feof retorna 1 se for o fim do arquivo, por isso a negação (!)
        fscanf(fp, "%c", &caractere); //lê um caractere do arquivo e guarda na variável caractere
        printf("%c", caractere);
    }
    printf("\n");
    fclose(fp);

    return 0;
}