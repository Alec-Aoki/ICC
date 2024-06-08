#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALEC CAMPOS AOKI, 15436800
NEWTON - BOTA TEU SOBRENOME E N USP AQ
JUAN - VC TMB
*/

/*STRUCT PASSAGEIRO*/
typedef struct{
    char *nome; //Ponteiro que apontará para o vetor de chars (string) nome na heap
    char *sobrenome; // ^
    char CPF[12]; //CPF DE 11 dígitos + /0. Como o tamanho do CPF é sempre o mesmo, não vamos alocá-lo dinamicamente
    char assento[100]; //COMO VAMOS DEFINIR O TAMANHO DO VETOR DO ASSENTO?????
    char classe[1]; //'C' para econômica, 'X' para executiva
}passageiro;

/*HEADER ARQUIVO
01 %d %d %d | três inteiros representando a quant. de assentos totais, o preco da econom. e o preco da exec., respect.
02 $%c[9] $%c[] | data do vôo "DDMMAAAA\0" e código do voo, demarcados pelo caractere '$' antes deles
03 '$'%c[] '$'%c[] | origem e destino do vôo,                      ^
*/

/*Função para checar se abrimos o arquivo corretamente*/
int Cheque_Arq(FILE *pont_arq){
    if (pont_arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    else {
        return 0;
    }
}

/*Função de abertura do vôo - AV*/
void Abertura_Voo(FILE *pont_arq){
    //Recebemos como parâmetro o ponteiro que aponta para o começo do arquivo
    int quant_assentos;
    int preco_economica;
    int preco_executiva;
    //Lendo os valores:
    scanf(" %d %d %d", &quant_assentos, &preco_economica, &preco_executiva);
    //Escrevendo os valores no arquivo:
    fprintf(pont_arq, "%d %d %d", quant_assentos, preco_economica, preco_executiva);
    return;
}

/*Função de realizar reserva - RR*/
/* NÃO TERMINADA*/
/*void Realizar_Reserva(FILE *pont_arq, passageiro *pont_vet_passageiros, int cont_passageiros){
    //Realocando a memória na heap para criarmos um novo espaço para o passageiro:
    pont_vet_passageiros = (passageiro *)realloc(pont_vet_passageiros, (sizeof(passageiro)*cont_passageiros));
    //Recebendo as informações do passageiro e guardando elas no vetor:
    //Nome:
    //Sobrenome:
    //CPF:
    scanf(" %s", pont_vet_passageiros[cont_passageiros-1].CPF);
    //Assento: 
    scanf(" %s", pont_vet_passageiros[cont_passageiros-1].assento);
    //Classe:
    //AINDA TEM UNS BAGULHO PRA DAR SCANF, NN TANKEI,  VOU DORMIR
    return;
}*/

int main(void)
{
    FILE *pont_arq = NULL; //pont_arq será o ponteiro que usaremos para manipular o arquivo
    int cont_passageiros = 0; //contador que vai guardar a quant. de passageiros no voo
    passageiro *pont_vet_passageiros = (passageiro *)malloc(sizeof(passageiro)); 
    // ^: ponteiro que vai apontar para o início do vetor de passageiros na heap

    /*RECEBER O COMANDO*/
    //Criando o vetor de chars (string) do comando na heap:
    char *comando = (char *)malloc(sizeof(char)*3);
    if (comando == NULL){
        printf("Deu ruim no malloc do comando\n");
        return 1;
    }

    //Inicializando a string comando para não termos lixo:
    strcpy(comando, "00");
    
    //Vamos usar a função strcmp() para saber qual comando foi digitado
    //Nota: ela retorna 0 se as string forem iguais
    while((strcmp(comando, "FD") != 0) && (strcmp(comando, "FV") != 0)){
        scanf( "%s", comando);
        /*ABERTURA DO VOO - AV*/
        if (strcmp(comando, "AV") == 0){
            //Vamos abrir o arquivo no modo w, pois pretendemos criar e escrever nele
            pont_arq = fopen("voo.txt", "w");
            Cheque_Arq(pont_arq);
            Abertura_Voo(pont_arq);
            fclose(pont_arq);
        }
        /*Realização de Reserva - RR*/
        /*else if (strcmp(comando, "RR") == 0){
            cont_passageiros++;
            //Vamos abrir o arquivo no modo a, pois pretendemos escrever nele, começando do final
            pont_arq = fopen("voo.txt", "a");
            Cheque_Arq(pont_arq);
            Realizar_Reserva(pont_arq, pont_vet_passageiros, cont_passageiros);
            fclose(pont_arq);
        }*/
    }
    free(comando);
    return 0;
}
