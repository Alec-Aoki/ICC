# Métodos de Ordenação IV
## Selection Sort
- encontrar o elemento de menor valor <br>
- jogar ele na primeira posição do vetor <br>
- repetir, mas agorando envolvendo os n-1 últimos elementos, até restar um <br>
- estável <br>
- $O(n^2)$ em todos os casos <br>
- implementação: <br>
```c
void selectionSort(int v[], int tam){
    int posicao_menor = 0, aux;

    for(int i=0; i<tam-1; i++){
        posicao_menor = i;

        for(int j=i+1; j<tam; j++){
            if(v[j] < v[posicao_menor]){
                posicao_menor = j;
            }
        }

        if(posicao_menor != i){
            aux = v[i];
            v[i] = v[posicao_menor];
            v[posicao_menor] = aux;
        }
    }
}
```

## Heap Sort
- não estável
- **estrutura heap**: uma árvore binária (se ramifica em no máximo 2 elementos) com *ordem* e *forma*
    - ordem: o item de qualquer nó deve estar ordenado em relação a seus nós filhos
        - heap máximo/descendente: pai $\geq$ filhos 
        - heap mínimo/ascendente: filhos $\leq$ pai
    - forma: até o penúltimo nível, a árvore tem que ser completa (todos os nós acima do penúltimo nível devem ter 2 filhos); se o último nível não estiver completo, todos seus nós devem estar o máximo possível à esquerda
- podemos representar uma heap como um vetor:
```
            16
      14          10
  8       7     9    3
2   4   1

16  14  10   8   7   9   3   2   4   1
[0] [1] [2] [3] [4] [5] [6] [7] [8] [9]
```
- filhos do nó $k$:
    - filho esquerdo = $[2k+1]$
    - filho direito = $[2k+2]$
- pai do nó $k$ = $\left[ \frac{k-1}{2} \right]$
- folhas: de $\frac{n}{2}$ em diante
- funcionamento:
    - construir uma heap máximo
    - trocar a raíz (primeiro e maior elemento do vetor) pela última posição
    - diminuir o tamanho da heap em 1
    - rearranjar a heap
    - repetir o processo $n-1$ vezes
```
Trocar a raíz
            16
      14          10
  8       7     9    3
2   4   1
16  14  10   8   7   9   3   2   4   1
[0] [1] [2] [3] [4] [5] [6] [7] [8] [9]


            1
      14          10
  8       7     9    3
2   4   16
1  14  10   8   7   9   3   2   4   16
[0] [1] [2] [3] [4] [5] [6] [7] [8] [9]

Rearranjar a heap
            14
      1           10
  8       7     9    3
2   4
14   1  10   8   7   9   3   2   4
[0] [1] [2] [3] [4] [5] [6] [7] [8]

            14
      8           10
  1       7     9    3
2   4
14   8  10   1   7   9   3   2   4
[0] [1] [2] [3] [4] [5] [6] [7] [8]

            14
      8           10
  4       7     9    3
2   1
14   8  10   4   7   9   3   2   1
[0] [1] [2] [3] [4] [5] [6] [7] [8]

Repetir o processo
```
- procedimentos:
    - **construir_heap** ($O(n)$):
    - percorre de forma ascendente os primeiros $\frac{n}{2} - 1$ nós (ou seja, os nós que não são folhas) e executa o *rearranjar_heap*
    - ou seja, começando pelos últimos níveis (que não são folhas) e subindo, vamos tornando as sub-árvores da heap em heap máximas, e quando chegamos na raíz, transformamos a heap toda em máxima
    ```c
    void construir_heap(int v[], int n){
        int i;
        for(i=(n/2)-1; i>=0; i--){
            rearranjar_heap(v, i, n);
        }

        return;
    }
    ```
    - **rearranjar_heap** ($O(\log(n))$):
    ```c
    void rearranjar_heap(int v[], int i, int tam_heap){
        int esq, dir, maior, aux;

        esq = 2*i + 1;
        dir = 2*i + 2;
        maior = i;

        /*Encontrando o maior elemento entre o filho da direita e da esquerda*/
        if((esq < tam_heap) && (v[esq] > v[maior])){
            maior = esq;
        }
        if((dir < tam_heap) && (v[dir] > v[maior])){
            maior = dir;
        }

        /*Fazendo o swap e repetindo para o próximo níel*/
        if(maior != i){
            aux = v[maior];
            v[maior] = v[i];
            v[i] = aux;

            rearranjar_heap(v, maior, tam_heap);
        }

        return;
    }
    ```
    - **heapSort** ($O(n \log(n))$, todos os casos):
    ```c
    void heapSort(int v[], int n){
        int i, aux, tam_heap;
        
        construir_heap(v, n);
        tam_heap = n;

        for(i=n-1; i>0; i--){
            aux = v[0];
            v[0] = v[i];
            v[i] = aux;

            tam_heap--;
            rearranjar_heap(v, 0, tam_heap);
        }

        return;
    }
    ```