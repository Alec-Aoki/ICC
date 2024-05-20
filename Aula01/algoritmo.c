#include <stdio.h>

/*O algoritmo apresentado no exercício possue os seguintes erros:
1) falta de ponto e vírgula no final dos comandos
2) nomes de variáveis começando com números (1nome e 2nome)
3) falta de ponto final em FIM

Observação: o nome de algumas variáveis (case e char) dariam erro se usadas em C pois estes são comandos da linguagem, não podendo
serem usados como nomes de variáveis. No "portugol", no entanto, esses erros não ocorrem (eu acho). Devido a estes e os erros 
mencionados acima sobre os nomes das variáveis, alterarei elas no código em C, adicionando "var_" antes delas
*/

int main(void){

    int var_case;
    char var_1nome, var_2nome, var_char;

    scanf("%d\n%c\n%c\n%c\n", &var_case, &var_1nome, &var_2nome, &var_char);

    int resposta;

    resposta = var_case;

    printf("a resposta eh ");
    printf("%d", resposta);

    return (0);
}