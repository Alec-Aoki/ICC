#include <stdio.h>

/*
Implemente um programa em C que recebe um vetor de inteiros at´e receber o n´umero ”1”(seu
vetor n˜ao deve armazenar o n´umero 1). em seguida, seu programa receber´a um comando a,b ou c.
O comando ’a’deve ordenar seu vetor e imprimi-lo, o comando ’b’ deve imprimir apenas os n´umeros
do vetor que pertencem `a sequˆencia de fibonacci (as entradas n˜ao ser˜ao maiores que 2000), o comando
c dever´a imprimir o equivalente de cara n´umero do vetor como caractere, e depois imprimir o mesmo
caractere como mai´usculo (ToUpper). Caso seu programa receba qualquer outro comando, deve printar
”comando inexistente”. s
*/

int main (void){

    int vetor[100], num=0; //vetor que vai armazenar todos os numeros e os numeros a serem guardados nele

    int cont=0, aux; //variavel contadora (n. de elem. no vetor) e aux. (para a ordenacao)

    char comando;

    vetor[-1] = 0; //inic. para compararmos vetor[i] < vetor[i-1]

    while(num!=1){ // um loop infinito que so vai quebrar quando num==1 (no break dentro do else)
        scanf("%d", &num);
        if (num!=1){
            vetor[cont] = num;
            cont++;
        }

        else { // num == 1, o vetor nao armazena o 1
            break;
        }
    }

    scanf(" %c", &comando);

    if (comando == 'a'){ //ordenar o vetor e imprimi-lo
        // Bubble Sort bem mamaco:
        for (int j=0; j<cont; j++){
            for (int i=0; i<cont; i++){
                if (vetor[i]<vetor[i-1]){
                    aux = vetor[i];
                    vetor[i] = vetor[i-1];
                    vetor[i-1] = aux;
                }
            }
        }
        // Imprimir o vetor:
        printf("vetor ordenado:");
        for (int i=0; i<cont; i++){
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }

    else if (comando == 'b'){ //imprimir só os valores que pertencem à sequencia de fibonnaci
        /*
        1) Calcular 1 termo pra seq. de fib.
        2) Ver se esse termo pertence ao vetor
        3) Calcular o 2 termo pra seq.
        4) ''
        5) Repetir até que o termo da seq de fib seja 1597 (o ultimo termo da seq. < 2000)
        */

        //Sequencia de Fibonacci
        int fibonacci[17]; // o termo 17 eh 1597; o termo 18 eh 2584

        fibonacci[0] = 1;
        fibonacci[1] = 1;

        for (int i=2; i<17; i++){
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //geracao da seq. de fibonacci, guardada no vetor
        }

        printf("Numeros de Fibonacci:");

        for (int j=0; j<cont; j++){
            for (int i=2; i<17; i++){
                    if (vetor[j] == fibonacci[i]){ //verificar se o num no vetor esta na sequencia
                        printf("%d ", vetor[j]);
                        break;
                }
            }
        }
        printf("\n");
    }

    else if (comando == 'c'){ //printar o caractere do numero (tabela ascii), em maiusculo
        // A = 65
        // a = 97
        /*
        Checar se o numero eh < 97 ou > (< = maiusculo, > = minusculo, temos que subtrair 32)
        */
        printf("Vetor maiusculo:");
        for (int i=0; i<cont; i++){
            if (vetor[i]>=97){
                printf("%c ", vetor[i]-32);
            }
            else {
                printf("%c ", vetor[i]);
            }
        }
        printf("\n");
    }

    else {
        printf("Comando inexistente\n");
    }

    return 0;
}