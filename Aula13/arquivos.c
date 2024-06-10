#include <stdio.h>
#include <stdlib.h>

/* ARQUIVOS
-> armazenar quantidades de dados muito grandes
-> armazenar informações de modo permanente

STREAM (ARQUIVO) DE TEXTO -> .txt
-> sequência de caracteres (leitura de byte a byte, ou seja, caractere a caractere)
-> onde a informação começa e termina já é sabido pelo OS

STREAM (ARQUIVO) BINÁRIA -> .exe, .mp3., .png etc
-> sequência de bytes
-> onde a informação começa e termina tem que ser determinados
    -> essa determinação geralmente está no HEADER, que é começo da stream

ARQUIVOS EM C
-> a associação stream-arquivo é iniciada com a operação de abertura fopen()
    -> permite que operações sejam realizadas no arquivo a partir do programa
-> as informações são gravas no arquivo quando:
    - ele é fechado fclose()
    - a main() acaba
    - a exit() é executada
    - a fflush() é executada (evitar)
    - ocorre crash
    - ocorre abort
-> em C, a stream é a estrutura FILE (biblioteca stdio.h)
    -> usado via ponteiro (geralmente chamado de fp)
    -> exemplo:
        FILE *fp; //esse ponteiro aponta para o arquivo (na verdade é a stream)
    MODOS DE ABERTURA DE ARQUIVO:
        - r: só leitura
        - w: só escrita
            obs: se não existe, cria; se existe, apaga e cria um novo
        - a: escreve no final do arquivo
        - rb: abre em modo binário, só leitura
        - wb: abre em modo binário, só escrita
        - ab: abre em modo binário, escreve no final
        - r+: leitura e escrita
            obs: não começa do final, mas sim no começo
            obs: se o arquivo já existir, não apaga
            obs: não cria arquivo se ele não existe !!!!!!!
        - w+: leitura e escrita
            obs: não começa do final, mas sim no começo
            obs: se o arquivo já existir, não apaga
            obs: cria arquivo se ele não existe !!!!!!!
        - r+b: leitura e escrita em binário
    SINTAXE:
        FILE *fopen("NOME_DO_ARQUIVO", "MODO_DE_ABERTURA");
        fclose (NOME_DO_PONTEIRO);
    exemplo:
        FILE *fp; //cria ponteiro que vai apontar para o começo do arquivo
        fp = fopen("arquivodaora.txt", "r+"); //cria o arquivo "arquivodaora.txt" no modo de ler e escrever
        //fp aponta para o início do arquivo arquivodaora
        if (*fp == NULL){ //erro na abertura do arquivo
            exit(1);
        }
        fclose (fp); //fecha o arquivo apontado por fp, salvando as alterações nele
    obs: aconselhável fechar um arquivo antes de abrir outro

    FUNÇÕES DE LEITURA E ESCRITA, E OUTRAS
    - putc();
        -> escreve um caractere no arquivo
        -> sucesso: retorna o caractere escrito
        -> falha: retorna EOF
    - fputc();
        -> igual ao putc
        -. OBS: stdout é o arquivo do monitor
            -> fput(c, stoud); //printa o conteúdo de c direto na tela
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    - fprintf(NOME_DO_PONTEIRO, "MÁSCARAS E/OU TEXTO", NOME_DA_VARIÁVEL);
        -> igual ao printf, mas tem que colocar o nome do ponteiro antes
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    - fscanf();
        -> igual ao scanf, mas tem que colcoar o nome do ponteiro antes
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    - feof(NOME_DO_PONTEIRO);
        -> detecta o fim do arquivo;
    - fgetc(NOME_DO_PONTEIRO);
        -> pega o caractere apontado pelo ponteiro no arquivo;
        -> obs: o fim de um arquivo .txt é denotado pelo caractere 'EOF'
    - fseek();

*/

int main (void){
    FILE *fp;
    fp = fopen("arquivo_daora.txt", "w+");
    if (fp == NULL){
        printf("Deu ruim no fopen\n");
        exit(1);
    }

    //Ler caracteres do teclado e jogar eles no arquivo:
    char caractere='0';
    while (caractere!='$'){
        scanf("%c", &caractere);
        //if (caractere!='$'){ //não vai printar o $
            fprintf(fp, "%c", caractere);
        //}
    }

    rewind(fp); //faz o ponteiro voltar para o início do arquivo
    caractere = '0';
    
    //Ler caracteres do arquivo e jogar eles na tela:
    while(caractere!='$'){ //enquanto não tiver chegado no fim do arquivo
    //note que feof retorna 1 se for o fim do arquivo, por isso a negação (!)
        fscanf(fp, "%c", &caractere); //lê um caractere do arquivo e guarda na variável caractere
        printf("%c", caractere);
    }
    printf("\n");
    fclose(fp);

    return 0;
}