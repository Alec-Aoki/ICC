# Métodos de Ordenação II
## Quicksort
-> selecionar um pivot $p$ (meio do vetor) <br>
-> com dois índices ($i$ e $j$), cada um começando em um extremo, procura-se $\left[i\right] \geq p$ e $\left[j\right] \leq p$ <br>
-> trocar $\left[i\right]$ e $\left[j\right]$ de lugar <br>
-> avançar $i$ e $j$ e repetir até $j$ e $i$ passarem um ao outro <br>
-> chamar o processo recursivamente para cada metade (início até $j$, $i$ até fim) <br>
-> $O(n^2)$, pior caso = o pivot escolhido é uma das extremidades de um vetor já ordenado, ou quando todos os elementos do vetor são iguais entre si <br>
-> o pior caso pode ser evitando pegando três elementos do vetor e selecionando o pivot como a mediana entre eles <br>
-> caso médio: $O(n log(n))$, mas mais rápido que o mergesort devido à alta taxa de crescimento da memória ocupada no mergesort <br>
-> **NÃO** é estável! <br>

```c
void quicksort(int v[], int inicio, int fim){

}
```