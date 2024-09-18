#include <stdio.h>

/*
Achar o número faltando na sequência PA
OBS: os números não estarão em ordem

-> guardar números em um vetor
-> ordenar o vetor
-> checar a sequência de números no vetor (X)
    -> o bubble sorte eh mto lento
-> se somarmos todos os numeros que ele digitou e todos os numeros que a sequencia normal tem,
o numero que falta vai ser a diferença entre esses dois valores!
*/

void achar_numero(int n){
    int sequencia[n], soma_ideal=0, soma_real=0;

    //leitura dos numeros
    for (int i=0; i<n; i++){
        scanf(" %d", &sequencia[i]);
    }

    /*//bubblesort p/ ordenar o vetor, deu TLE
    for (int i=0; i<n; i++){
        for (int j=1; j<n; j++){
            if (sequencia[j]<sequencia[j-1]){
                aux = sequencia[j];
                sequencia[j] = sequencia[j-1];
                sequencia[j-1] = aux;
            }
        }
    }*/
    /*//checando o vetor para achar o numero faltando
    for (int i=0; i<n; i++){
        if (sequencia[i]+1 != sequencia[i+1]){
            printf("Numero desaparecido: %d\n", sequencia[i]+1);
            return;
        }
    }*/

    for (int i=1; i<=n; i++){
        soma_ideal = soma_ideal + i;
    }
    for (int i=0; i<n; i++){
        soma_real = soma_real + sequencia[i];
    }
    printf("Numero desaparecido: %d\n", soma_ideal-soma_real);

    return;
}


int main(void){

    int quant; //quant. de num. que serao digitados
    scanf(" %d", &quant);

    achar_numero(quant);

    return 0;
}