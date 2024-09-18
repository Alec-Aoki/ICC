#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4 FUNCIONALIDADES:
    "R":
    -> registrar nova receita (DINAMICAMENTE)
    -> 6 entradas:
        1. string de no máx. 20 chars
        2. farinha
        3. ovos
        4. oleo
        5. acucar
        6. chocolate
    "C":
    -> quant. de cada ingrediente comprado
    -> 5 inteiros, na mesma ordem que R
    "F":
    -> qual receita será feita
    -> 1 entrada: número da receita que será feita
    -> é preciso checar se há ingredientes suficientes
    -> é preciso checar se a receita existe
    "S":
    -> imprime quant. remanescente de ingredientes
    -> imprimte quant. de receitas cadastradas
    -> sai do programa
OBS:
• Utilize structs para cadastrar as receitas
*/

typedef struct{
    char nome[21];
    int farinha;
    int ovos;
    int oleo;
    int acucar;
    int chocolate;
}receita;

int main(void){
    int compras_realizadas = 0, aux_compra = 0;

    int ingredientes_atuais[5];
    /*
    [0] = farinha
    [1] = ovos
    [2] = oleo
    [3] = acucar
    [4] = chocolate
    */
   int receitas_cadastradas = 0; //contador de receitas cadastradasa
   receita *pont_receitas=NULL;
   
   char comando = '0';
   int terminar = 0;

    while(!terminar){
        scanf(" %c", &comando);
        if(comando == 'R'){
            /*Registrar nova receita*/
            if (receitas_cadastradas == 0){
                //criando o vetor na heap pela primeira vez
                pont_receitas = (receita *)malloc(sizeof(receita));
                if (pont_receitas == NULL){
                    printf("Deu ruim no primeiro malloc\n");
                    return 1;
                }
            }
            else {
                //realocando esse vetor
                pont_receitas = (receita *)realloc(pont_receitas, sizeof(receita)*(receitas_cadastradas+1));
                if (pont_receitas == NULL){
                    printf("Deu ruim no realloc\n");
                }
            }
            //Leitura das informações da receita
            scanf(" %[^ ]", &pont_receitas[receitas_cadastradas].nome);
            scanf("%d", &pont_receitas[receitas_cadastradas].farinha);
            scanf("%d", &pont_receitas[receitas_cadastradas].ovos);
            scanf("%d", &pont_receitas[receitas_cadastradas].oleo);
            scanf("%d", &pont_receitas[receitas_cadastradas].acucar);
            scanf("%d", &pont_receitas[receitas_cadastradas].chocolate);
            receitas_cadastradas++;
        }
        else if (comando == 'C'){
            /*Compra dos ingredientes*/
            if (compras_realizadas == 0){
                for (int i=0; i<5; i++){
                    scanf(" %d", &ingredientes_atuais[i]);
                }
            }
            else {
                //vamos somar o conteúdo comprado ao que já temos
                for (int i=0; i<5; i++){
                    scanf(" %d", &aux_compra);
                    ingredientes_atuais[i] += aux_compra;
                    aux_compra = 0;
                }
            }
            compras_realizadas++;
        }
        else if (comando == 'F'){
            /*Feitura da receita selecionada*/
            //Leitura de qual receita será feita:
            int num_receita;
            scanf(" %d", &num_receita);
            //Checagem se a receita existe:
            if (num_receita > (receitas_cadastradas-1)){
                printf("Receita nao encontrada!\n");
            }
            //Checagem se os ingredientes são suficientes:
            else {
                if (pont_receitas[num_receita].farinha > ingredientes_atuais[0]){
                    printf("Farinha insuficiente\n");
                }
                else if (pont_receitas[num_receita].ovos > ingredientes_atuais[1]){
                    printf("Ovos insuficientes\n");
                }
                else if (pont_receitas[num_receita].oleo > ingredientes_atuais[2]){
                    printf("Oleo insuficiente\n");
                }
                else if (pont_receitas[num_receita].acucar > ingredientes_atuais[3]){
                    printf("Acucar insuficiente\n");
                }
                else if (pont_receitas[num_receita].chocolate > ingredientes_atuais[4]){
                    printf("Chocolate insuficiente\n");
                }
                else {
                    printf("%s feita com sucesso!\n", pont_receitas[num_receita].nome);
                    //Removendo a quant. dos ingredientes utilizada dos ingredientes atuais:
                    ingredientes_atuais[0] -= pont_receitas[num_receita].farinha;
                    ingredientes_atuais[1] -= pont_receitas[num_receita].ovos;
                    ingredientes_atuais[2] -= pont_receitas[num_receita].oleo;
                    ingredientes_atuais[3] -= pont_receitas[num_receita].acucar;
                    ingredientes_atuais[4] -= pont_receitas[num_receita].chocolate;
                }
            }
        }
        else if (comando == 'S'){
            /*Sair do programa*/
            //Imprimir quant. de ingredientes restantes:
            printf("Quantidade no estoque:\n");
            printf("Acucar: %d\n", ingredientes_atuais[3]);
            printf("Chocolate: %d\n", ingredientes_atuais[4]);
            printf("Farinha: %d\n", ingredientes_atuais[0]);
            printf("Oleo: %d\n", ingredientes_atuais[2]);
            printf("Ovos: %d\n", ingredientes_atuais[1]);
            //Imprimir quant. de receitas cadastradas:
            printf("Receitas cadastradas: %d\n", receitas_cadastradas);
            //Sair do programa:
            terminar = 1;
        }
        else{
            printf("Codigo invalido\n");
        }
    }

    free(pont_receitas);
    return 0;
}