#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALEC CAMPOS AOKI, 15436800
NEWTON - BOTA TEU SOBRENOME E N USP AQ
JUAN - VC TMB

INTRUÇÕES
-> armazenamos todas as informações na memória do programa
-> lemos as informações do arquivo somente no começo do dia
    -> qualquer comando diferente de AV, FD e FV
    -> a fazer
-> salvamos as informações no arquivo somente no fim do programa
    -> função FV ou FD
    -> guardar as informações nos vetores adequados, como mencionado no docs
    -> NÃO É PRA IR CRIANDO VETORES A RODO SENÃO VIRA VÁRZEA
        -> me perguntem plmds
*/

/*STRUCT PASSAGEIRO*/
typedef struct{
    char *nome; //Ponteiro que apontará para o vetor de chars (string) nome na heap
    char *sobrenome; // ^
    char CPF[12]; //CPF DE 11 dígitos + /0. Como o tamanho do CPF é sempre o mesmo, não vamos alocá-lo dinamicamente
    char *assento; //Ponteiro que apontará para o vetor de chars (string) assento na heap
    char classe; //'C' para econômica, 'X' para executiva
}passageiro;

/*HEADER ARQUIVO
01 %d %d %d %d | quant. de assentos totais, preço das passagens e quant. de assentos disponíveis, respect.
*/

/*Função de abertura do vôo - AV*/
void Abrir_Voo(int *pont_info_voo){
    /*Lendo os valores:
    [0] = Quant. de assentos TOTAL
    [1] = Quant. de assentos DISPONÍVEIS
    [3] = Valor econômica
    [3] = Valor executiva
    */
    scanf(" %d %d %d", &pont_info_voo[0], &pont_info_voo[2], &pont_info_voo[3]);
    pont_info_voo[1] = pont_info_voo[0]; //Na abertura do voo, a quant. de assentos disp = total
    return;
}

/*Função de fechamento do dia - FV*/
void Fim_Dia(FILE *pont_arq, int *pont_info_voo){
    /*Abertura do arquivo*/
    //Vamos abrir no modo w para escrevermos as informações nele
    pont_arq = fopen("voo.txt", "w");
    if (pont_arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    /*Escrevendo as informações do vôo no arquivo*/
    fprintf(pont_arq, "%d %d %d %d", pont_info_voo[0], pont_info_voo[1], pont_info_voo[2], pont_info_voo[3]);

    fclose(pont_arq);
    return;
}

/*Função de realizar reserva - RR*/
/* NÃO TERMINADA*/
void Realizar_Reserva(int *point_info_voo, passageiro *pont_vet_passageiros, int cont_passageiros){
    //Realocando a memória na heap para criarmos um novo espaço para o passageiro:
    pont_vet_passageiros = (passageiro *)realloc(pont_vet_passageiros, (sizeof(passageiro)*cont_passageiros));
    if (pont_vet_passageiros == NULL){
        printf("Erro ao realocar\n");
        exit(1);
    }

    //Reduzindo em 1 a quantidade disponível de assentos no vôo:
    point_info_voo[1]--;

    //Recebendo as informações do passageiro e guardando elas no vetor:
    //Nome:
    char string_temp[100] = "0"; //Vetor temporário para guardarmos caracteres
    scanf(" %s", &string_temp);
    //O ponteiro nome do passageiro agora aponta para um espaço na heap:
    pont_vet_passageiros[cont_passageiros-1].nome = (char *)malloc(strlen(string_temp)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].nome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    for (int i=0; i<=strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].nome[i] = string_temp[i];
    }

    //Sobrenome:
    scanf(" %s", &string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    pont_vet_passageiros[cont_passageiros-1].sobrenome = (char *)malloc(strlen(string_temp)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].sobrenome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    for (int i=0; i<strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].sobrenome[i] = string_temp[i];
    }

    //CPF:
    scanf(" %s", &pont_vet_passageiros[cont_passageiros-1].CPF);

    //Assento:
    scanf(" %s", &string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    pont_vet_passageiros[cont_passageiros-1].assento = (char *)malloc(strlen(string_temp)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].assento == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    for (int i=0; i<strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].assento[i] = string_temp[i];
    }

    //Classe:
    scanf(" %c", &pont_vet_passageiros[cont_passageiros-1].classe);

    /*TESTE - APAGAR DEPOIS*/
    printf("Nome: %s\n", pont_vet_passageiros[cont_passageiros-1].nome);
    printf("Sobrenome: %s\n", pont_vet_passageiros[cont_passageiros-1].sobrenome);
    printf("CPF: %s\n", pont_vet_passageiros[cont_passageiros-1].CPF);
    printf("Assento %s\n", pont_vet_passageiros[cont_passageiros-1].assento);
    printf("Classe: %c\n", pont_vet_passageiros[cont_passageiros-1].classe);
    return;
}

int main(void){
    FILE *pont_arq = NULL; //pont_arq será o ponteiro que usaremos para manipular o arquivo

    /*CONTADOR DE COMANDOS
    -> Vamos usar esse contador para saber quando temos que ler o arquivo
    -> Se o contador for 0, vamos ler o arquivo
    -> Senão, não o lemos
    */
    int cont_comandos = 0;

    /*INFORMAÇÕES PASSAGEIROS*/
    int cont_passageiros = 0; //contador que vai guardar a quant. de passageiros no voo
    passageiro *pont_vet_passageiros = (passageiro *)malloc(sizeof(passageiro));
    // ^: ponteiro que vai apontar para o início do vetor de passageiros na heap

    /*INFORMAÇÕES DO VOO*/
    int info_voo[4];
    /*
    [0] = Quant. de assentos TOTAL
    [1] = Quant. de assentos DISPONÍVEIS
    [3] = Valor econômica
    [3] = Valor executiva*/
    int *pont_info_voo = &info_voo[0];

    /*RECEBER O COMANDO*/
    //Criando o vetor de chars (string) do comando na heap:
    char comando[3];
    
    //Vamos usar a função strcmp() para saber qual comando foi digitado
    //Nota: ela retorna 0 se as string forem iguais
    do {
        scanf( "%s", comando);

        if (cont_comandos == 0){
            //Precisamos ler as informações do arquivo e jogar elas nos vetores
            pont_arq = fopen("voo.txt", "r");
            if (pont_arq == NULL){
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            // Informações do voo:
            fscanf(pont_arq, "%d %d %d %d", &info_voo[0], &info_voo[1], &info_voo[2], &info_voo[3]);
            fclose(pont_arq);
        }

        /*ABERTURA DO VOO - AV*/
        if (strcmp(comando, "AV") == 0){
            Abrir_Voo(pont_info_voo);
        }

        /*REALIZAR RESERVA - RR*/
        else if (strcmp(comando, "RR") == 0){
            cont_passageiros++;
            Realizar_Reserva(pont_info_voo, pont_vet_passageiros, cont_passageiros);
        }
        cont_comandos++;
    } while((strcmp(comando, "FD") != 0) && (strcmp(comando, "FV") != 0));

    /*FIM DO DIA - FD*/
    if (strcmp(comando, "FD") == 0){
        /*Vamos gravar as informações no arquivo e sair do programa*/
        Fim_Dia(pont_arq, pont_info_voo);
    }
    return 0;
}
