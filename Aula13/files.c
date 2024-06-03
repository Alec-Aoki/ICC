#include <stdio.h>
#include <stdlib.h>

/*ARQUIVOS

MODOS DE ABERTURA DE ARQUIVO:
    w -> write
    r -> read
    a -> adicionar conteúdo
    r+ -> read and write
    w+ -> read and write, apaga o conteúdo do arquivo
    a+ -> read and write, adicionando conteúdo
*/

int main(void){
    FILE *ponteiro_arq; //ponteiro para arquivo
    
    ponteiro_arq = fopen("teste.txt", "w+");
    // a função fopen "conecta" nosso programa a um arquivo
    if (ponteiro_arq == NULL){
        printf("Deu ruim no fopen\n");
        exit(1);
    }

    //ESCREVER NO ARQUIVO
    printf("Digite que sera escrito no arquivo:\n");
    char letra='0';

    while (letra!='\n'){
        scanf("%c", &letra);
        fputc(letra, ponteiro_arq);
        //a função fputc coloca a variável no arquivo
    }

    //LER NO ARQUIVO
    rewind(ponteiro_arq); //volta o ponteiro para o início do arquivo
    while(!feof(ponteiro_arq)){
        //feof verifica se chegou no fim do arquivo
        //ele retorna 1 se chegou
        letra = fgetc(ponteiro_arq);
        //fgetc pega um caractere e o atribui para letra
        printf("%c", letra);
    }
    fclose(ponteiro_arq);
    //sempre temos que fechar o arquivo

    return 0;
}