#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALEC CAMPOS AOKI - 15436800
NEWTON - BOTA TEU SOBRENOME E N USP AQ
JUAN HENRIQUES PASSOS - 15464826
*/

/*HEADER ARQUIVO
01 %d %d %f %f | quant. de assentos totais, quant. de assentos disponíveis e preço das passagens, respect.
02 %c[4] %c[4] %c[11] %c[5] | origem, destino, data e número do voo, respect.
*/

/*STRUCT PASSAGEIRO*/
typedef struct{
    char *nome; //Ponteiro que apontará para o vetor de chars (string) nome na heap
    char *sobrenome; // ^
    char CPF[15]; //CPF DE 11 dígitos + . . - +/0. Como o tamanho do CPF é sempre o mesmo, não vamos alocá-lo dinamicamente
    char *assento; //Ponteiro que apontará para o vetor de chars (string) assento na heap
    char classe[10]; //'C' para econômica, 'X' para executiva
}passageiro;

/*STRUCT VOO*/
//Contém as informações sobre o voo
typedef struct{
    int assentos_total; //Quantidade de assentos total
    int assentos_disp; //Quantidade de assentos disponível
    float preco_economica; //Preço da econômica
    float preco_executiva; //Preço da executiva
    char data[11]; //String que guarda a data da viagem
    char origem[4]; //String do nome da origem, sigla de 3 letras + \0
    char destino[4]; // ^
    char numero[5]; //String que vai guardar o código do voo
}aviao;

/*Função de abertura do vôo - AV*/
void Abrir_Voo(aviao voo){
    scanf(" %d %f %f", &(voo.assentos_total), &(voo.preco_economica), &(voo.preco_executiva));
    //quant. assentos, valor economica, valor executiva
    voo.assentos_disp = voo.assentos_total; //Na abertura do voo, a quant. de assentos disp = total
    return;
}

/*Função de fechamento do dia - FV*/
void Fim_Dia(FILE *pont_arq, aviao voo){
    /*Abertura do arquivo*/
    //Vamos abrir no modo w para escrevermos as informações nele
    pont_arq = fopen("voo.txt", "w");
    if (pont_arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    /*HEADER ARQUIVO
    01 %d %d %f %f | quant. de assentos totais, quant. de assentos disponíveis e preço das passagens, respect.
    02 %c[4] %c[4] %c[11] %c[5] | origem, destino, data e número do voo, respect.
    */

    /*Escrevendo as informações do vôo no arquivo*/
    fprintf(pont_arq, "%d %d %f %f\n", voo.assentos_total, voo.assentos_disp, voo.preco_economica, voo.preco_executiva);
    fprintf(pont_arq, "%s %s %s %s\n", voo.origem, voo.destino, voo.data, voo.numero);

    fclose(pont_arq);
    return;
}

/*Função de realizar reserva - RR*/
void Realizar_Reserva(aviao *voo, passageiro *pont_vet_passageiros, int cont_passageiros){
    //Realocando a memória na heap para criarmos um novo espaço para o passageiro:
    pont_vet_passageiros = (passageiro *)realloc(pont_vet_passageiros, (sizeof(passageiro)*cont_passageiros));
    if (pont_vet_passageiros == NULL){
        printf("Erro ao realocar\n");
        exit(1);
    }

    //Reduzindo em 1 a quantidade disponível de assentos no vôo:
    voo->assentos_disp--;

    //Recebendo as informações do passageiro e guardando elas no vetor:
    //Nome:
    char string_temp[100] = "0"; //Vetor temporário para guardarmos caracteres
    scanf(" %s", string_temp);
    //O ponteiro nome do passageiro agora aponta para um espaço na heap:
    //nota-se que o +1, faz referencia ao '\0'.
    pont_vet_passageiros[cont_passageiros-1].nome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].nome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //observe-se que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'.
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].nome[i] = string_temp[i];
    }

    //Sobrenome:
    scanf(" %s", string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    //nota-se que o +1, faz referencia ao '\0'.
    pont_vet_passageiros[cont_passageiros-1].sobrenome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].sobrenome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //observe-se que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'.
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].sobrenome[i] = string_temp[i];
    }

    //CPF:
    scanf(" %s ", pont_vet_passageiros[cont_passageiros-1].CPF);

    //Data Viagem:
    fgets(voo->data, 11, stdin);
    voo->data[strcspn(voo->data, " ")] = '/';
    voo->data[strcspn(voo->data, " ")] = '/';
    voo->data[10] = '\0';

    //Número do Voo):
    scanf(" %s", voo->numero);
    voo->numero[4] = '\0';

    //Assento:
    scanf(" %s", string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    //nota-se que o +1 faz referencia ao '\0'.
    pont_vet_passageiros[cont_passageiros-1].assento = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if (pont_vet_passageiros[cont_passageiros-1].assento == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //nota-se que de zero até strlen(string_temp) entrará o assento mais o '\0'.
    for(long unsigned int i=0; i<=strlen(string_temp); i++){
        pont_vet_passageiros[cont_passageiros-1].assento[i] = string_temp[i];
    }

    //Classe:
    scanf(" %s", pont_vet_passageiros[cont_passageiros-1].classe);

    //Valor:
    scanf(" %s", string_temp);

    //Origem:
    scanf(" %s", voo->origem);
    voo->origem[3] = '\0';

    //Destino:
    scanf(" %s", voo->destino);
    voo->destino[3] = '\0';

    /*TESTE - APAGAR DEPOIS*/
    /*
    printf("Nome: %s\n", pont_vet_passageiros[cont_passageiros-1].nome);
    printf("Sobrenome: %s\n", pont_vet_passageiros[cont_passageiros-1].sobrenome);
    printf("CPF: %s\n", pont_vet_passageiros[cont_passageiros-1].CPF);
    printf("Data viagem: %s\n", voo->data);
    printf("Numero do voo: %s\n", voo->numero);
    printf("Assento: %s\n", pont_vet_passageiros[cont_passageiros-1].assento);
    printf("Classe: %s\n", pont_vet_passageiros[cont_passageiros-1].classe);
    if(strcmp(pont_vet_passageiros[cont_passageiros-1].classe, "economica") == 0){
        printf("Valor: %f\n", voo->preco_economica);
    }
    else {
        printf("Valor: %f\n", voo->preco_executiva);
    }
    printf("Origem: %s\n", voo->origem);
    printf("Destino: %s\n", voo->destino);*/
    return;
}

int main(void){
    FILE *pont_arq = NULL; //pont_arq será o ponteiro que usaremos para manipular o arquivo

    /*INFORMAÇÕES PASSAGEIROS*/
    int cont_passageiros = 0; //contador que vai guardar a quant. de passageiros no voo
    passageiro *pont_vet_passageiros = (passageiro *)malloc(sizeof(passageiro));
    // ^: ponteiro que vai apontar para o início do vetor de passageiros na heap

    aviao voo;

    /*RECEBER O COMANDO*/
    //Criando o vetor de chars (string) do comando na heap:
    char comando[3];
    
    //Vamos usar a função strcmp() para saber qual comando foi digitado
    //Nota: ela retorna 0 se as string forem iguais
    do {
        scanf( "%s", comando);
        //Verificamos se o arquivo está aberto, se ele aponta para nulo, abrimos o arquivo
        if (pont_arq == NULL){
            //Lendo as informações do arquivo e jogar elas nos vetores
            pont_arq = fopen("voo.txt", "r");
            if (pont_arq == NULL){
                printf("Erro ao abrir arquivo\n");
                exit(1);
            }
            // Informações do voo:
            fscanf(pont_arq, "%d %d %f %f", &voo.assentos_total, &voo.assentos_disp, &voo.preco_economica, &voo.preco_executiva);
            fscanf(pont_arq, "%s %s %s %s", voo.origem, voo.destino, voo.data, voo.numero);
            fclose(pont_arq);
        }

        /*ABERTURA DO VOO - AV*/
        if (strcmp(comando, "AV") == 0){
            Abrir_Voo(voo);
        }

        /*REALIZAR RESERVA - RR*/
        else if (strcmp(comando, "RR") == 0){
            cont_passageiros++;
            Realizar_Reserva(&voo, pont_vet_passageiros, cont_passageiros);
        }
    } while((strcmp(comando, "FD") != 0) && (strcmp(comando, "FV") != 0));

    /*FIM DO DIA - FD*/
    if (strcmp(comando, "FD") == 0){
        /*Vamos gravar as informações no arquivo e sair do programa*/
        Fim_Dia(pont_arq, voo);
    }

    /*TEMOS QUE DAR FREE NOS PONTEIROS DPS*/
    return 0;
}
