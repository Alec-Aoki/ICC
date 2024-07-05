#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ARQUIVOS BINÁRIOS
    HEADER
    -> quant. DEFINIDA de dados no início do arquivo com informações sobre o resto dele

    Lógica para copiar um arq. bin.
    -> criar 2 ponteiros para arq.
    -> p1 no modo rb, p2 no modo wb
    -> ler CARACTERE A CARACTERE do p1 e escrever no p2 (fgetc e fputc, ou fscanf e fprintf)
        -> caractere mesmo (char) pq tem 1 byte, e queremos copiar de byte a byte
    
    OPERAÇÃO COM MAIS DE 1 BYTE
    -> se quisermos operar com ints, não poderíamos fazer o mesmo q acima
        -> temos q usar fwrite() e fread() para ler ou escrever mais que 1 byte
        -> fwrite(&nome_variável, sizeof(tipo_da_variável), quant_de_vezes, nome_ponteiro);
        -> fread(&nome_variável, sizeof(tipo_da_variável), quant_de_vezes, nome_ponteiro);
            -> retorna 0 se dá erro
        exemplo:
            scanf("%d", &num); //num um int, pont_arq o ponteiro para o arquivo
            fwrite(&num, sizeof(int), 1, pont_arq); //escreve o conteúdo de num 1 vez no arquivo
            fread(&num, sizeof(int), 1, pont_arq); //lê 1 int do arquivo 1 vez e guarda no num
            printf("%d\n", num);

    STRUCTS EM ARQUIVO BINÁRIO
    -> dá pra printar informação por informação, ou só jogar a struct inteira mesmo
    exemplo:
        struct S{
            int num1;
            float num2;
        }y;
        fwrite(&y, sizeof(S), 1, pont_arq);
        fread(&y, sizeof(S), 1, pont_arq);
        printf(...);
    -> pra vetores de struct é a mesma coisa, só muda o quant_de_vezes
    exemplo:
        fwrite(vet, sizeof(S), 3, pont_arq); //coloca as 3 primeiras posição do vetor apontado por vet no arquivo
        fwrite(&vet[0], sizeof(S), 1, pont_arq); //escreve só a primeira posição do vetor ap. por vet no arquivo
        //OBS: escreve depois das outras posições (anteriormente escrita)
        fread(vet2, sizeof(S), 4, pont_arq); //colocar os conteudos do arquivo no vetor vet2
        printf(...);
*/

int main (void){


    return 0;
}