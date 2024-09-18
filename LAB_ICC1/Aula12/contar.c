#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Implemente um programa em C que leia o nome de um arquivo de texto, e em seguida leia uma
palavra, de no m´aximo 10 caracteres, que ser´a buscada dentro do arquivo. O programa deve imprimir
quantas vezes essa palavra dentro do texto do arquivo.
Tenha em mente que a palavra pode aparecer mai´uscula ou min´uscula, e tamb´em seguida por
pontua¸c˜ao, n˜ao conte situa¸c˜oes em que a palavra aparece dentro de outra palavra
*/

int main(void){
    //Alocação dinâmica do nome do arquivo
    char *nome_arq = (char *)malloc(20*sizeof(char));
    if(nome_arq == NULL) exit(1);
    scanf(" %s", nome_arq);
    nome_arq = (char *)realloc(nome_arq, strlen(nome_arq)*sizeof(char));
    if(nome_arq == NULL) exit(1);

    //Alocação dinâmica da palavra
    char *palavra = (char *)malloc(20*sizeof(char));
    if(palavra == NULL) exit(1);
    scanf(" %s", palavra);
    palavra = (char *)realloc(palavra, strlen(palavra)*sizeof(char));
    if(palavra == NULL) exit(1);
    int tam_palavra = (int)strlen(palavra);

    nome_arq[strlen(nome_arq)] = '\0';
    palavra[tam_palavra] = '\0';


    //Abertura do arquivo:
    FILE *fp;
    fp = fopen(nome_arq, "a+");
    if (fp == NULL) exit(1);
    rewind(fp);

    //Pegando o tamanho do arquivo:
    fseek(fp, 0, SEEK_END);
    int tam_arq = ftell(fp);
    rewind(fp);

    char *pont_string = (char *)malloc((tam_arq+1)*sizeof(char));
    if(pont_string == NULL) exit(1);
    
    fread(pont_string, sizeof(char), tam_arq, fp);
    pont_string[tam_arq] = '\0';
    //pont_string é um vetor que agora contém os caracteres guardados no arquivo binário

    /*
    Temos agora o conteúdo do arquivo e a palavra a ser encontrada
    Vamos transformar todo o vetor contendo o conteúdo do arquivo em letras minúsculas e aí comparar as strings
    Para isso vamos usar a função tolower() da biblioteca <ctype.h>
    */

   char *pont_p = NULL;
   int cont_palavras = 0;

   while(1){
        pont_p = strstr(pont_string, palavra);
        if(pont_p == NULL){
            break;
        }
        if(pont_p == pont_string){ //Palavra no começo
            if((pont_p[tam_palavra+1]<97) || (pont_p[tam_palavra+1]>122) || (pont_p[tam_palavra+1] == ' ')){
                cont_palavras++;
            }
        }
        else if((&(pont_p[tam_palavra])) == (&(pont_string[tam_arq]))){ //Palavra no fim
            if((pont_p[-1]<97) || (pont_p[-1]>122) || (pont_p[-1] == ' ')){
                cont_palavras++;
            }
        }
        else{ //Palavra no meio
            if(((pont_p[tam_palavra+1]<97) || (pont_p[tam_palavra+1]>122) || (pont_p[tam_palavra+1] == ' ')) && ((pont_p[-1]<97) || (pont_p[-1]>122) || (pont_p[-1] == ' '))){
                cont_palavras++;
            }
        }
        pont_p[0] = '@';
   }

   printf("\n%s\n", pont_string);

   printf("quantidade: %d\n", cont_palavras);

    fclose(fp);
    free(nome_arq);
    free(palavra);
    free(pont_string);
    return 0;
}