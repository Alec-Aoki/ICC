#include <stdio.h>
#include <stdlib.h>

/*
Entrada
3
1 54 manga
0 3624 t o m e _ c u i d a d o _ c o m _ p a l a v r a s _ g r a n d e s _ h a h a h a h h a h a h a h h a h a h a
2 67 i m p o r t a nt e _ l em b r ar _ d e_ c a so s _ c om _ n um e r os _ p r im o s

CÓDIGO:
54/2 = 27, res 0
27/3 = 9, res 0
9/5 = 1, res 4 -> se res != 0, já temos nossos divisores
2+3 = 5 bytes (5 caracteres)

Saída
i m p o r t a n t e _l e m br a r _ de _ c as o s _c o m _ nu m e ro s _ pr i m o s 67
manga 54
t o m e _ c u i d a d o _ c o m _ p a l a v r a s _ g r a n d e s _ h a h a h a h h a h a h a h h a h a h a 3624

O programa receber´a como entrada um n´umero inteiro (n) correspondente `a quantidade de dados
fornecidos e, nas pr´oximas n linhas, o IP (inteiro que indica a importˆancia do dado para poder
coagir Seu Jair), o c´odigo (inteiro que possibilitar´a saber a quantidade m´axima de bytes referente `a
informa¸c˜ao) e o conte´udo em formato de string sem espa¸cos. A partir de cada c´odigo, obtenha o
tamanho das respectivas strings - somando seus divisores primos - para uma aloca¸c˜ao mais eficiente e
fa¸ca o programa exibir os produtos em ordem decrescente de IP, printando o conte´udo e o c´odigo

-> IP
-> Código (tamanho)
-> String

Programa:
-> criar uma matriz na heap de n linhas e 1 coluna (quant. de dados)
-> receber o IP, que vai ser nosso índice da linha
    -> ou seja, na linha [IP], vamos guardar a string
-> receber o código e decompor
    -> retorna o tamanho em bytes da string
-> realocar o espaço do vetor [IP] para esse tamanho em bytes
-> dar o scanf
-> repetir

Crie_Matriz(n); //retornar o ponteiro que aponta para o vetor de ponteiros
Calcule_Tamanho(codigo); //retorna o tamanho da string em bytes
Leia_String(tamanho_string, IP); // guarda a string no vetor
Imprima_Resultado;
*/

char **Crie_Matriz(int linhas){
    //ponteiro para o vetor de ponteiros:
    char **pont_vet_pont;
    pont_vet_pont = (char **)malloc(linhas*sizeof(char *));

    //vetor de char para cada ponteiro do vetor de ponteiros:
    for (int i=0; i<linhas; i++){
        pont_vet_pont[i] = (char *)malloc(1*sizeof(char));
    }
    return pont_vet_pont;
}

int *Crie_Vet_Tamanho(int quant_de_dados){
    /* GUARDANDO O TAMANHO DAS STRINGS
    Para imprimir os valores, vamos ter que guardar os tamanhos das string em algum lugar
    Para tanto, iremos criar um vetor na heap que guarda esses tamanhos na mesma ordem que o vetor de ponteiros
    Esse vetor só será usado mais adiante, mas já criaremos ele aqui
    */
    int *pont_vet_tamanho;
    pont_vet_tamanho = (int *)malloc(quant_de_dados*sizeof(int));
    return pont_vet_tamanho;
}

int *Crie_Vet_Codigo(int quant_de_dados){
    //para Imprima_Resultado
    int *pont_vet_codigo;
    pont_vet_codigo = (int *)malloc(quant_de_dados*sizeof(int));
    
    return pont_vet_codigo;
}

int Calcule_Tamanho(int *pont_vet_codigo, int IP){
    int codigo, tamanho_string=0;
    scanf(" %d", &codigo);

    //guardado o codigo no vetor apropriado para usarmos depois:
    pont_vet_codigo[IP] = codigo;

    //primeiro, vamos conferir se o código em si não é primo
    int flag_cod=0;
    for (int i=1; i<=codigo; i++){
        flag_cod = 0;
        if ((codigo%i == 0) && (i!=1) && (i!=codigo)){
            //codigo nao é primo, podemos prosseguir
            flag_cod = 1;
            break;
        }
    }
    if (flag_cod == 0){
        //código é primo, já sabemos o tamanho da string (é o próprio código)
        tamanho_string = codigo;
        return tamanho_string;
    }

    /*DIVISORES PRIMOS
    Como garantir que o divisor é primo?
    Vamos começar com o divisor = 2, pois 2 é o primeiro número primo
    Vamos então dividir o divisor por cada número entre 1 e ele mesmo
    Se ele for divisível por qualquer número que não seja 1 ou ele mesmo, então ele NÃO é primo
        Neste caso, incrementamos 1 ao divisor e checamos de novo
    Se não acharmos nenhum número que divide o divisor, sendo esse número != de 1 e ele mesmo, então ele é primo
    */

    int flag = 0;
    //vamos usar essa flag para ter certeza que o divisor é primo ou não

    for (int divisor=2; divisor<=codigo; divisor++){
        //teste para ver se o divisor é primo ou não
        for (int i=1; i<=divisor; i++){
            flag = 0;
            if ((divisor%i == 0) && (i!=1) && (i!=divisor)){
                //divisor não é primo, precisamos ir para o proximo divisor
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            //nosso divisor atual é primo
            if ((codigo%divisor) == 0){
                tamanho_string += divisor;
                codigo = codigo/divisor;
            }
        }
    }
    return tamanho_string;
}

void Leia_String(int IP, char **pont_vet_pont, int tamanho_string, int *pont_vet_tamanho){
    //realocando o espaço anteriormente reservado para um novo com o tamanho da string:
    pont_vet_pont[IP] = (char *)realloc(pont_vet_pont[IP], tamanho_string*sizeof(char));

    scanf(" %s", pont_vet_pont[IP]);

    int i=0;
    while(pont_vet_pont[IP][i] != '\0'){
        i++;
    }
    tamanho_string = i;
    pont_vet_tamanho[IP] = tamanho_string;
}

void Imprima_Resultado(char **pont_vet_pont, int *pont_vet_tamanho, int *pont_vet_codigo, int quant_de_dados){
    //printando as palavras:
    for (int i=(quant_de_dados-1); i>=0; i--){
        for (int j=0; j<pont_vet_tamanho[i]; j++){
            printf("%c", pont_vet_pont[i][j]);
        }
        printf(" %d\n", pont_vet_codigo[i]);
    }
}

int main(void){
    int quant_de_dados;
    scanf(" %d", &quant_de_dados);

    char **pont_vet_pont;
    int tamanho_string, *pont_vet_tamanho, *pont_vet_codigo;

    if (quant_de_dados == 0){
        printf("Sem produtos a serem cadastrados\n");
        return 0;
    }
    else {
        //pont_vet_pont aponta para o começo do vetor de ponteiros na heap
        pont_vet_pont = Crie_Matriz(quant_de_dados);

        //pont_vet_tamanho aponta para o começo do vetor que guarda tamanho das strings
        pont_vet_tamanho = Crie_Vet_Tamanho(quant_de_dados);

        //pont_vet_codigo aponta para o começo do vetor que guarda os codigos dos produtos
        pont_vet_codigo = Crie_Vet_Codigo(quant_de_dados);

        for (int i=0; i<quant_de_dados; i++){
            // o IP está fora de uma função porque senão a ordem de entrada dos dados estaria zoada
            int IP;
            scanf(" %d", &IP);

            tamanho_string = Calcule_Tamanho(pont_vet_codigo, IP);

            Leia_String(IP, pont_vet_pont, tamanho_string, pont_vet_tamanho);
        }
    }

    Imprima_Resultado(pont_vet_pont, pont_vet_tamanho, pont_vet_codigo, quant_de_dados);

    return 0;
}