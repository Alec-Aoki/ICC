#include <stdio.h>

/* MATRIZES: arrays com mais de uma dimensão
obs: guardado na memória de forma contígua, que nem um array normal
-> pode ser interessante pensar em matrizes como uma TABELA ou então como um PLANO CARTESIANO
    -> no caso de caracteres, podemos pensar em um vetor que armazena mais de um caractere por linha

*Storage Mapping Function -> eq. para achar o elemento na memória contígua
-> M[3][4] = 0 1 2 3 | 4 5 6 7 | 8 9 10 11 | ...
                0         1           2
M[i][j] = [0][0] + ((quant. colun. * i) + j)
[0][0] é pra onde aponta o ponteiro estático da matriz

!!!!!!!*Como achar os índices a partir do endereço? -> Tenta fazer aí!!!!!!!

    Matrizes Bidimensionais
    int matriz[3][4]; //3 linhas, 4 colunas:
      0  1  2  3
    0
    1
    2
    //para percorrer a matriz, podemos fazer um for dentro de outro

    Some todos os elementos da matriz:
    int soma=0, matriz[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        }; // == {1,2,3,4,5,6,7,8,9,10,11,12}

    for (int linha=0; linha<3; linha++){
        for (int coluna=0; coluna<4; coluna++){
            soma = soma + matriz[linha][coluna];
        }
    }
    printf("%d\n", soma);

OBS: inicialização de string
    char str[4] = "USP"; // == {'U','S','P', '/0'};
*/

int main(void){
    int soma=0, matriz[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        }; // == {1,2,3,4,5,6,7,8,9,10,11,12}

    for (int linha=0; linha<3; linha++){
        for (int coluna=0; coluna<4; coluna++){
            soma = soma + matriz[linha][coluna];
        }
    }
    printf("%d\n", soma);

    return 0;
}