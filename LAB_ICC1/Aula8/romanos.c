#include <stdio.h>

/*Transformar numero em decimal para romano (Obs: o maior n possivel eh 3999)
Romanos definidos:
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Subtracoes sucessivas pelo maior romano definido possivel
*/


void inteiroParaRomano(int numero){
    int RomanosDefinidos[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    char RomanosChar[13][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    //note que tivemos que adicionar os casos especiais IV, IX, XL, XC, CD, CM
    int cont=12;

    while (cont>=0){
        //teste dos valores, percorrendo de trás pra frente
        if (numero-RomanosDefinidos[cont]>=0){
            printf("%s", RomanosChar[cont]);
            numero = numero - RomanosDefinidos[cont];
        }
        else {
            cont--;
        }
    }
    printf("\n");
    return;
}

int main(void){
    int tamanho_vetor;
    scanf("%d", &tamanho_vetor);
    int numeros[tamanho_vetor];

    for (int i=0; i<tamanho_vetor; i++){
        // lemos cada numero e jogamos ele pra funcao
        scanf(" %d", &numeros[i]);
        inteiroParaRomano(numeros[i]);
    }
    return 0;
}