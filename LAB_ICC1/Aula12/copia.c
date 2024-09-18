#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*TAREFA
fazer um
programa em C que tem como entrada o nome do arquivo em bin´ario a ser clonado e deve retornar
todo o conte´udo do arquivo em formato de texto na tela

• Os nomes dos arquivos recebem uma formata¸c˜ao padr˜ao, sendo ”binario(n).bin”, onde 1 ≤ n ≤ 5.
• O tamanho do arquivo n˜ao ´e fornecido, ent˜ao vocˆe deve utilizar de fun¸c˜oes da biblioteca stdlib.h
para descobrir as informa¸c˜oes necess´arias para armazenar todo o cone´udo dinamicamente e
printar o texto na tela.
*/

/*LÓGICA
-> receber o nome do arquivo (dinamicamente)
-> abrir tal arquivo
-> printar o conteúdo dele
*/

int main(void){
    //Criação do vetor para guardar o nome do arquivo dinamicamente:
    char *pont_nome = (char *)malloc(20*sizeof(char));
    if (pont_nome == NULL){
        printf("Deu ruim no malloc\n");
        exit(1);
    }
    //Leitura do nome do arquivo:
    scanf("%[^\n]s", pont_nome);
    //Realocação do espaço alocado para o nome do arquivo
    pont_nome = (char *)realloc(pont_nome, (strlen(pont_nome)+1)*sizeof(char));
    if (pont_nome == NULL){
        printf("Deu ruim no realloc\n");
        exit(1);
    }
    pont_nome[strlen(pont_nome)] = '\0';

    FILE *fp; //ponteiro que apontará para o arquivo
    fp = fopen(pont_nome, "rb"); //abrindo no modo de leitura para binário
    if (fp == NULL){
        printf("Deu ruim ao abrir arquivo\n");
        exit(1);
    }
    free(pont_nome);
    pont_nome = NULL;
    
    char c;
    while(1){
        c = fgetc(fp);
        if (c == EOF){
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}