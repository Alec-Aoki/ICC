#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Vocˆe encontrou um conjunto de arquivos bin´arios do mestre Rafito dinamite. Esses arquivos
possuem conselhos valiosos. por´em o arquivo foi invadido com uma palavra invasora. Vocˆe decide
fazer um programa para limpar esse arquivo, o programa receber´a a palavra invasora, seguida pelo
nome do arquivo de entrada, que ser˜ao no formato binn.bin, onde estar´a o texto a ser lido, e dever´a
imprimir o texto sem a palavra invasora
*/

int main(void){
    //Alocação dinâmica da palavra
    char *pont_palavra = (char *)malloc(20*sizeof(char));
    if(pont_palavra == NULL) exit(1);
    scanf(" %s", pont_palavra);
    pont_palavra = (char *)realloc(pont_palavra, strlen(pont_palavra)*sizeof(char));
    if(pont_palavra == NULL) exit(1);
    int tam_palavra = (int)strlen(pont_palavra);


    //Alocação dinâmica do nome do arquivo
    char *pont_nomearq = (char *)malloc(20*sizeof(char));
    if(pont_nomearq == NULL) exit(1);
    scanf(" %s", pont_nomearq);
    pont_nomearq = (char *)realloc(pont_nomearq, strlen(pont_nomearq)*sizeof(char));
    if(pont_nomearq == NULL) exit(1);

    //Abertura do arquivo:
    FILE *fp;
    fp = fopen(pont_nomearq, "a+");
    if (fp == NULL) exit(1);
    rewind(fp);

    //Pegando o tamanho do arquivo:
    fseek(fp, 0, SEEK_END);
    int tam_arq = ftell(fp);
    rewind(fp);


    /*Achar a palavra no arquivo
    -> vamos percorrer o arquivo comparando string por string com a palavra
    -> para isso, vamos ter que ter uma string grandona para guardar as strings do arquivo
    */
    char *pont_string = (char *)malloc((tam_arq+1)*sizeof(char));
    if(pont_string == NULL) exit(1);

    fread(pont_string, sizeof(char), tam_arq, fp);
    pont_string[tam_arq] = '\0';
    //pont_string é um vetor que agora contém os caracteres guardados no arquivo binário

    char *pont_p = NULL;
    pont_p = strstr(pont_string, pont_palavra);

    //Ajustando o tamanho da palavra invasora:
    while(*(pont_p+tam_palavra) == ' '){
        tam_palavra++;
    }

    //Removendo o tamanho da palavra invasora:
    memmove(pont_p, pont_p+tam_palavra, strlen(pont_p+tam_palavra)+1);

    //Printando o conteúdo do arquivo sem a palavra
    printf("%s\n", pont_string);

    fclose(fp);
    free(pont_nomearq);
    free(pont_palavra);
    return 0;
}