# Métodos de Ordenação V
## Ordenação por Contagem de Menores
- Se sabemos a quantidade de valores menores que o elemento, sabemos a posição em que inserí-lo;
    - Se temos 5 valores menores que o elemento que queremos inserir, devemos inserí-lo na posição 6;
- Utiliza um vetor auxiliar, que vai armazenar a *quantidade de valores menor que o elemento na mesma posição no vetor principal*;
    - Supondo um vetor auxiliar X e um principal A, X[i] = número de elementos do vetor A que são menor que A[i];
    - Ou seja, X[i] indica a posição correta de A[i];
- Não estável;
- Complexidade de tempo: $O(n^2)$;
- Complexidade de espaço: $O(3n) = O(n)$;
- Algoritmo:
  1. criar um vetor auxiliar;
  2. preencher vetor auxiliar de acordo;
  3. rearranjar o vetor principal fazendo swaps.

```c
void contagem_menores(int mainVet[], int tam){
    int auxVet_1[tam], auxVet_2[tam];

    /*contando os menores*/
    for(int i=0; i<tam; i++){
        auxVet_2[i] = mainVet[i]; // copiando o vetor principal 
        //no auxVet_2 por tabela, poderia estar
        // em um laço separado

        int quantMenores = 0;
        for(int j=0; j<tam; j++){
            if(mainVet[j] < mainVet[i]) quantMenores++;
        }
        auxVet_1[i] = quantMenores;
    }

    /*rearranjando o vetor principal*/
    for(int i=0; i<tam; i++){
        mainVet[auxVet_1[i]] = auxVet_2[i];
    }
}
```

## Counting Sort/Contagem de Tipos
- https://www.w3schools.com/dsa/dsa_algo_countingsort.php
- Conta-se a quantidade de vezes que cada elemento aparece;
- **Restrição**: números positivos e dentro de um intervalo com valor máximo e mínimo;
- Suponha que há 3 elementos 1 no vetor $\rightarrow$ eles ocuparão as posições 0, 1 e 2 do vetor ordenado;
- **Não realiza comparações!**;
- Complexidade de tempo: $O(n)$ se $valor_{max} \leq tam$;
  - $ O(n+k) $, $n$ a quantidade de elementos no array principal e $k$ a maior quantidade de vezes que um elemento aparece;
- Complexidade de espaço: $O(2n) = O(n)$;
- Estável;
- Algoritmo:
  1. Achar o maior elemento do vetor;
  2. Criar um novo vetor de tamanho $tam_{original} + elemento_{maior}$;
     1. Cada index desse vetor representa um elemento do vetor original, e o valor armazenado no index $i$ se refere à quantidade de vezes que o elemento $i$ aparece no vetor principal;
  3. Somar o valor guardado na posição $i$ com o valor na posição $i-1$, e guardar esse resultado na posição $i$;
  4. Shiftar o vetor obtido para a direita, NÃO-circularmente;
  5. Agora o valor guardado no índice $i$ indica qual o index inicial do elemento $i$ no vetor principal;
     1. Ao inserirmos esse elemento, incrementamos o valor guardado em seu index por um.

```c
void countingSort(int v[], int tam){
    int valorMax = -1;

    //passo 1
    for(int i=0; i<tam; i++){
        if(v[i] > valorMax) valorMax = v[i];
    }

    //passo 2
    int vetFreq[valorMax + 1];
    memset(vetFreq, 0, sizeof(int)*(valorMax + 1)); 
    //inicializando o vetor vetFreq com 0

    for(int i=0; i<tam; i++){
        vetFreq[v[i]]++;
    }

    //passo 3
    for(int i=1; i<valorMax+1; i++){
        vetFreq[i] += vetFreq[i-1];
    }

    //passo 4
    for(int i=valorMax; i>0; i--){
        vetFreq[i] = vetFreq[i-1];
    }
    vetFreq[0] = 0;

    int vAux[tam];
    //passo 5
    for(int i=0; i<tam; i++){
        vAux[vetFreq[v[i]]] = v[i];
        vetFreq[v[i]]++;
    }
    for(int i=0; i<tam; i++){
        v[i] = vAux[i];
    }

}
```