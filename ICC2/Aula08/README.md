# Métodos de Ordenação V
## Ordenação por Contagem de Menores
- se sabemos a quantidade de valores menores que o elemento, sabemos a posição em que inserí-lo
    - se temos 5 valores menores que o elemento que queremos inserir, devemos inserí-lo na posição 6
- utiliza um vetor auxiliar, que vai armazenar a *quantidade de valores menor que o elemento na mesma posição no vetor principal*
    - supondo um vetor auxiliar X e um principal A, X[i] = número de elementos do vetor A que são menor que A[i]
    - ou seja, X[i] indica a posição correta de A[i]
- não estável se for só $<$, estável se for $leq$
- complexidade de tempo: $O(n^2)$
- complexidade de espaço: $O(3n) = O(n)$

1. criar um vetor auxiliar;
2. preencher vetor auxiliar de acordo;
3. rearranjar o vetor principal fazendo swaps.

```c
void contagem_menores(int mainVet[], int tam){
    int auxVet_1[tam], auxVet_2[tam];

    /*contando os menores*/
    for(int i=0; i<tam; i++){
        auxVet_2[i] = mainVet[i]; // copiando o vetor principal no auxVet_2 por tabela, poderia estar em um laço separado

        int quantMenores = 0;
        for(int j=0; j<tam; j++){
            if(mainVet[j] <= mainVet[i]) quantMenores++;
        }
        auxVet_1[i] = quantMenores;
    }

    /*rearranjando o vetor principal*/
    for(int i=0; i<tam; i++){
        mainVet[auxVet_1[i]] = auxVet_2[i];
    }
}
```

## Counting Sort
- https://www.w3schools.com/dsa/dsa_algo_countingsort.php
- conta-se a quantidade de vezes que cada elemento aparece
    - se há $k$ elementos antes dele, ele deve ser inserido na posição $k+1$
    - **restrição**: números positivos e dentro de um intervalo com valor máximo e mínimo
- suponha que há 3 elementos 1 no vetor -> eles ocuparão as posições 0, 1 e 2 do vetor ordenado
- **não realiza comparações!**
- complexidade de tempo: $O(n)$ se $valorMax \leq tam$
- complexidade de espaço: $O(2n)$

```c
void countingSort(int v[], int tam){
    int valorMax = -1;

    for(int i=0; i<tam; i++){
        if(v[i] > valorMax) valorMax = v[i];
    }

    int vetFreq[valorMax + 1];
    memset(vetFreq, 0, sizeof(int)*(valorMax + 1)); //inicializando o vetor vetFreq com 0

    for(int i=0; i<tam; i++){
        vetFreq[v[i]]++;
    }

    /*TERMINAR*/

    for(int i=0; i<valorMax+1; i++){

    }
}
```