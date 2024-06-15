#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
ALEC CAMPOS AOKI - 15436800
NEWTON EDUARDO PENA VILLEGAS - 15481732
JUAN HENRIQUES PASSOS - 15464826
*/

/*HEADER ARQUIVO
01 %d %d %f %f | quant. de assentos totais, quant. de assentos disponíveis e preço das passagens, respect.
02 %c[4] %c[4] %c[11] %c[5] | origem, destino, data e número do voo, respect.
03 %d | quantidade de passageiros
04 %d %d | tamanho da string nome e sobrenome (de cada passageiro)
05 %s %s %s %s %s | nome, sobrenome, CPF, assento, classe (de cada passageiro, separados por um quebra de linha)
*/

/*STRUCT PASSAGEIRO*/
typedef struct{
    char *nome; //Ponteiro que apontará para o vetor de chars (string) nome na heap
    char *sobrenome; // ^
    char CPF[15]; //CPF DE 11 dígitos + . . - +/0. Como o tamanho do CPF é sempre o mesmo, não vamos alocá-lo dinamicamente
    char assento[4]; //Ponteiro que apontará para o vetor de chars (string) assento na heap
    char classe[10]; //Classe econômica ou executiva.
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
void Abrir_Voo(aviao *voo);

/*Função de realizar reserva - RR*/
void Realizar_Reserva(aviao *voo, passageiro **pont_vet_passageiros, int cont_passageiros);

/*Função de consultar reserva - CR*/
void Consultar_Reserva(aviao *voo, passageiro *pont_vet_passageiros, int cont_passageiros);

/*Função de cancelar reserva - CA*/
void Cancelar_Reserva(passageiro **pont_vet_passageiros, int *cont_passageiros);

/*Função de modificar a reserva - MR*/
void Modificar_Reserva(aviao *voo, passageiro **pont_vet_passageiros,int cont_passageiros);

/*Função de fechamento do dia - FV*/
void Fim_Dia(FILE *pont_arq, aviao *voo, int cont_passageiros, passageiro *pont_vet_passageiros);

/*Função de fechamento do voo - FV*/
void Fim_Voo(aviao *voo, int cont_passageiros, passageiro *pont_vet_passageiros, FILE *pont_arq);

/*Função para lermos as informações dos arquivos*/
void Abrir_Arquivo(FILE *pont_arq, aviao *voo, passageiro **pont_vet_passageiros, int *cont_passageiros);

/*Função para dar free nos ponteiros usados para alocação dinâmica*/
void Liberar_Ponteiros(passageiro *pont_vet_passageiros, int cont_passageiros);

int main(void){
    FILE *pont_arq = NULL; //pont_arq será o ponteiro que usaremos para manipular o arquivo

    int cont_comandos = 0;

    /*INFORMAÇÕES PASSAGEIROS*/
    int cont_passageiros = 0; //Contador que vai guardar a quant. de passageiros no voo
    passageiro *pont_vet_passageiros = (passageiro *)malloc(sizeof(passageiro));
    // ^: Ponteiro que vai apontar para o início do vetor de passageiros na heap

    aviao voo;

    /*RECEBER O COMANDO*/
    //Criando o vetor de chars (string) do comando na heap:
    char comando[3];

    //Vamos usar a função strcmp() para saber qual comando foi digitado
    //Nota: ela retorna 0 se as string forem iguais
    do {
        scanf( "%s", comando);
        //Verificamos se o arquivo está aberto, se ele aponta para nulo, abrimos o arquivo
        if(cont_comandos == 0){
           Abrir_Arquivo(pont_arq, &voo, &pont_vet_passageiros, &cont_passageiros);
           cont_comandos++;
        }

        /*ABERTURA DO VOO - AV*/
        if(strcmp(comando, "AV") == 0){
            Abrir_Voo(&voo);
            if(voo.assentos_total == 0){
                Fim_Voo(&voo, cont_passageiros, pont_vet_passageiros, pont_arq);
                return 0;
            }
        }

        /*REALIZAR RESERVA - RR*/
        else if(strcmp(comando, "RR") == 0){
            cont_passageiros++;
            Realizar_Reserva(&voo, &pont_vet_passageiros, cont_passageiros);
            if(voo.assentos_disp == 0){
                Fim_Voo(&voo, cont_passageiros, pont_vet_passageiros, pont_arq);
                Liberar_Ponteiros(pont_vet_passageiros, cont_passageiros);
                return 0;
            }
        }

        /*CONSULTAR RESERVA - CR*/
        else if(strcmp(comando, "CR") == 0){
            Consultar_Reserva(&voo, pont_vet_passageiros, cont_passageiros);
        }
          
        /*CANCELAR RESERVA - CA*/
        else if(strcmp(comando, "CA") == 0){
            Cancelar_Reserva(&pont_vet_passageiros, &cont_passageiros);
            //Aumentando em 1 a quantidade disponível de assentos no vôo:
            voo.assentos_disp++;
        }
          
        /*MODIFICAR RESERVA - MR*/
        else if(strcmp(comando, "MR") == 0){
            Modificar_Reserva(&voo, &pont_vet_passageiros, cont_passageiros);
        }

    } while((strcmp(comando, "FD") != 0) && (strcmp(comando, "FV") != 0));

    /*FIM DO DIA - FD*/
    if(strcmp(comando, "FD") == 0){
        /*Vamos gravar as informações no arquivo e sair do programa*/
        Fim_Dia(pont_arq, &voo, cont_passageiros, pont_vet_passageiros);
    }
  
    /*FIM DO VOO - FV*/
    else if(strcmp(comando, "FV") == 0){
        /*Vamos avisar sobre o fechamento do voo e imprimir os cpfs, nomes e assentos dos passageiros, em ordem de reserva*/
        Fim_Voo(&voo, cont_passageiros, pont_vet_passageiros, pont_arq);
    }

    /*Free nos ponteiros*/
    //Ponteiros nome e sobrenome dos passageiros
    Liberar_Ponteiros(pont_vet_passageiros, cont_passageiros);
    return 0;
}

/*Função de abertura do vôo - AV*/
void Abrir_Voo(aviao *voo){
    scanf(" %d %f %f", &(voo->assentos_total), &(voo->preco_economica), &(voo->preco_executiva));
    //quant. assentos, valor economica, valor executiva
    voo->assentos_disp = voo->assentos_total; //Na abertura do voo, a quant. de assentos disp = total
    return;
}

/*Função de realizar reserva - RR*/
void Realizar_Reserva(aviao *voo, passageiro **pont_vet_passageiros, int cont_passageiros){
    //Realocando a memória na heap para criarmos um novo espaço para o passageiro:
    *pont_vet_passageiros = (passageiro *)realloc(*pont_vet_passageiros, (cont_passageiros*(sizeof(passageiro))));
    if(*pont_vet_passageiros == NULL){
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
    (*pont_vet_passageiros)[cont_passageiros-1].nome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if((*pont_vet_passageiros)[cont_passageiros-1].nome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //observe-se que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'.
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        (*pont_vet_passageiros)[cont_passageiros-1].nome[i] = string_temp[i];
    }

    //Sobrenome:
    scanf(" %s", string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    //nota-se que o +1, faz referencia ao '\0'.
    (*pont_vet_passageiros)[cont_passageiros-1].sobrenome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if ((*pont_vet_passageiros)[cont_passageiros-1].sobrenome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //observe-se que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'.
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        (*pont_vet_passageiros)[cont_passageiros-1].sobrenome[i] = string_temp[i];
    }

    //CPF:
    scanf(" %s ", (*pont_vet_passageiros)[cont_passageiros-1].CPF);
    ((*pont_vet_passageiros)[cont_passageiros-1].CPF)[14] = '\0';

    //Data Viagem:
    fgets(voo->data, 11, stdin);
    voo->data[strcspn(voo->data, " ")] = '/';
    voo->data[strcspn(voo->data, " ")] = '/';
    voo->data[10] = '\0';

    //Número do Voo:
    scanf(" %s", voo->numero);
    voo->numero[4] = '\0';

    //Assento:
    scanf(" %s ", (*pont_vet_passageiros)[cont_passageiros-1].assento);
    ((*pont_vet_passageiros)[cont_passageiros-1].assento)[3] = '\0';

    //Classe:
    scanf(" %s", (*pont_vet_passageiros)[cont_passageiros-1].classe);

    //Valor:
    scanf(" %s", string_temp);

    //Origem:
    scanf(" %s", voo->origem);
    voo->origem[3] = '\0';

    //Destino:
    scanf(" %s", voo->destino);
    voo->destino[3] = '\0';

    return;
}

/*Função de consultar reserva - CR*/
void Consultar_Reserva(aviao *voo, passageiro *pont_vet_passageiros, int cont_passageiros){
    char CPF_temp[15]; //Variável para guardar o CPF do passageiro que irá consultar a reserva. tam CPF = 14 + '\0'
  
    //Receber o CPF do passageiro:
    scanf(" %s", CPF_temp);
    CPF_temp[14] = '\0';
  
    //Procurar no vetor de passageiros o cpf dessa pessoa:
    for(int i = 0; i< (cont_passageiros); i++){
        if(strcmp(pont_vet_passageiros[i].CPF, CPF_temp) == 0){
            //Após achar a pessoa, vamos imprimir suas informações de reserva, e encerramos a procura:
            printf("%s\n", pont_vet_passageiros[i].CPF);
            printf("%s ", pont_vet_passageiros[i].nome);
            printf("%s\n", pont_vet_passageiros[i].sobrenome);
            printf("%s\n", voo->data);
            printf("Voo: %s\n", voo->numero);
            printf("Assento: %s\n", pont_vet_passageiros[i].assento);
            printf("Classe: %s\n", pont_vet_passageiros[i].classe);
            printf("Trecho: %s ", voo->origem);
            printf("%s\n", voo->destino);
            if(strcmp(pont_vet_passageiros[i].classe, "economica") == 0){
                printf("Valor: %.2f\n", voo->preco_economica);
            }
            else {
                printf("Valor: %.2f\n", voo->preco_executiva);
            }
            printf("--------------------------------------------------\n");
            break;
        }
    }
    return;
}

/*Função de cancelar reserva - CA*/
void Cancelar_Reserva(passageiro **pont_vet_passageiros, int *cont_passageiros){
    int posicao; //Variável em que será guardada a posição do passageiro no vetor
    char CPF_temp[15]; //Variável para guardar o CPF do passageiro que irá cancelar a reserva. tam CPF = 14 + '\0'.
  
    //Receber o CPF do passageiro;
    scanf(" %s", CPF_temp);
    CPF_temp[14] = '\0';
  
    //Procurar no vetor de passageiros o CPF dessa pessoa:
    for(int i = 0; i< (*cont_passageiros); i++){
        //Comparando os CPFs e guardando a posição dele quando achar:
        if(strcmp((*pont_vet_passageiros)[i].CPF, CPF_temp) == 0){
            posicao = i;
            break;
        }
    }
    //Deslocando o CPF da pessoa que quer cancelar para o final do vetor:
    for(int i = posicao; i < (*cont_passageiros)-1; i++){
        (*pont_vet_passageiros)[i] = (*pont_vet_passageiros)[i+1];
    }
    //Subtraindo ela da contagem de passageiros do voo:
    (*cont_passageiros)--;
    //Ajustando a posição do vetor para a quantidade de passageiros do voo;
    *pont_vet_passageiros = realloc(*pont_vet_passageiros, (sizeof(passageiro)*(*cont_passageiros)));

    return; 
}

/*Função de modificar a reserva - MR*/
void Modificar_Reserva(aviao *voo, passageiro **pont_vet_passageiros,int cont_passageiros){
    int posicao; //Variável em que será guardada a posição do passageiro no vetor
    char CPF_temp[15]; //Variável para guardar o CPF do passageiro que irá consultar a reserva. tam CPF = 14 + '\0'.
    char string_temp[100] = "0"; //Vetor temporário para guardarmos caracteres
  
    //Receber o CPF do passageiro:
    scanf(" %s", CPF_temp);
    CPF_temp[14] = '\0';
  
    //Procurar no vetor de passageiros o cpf dessa pessoa:
    for(int i = 0; i< (cont_passageiros); i++){
        if(strcmp((*pont_vet_passageiros)[i].CPF, CPF_temp) == 0){
            //Guardando a posição do passageiro para atualizar seus dados:
            posicao = i;
        }
    }
  
    //Nome:
    scanf(" %s", string_temp);
    (*pont_vet_passageiros)[posicao].nome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    //O ponteiro nome do passageiro agora aponta para um espaço na heap
    //Nota-se que o +1 faz referência ao '\0'
    if((*pont_vet_passageiros)[posicao].nome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //Observe que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        (*pont_vet_passageiros)[posicao].nome[i] = string_temp[i];
    }
  
    //Sobrenome:
    scanf(" %s", string_temp);
    //O ponteiro sobrenome do passageiro agora aponta para um espaço na heap:
    //Nota-se que o +1, faz referencia ao '\0'.
    (*pont_vet_passageiros)[posicao].sobrenome = (char *)malloc((strlen(string_temp)+1)*sizeof(char));
    if ((*pont_vet_passageiros)[posicao].sobrenome == NULL){
        printf("Erro ao alocar\n");
        exit(1);
    }
    //Atribuindo cada caractere de nome_temp ao vetor apontado pelo nome da struct:
    //Observe que o laço de repetição vai da posição zero até o tamanho do nome, incluindo o '\0'.
    for (long unsigned int i=0; i<=strlen(string_temp); i++){
        (*pont_vet_passageiros)[posicao].sobrenome[i] = string_temp[i];
    }

    //CPF:
    scanf(" %s", (*pont_vet_passageiros)[posicao].CPF);
    ((*pont_vet_passageiros)[posicao].CPF)[14] = '\0';

    //Assento:
    scanf(" %s", (*pont_vet_passageiros)[posicao].assento);
    ((*pont_vet_passageiros)[posicao].assento)[3] = '\0';

    printf("Reserva Modificada:\n");
    printf("%s\n", (*pont_vet_passageiros)[posicao].CPF);
    printf("%s ", (*pont_vet_passageiros)[posicao].nome);
    printf("%s\n", (*pont_vet_passageiros)[posicao].sobrenome);
    printf("%s\n", voo->data);
    printf("Voo: %s\n", voo->numero);
    printf("Assento: %s\n", (*pont_vet_passageiros)[posicao].assento);
    printf("Classe: %s\n", (*pont_vet_passageiros)[posicao].classe);
    printf("Trecho: %s ", voo->origem);
    printf("%s\n", voo->destino);
    if(strcmp((*pont_vet_passageiros)[posicao].classe, "economica") == 0){
        printf("Valor: %.2f\n", voo->preco_economica);
    }
    else {
        printf("Valor: %.2f\n", voo->preco_executiva);
    }
    printf("--------------------------------------------------\n");
    return;

}

/*Função de fechamento do dia - FV*/
void Fim_Dia(FILE *pont_arq, aviao *voo, int cont_passageiros, passageiro *pont_vet_passageiros){
    float valor_venda = 0.00;// Variável para guardar a soma do valor adquirido com as vendas das passagens do voo até aquele dia
  
  //Calculando a soma das passagens economicas e executivas dos passageiros:
    for(int i=0; i<(cont_passageiros); i++){
        if(strcmp(pont_vet_passageiros[i].classe, "economica") == 0){ //Economica
            valor_venda += voo->preco_economica;
        }
        else{ //Executiva
            valor_venda += voo->preco_executiva;
        }
    }
  
    //Exibir o fechamento do dia:
    printf("Fechamento do dia:\n");
    printf("Quantidade de reservas: %d\n", cont_passageiros);
    printf("Posicao: %.2f\n", valor_venda);
    printf("--------------------------------------------------\n");

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
    03 %d | quantidade de passageiros
    04 %d %d | tamanho da string nome e sobrenome (de cada passageiro)
    05 %s %s %s %s %s | nome, sobrenome, CPF, assento, classe (de cada passageiro, separados por um quebra de linha)
    */

    /*Escrevendo as informações do voo no arquivo*/
    fprintf(pont_arq, "%d %d %f %f\n", voo->assentos_total, voo->assentos_disp, voo->preco_economica, voo->preco_executiva);
    fprintf(pont_arq, "%s %s %s %s\n", voo->origem, voo->destino, voo->data, voo->numero);
    fprintf(pont_arq, "%d\n", cont_passageiros);
    for(int i = 0; i < cont_passageiros; i++){
        fprintf(pont_arq, "%ld %ld\n", strlen(pont_vet_passageiros[i].nome), strlen(pont_vet_passageiros[i].sobrenome));
        fprintf(pont_arq, "%s ", pont_vet_passageiros[i].nome);
        fprintf(pont_arq, "%s ", pont_vet_passageiros[i].sobrenome);
        fprintf(pont_arq, "%s ", pont_vet_passageiros[i].CPF);
        fprintf(pont_arq, "%s ", pont_vet_passageiros[i].assento);
        fprintf(pont_arq, "%s\n", pont_vet_passageiros[i].classe);
    }
    fclose(pont_arq);
    pont_arq = NULL;
    return;
}

/*Função de fechamento do voo - FV*/
void Fim_Voo(aviao *voo, int cont_passageiros, passageiro *pont_vet_passageiros, FILE *pont_arq){
    float valor_total = 0.00; //Variável para guardar a soma do valor adquirido com as vendas das passagens do voo
  
    //Calculando a soma das passagens economicas e executivas dos passageiros:
    for(int i = 0; i < (cont_passageiros); i++){
        if(strcmp(pont_vet_passageiros[i].classe, "economica") == 0){
            valor_total += voo->preco_economica;
        }
        else{
            valor_total += voo->preco_executiva;
        }
    }
  
    //Exibir o fechamento do voo:
    printf("Voo Fechado!\n\n");

    for(int i = 0; i < cont_passageiros; i++){
        printf("%s\n", pont_vet_passageiros[i].CPF);
        printf("%s ", pont_vet_passageiros[i].nome);
        printf("%s\n", pont_vet_passageiros[i].sobrenome);
        printf("%s\n\n", pont_vet_passageiros[i].assento);
    }
    printf("Valor Total: %.2f\n", valor_total);
    printf("--------------------------------------------------\n");

    pont_arq = fopen("voo.txt", "w");
    fclose(pont_arq);
    pont_arq = NULL;
    return;
}

/*Função para lermos as informações do arquivo*/
void Abrir_Arquivo(FILE *pont_arq, aviao *voo, passageiro **pont_vet_passageiros, int *cont_passageiros){
    //Lendo as informações do arquivo e jogando elas nos vetores
    pont_arq = fopen("voo.txt", "a+");
    rewind(pont_arq);
    if(pont_arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    /*HEADER ARQUIVO
    01 %d %d %f %f | quant. de assentos totais, quant. de assentos disponíveis e preço das passagens, respect.
    02 %c[4] %c[4] %c[11] %c[5] | origem, destino, data e número do voo, respect.
    03 %d | quantidade de passageiros
    04 %d %d | tamanho da string nome e sobrenome
    05 %s %s %s %s %s | nome, sobrenome, CPF, assento, classe (de cada passageiro, separados por um quebra de linha)
    */
    //Informações do voo:
    fscanf(pont_arq, "%d %d %f %f", &voo->assentos_total, &voo->assentos_disp, &voo->preco_economica, &voo->preco_executiva);
    fscanf(pont_arq, "%s %s %s %s", voo->origem, voo->destino, voo->data, voo->numero);
    fscanf(pont_arq, "%d", cont_passageiros);
    
    if (*cont_passageiros == 0){
        *pont_vet_passageiros = (passageiro *)realloc(*pont_vet_passageiros, ((sizeof(passageiro))));
        if(*pont_vet_passageiros == NULL){
            printf("Erro ao realocar\n");
            exit(1);
        }
    }
    else{
        *pont_vet_passageiros = (passageiro *)realloc(*pont_vet_passageiros, ((*cont_passageiros)*(sizeof(passageiro))));
        if(*pont_vet_passageiros == NULL){
            printf("Erro ao realocar\n");
            exit(1);
        }
    }

    //Informações de cada passageiro:
    long unsigned int tamanho_strings[2]; //Vetor para guardamos o tamanho do nome, sobrenome e assento
    for (int i=0; i<(*cont_passageiros); i++){
        //Lendo o tamanho do nome, sobrenome e assento do passageiro i:
        fscanf(pont_arq, "%ld %ld", &tamanho_strings[0], &tamanho_strings[1]);
        //Note que não precisamos saber o tamanho das string que tem tamanho definido na struct
        //Alocando os vetores de suas struct com os respectivos tamanhos:
        (*pont_vet_passageiros)[i].nome = (char *)malloc(sizeof(char)*((int)tamanho_strings[0]+1));
        (*pont_vet_passageiros)[i].sobrenome = (char *)malloc(sizeof(char)*((int)tamanho_strings[1]+1));
        //Lendo as informações do passageiro:
        fscanf(pont_arq, "%s %s %s %s %s", (*pont_vet_passageiros)[i].nome, (*pont_vet_passageiros)[i].sobrenome, (*pont_vet_passageiros)[i].CPF, (*pont_vet_passageiros)[i].assento, (*pont_vet_passageiros)[i].classe);
    }
    fclose(pont_arq);
    pont_arq = NULL;
    return;
}

/*Função para dar free nos ponteiros usados para alocação dinâmica*/
void Liberar_Ponteiros(passageiro *pont_vet_passageiros, int cont_passageiros){
    for(int i=0; i<cont_passageiros; i++){
        free(pont_vet_passageiros[i].nome);
        free(pont_vet_passageiros[i].sobrenome);
    }
    free(pont_vet_passageiros);
    return;
}