# Métodos de Ordenação III
## Insertion Sort
-> temos os elementos de $[0]$ até $[i-1]$ já estão ordenados <br>
-> inserimos o elemento $[i]$ em sua posição correta dentro desse intervalo <br>
-> estável <br>
-> pior caso: menor número no fim do vetor $O(n^2)$<br>
-> melhor caso: vetor já ordenado $O(n)$ <br>
-> exemplo: <br>
```
10 30 31 15 50 60 5 22

10 30 31 [15] 50 60 5 22
10 [15] 30 31 50 60 5 

10 15 30 31 [50] 60 5 22
10 15 30 31 [50] 60 5 22

10 15 30 31 50 [60] 5 22
10 15 30 31 50 [60] 5 22

10 15 30 31 50 60 [5] 22
[5] 10 15 30 31 50 60 22

5 10 15 30 31 50 60 [22]
5 10 15 [22] 30 31 50 60

5 10 15 22 30 31 50 60
```
-> implementação: <br>
```c
void insertionSort(int v[], int tam){
    int i, j, aux;
    
    for(i=1; i<tam; i++){
        aux = v[i];
        for(j=i-1; j>=0 && v[j]>aux; j--){
            v[j+1] = v[j];
        }
        v[j+1] = aux;
    }
}
```

## Shell Sort
-> divide o vetor em subjconjuntos de elemento de distância $h$ entre si <br>
-> aplica o inserction sort em cada um <br>
-> reduz $h$ <br>
-> o i-ésimo elemento do j-ésimo conjunto é $x[(i-1) \times h + j - 1]$ <br>
-> não estável <br>
-> **complexidade de pior variável**, dependendo do $h$ <br>
-> pior caso: vetor ordenado inversamente? <br>
-> exemplo: <br>
```
10 30 5 50 40 25 15

h = 3
[10] 30 5 [50] 40 25 [15]
[10] 30 5 [15] 40 25 [50]
10 [30] 5 [15] 40 [25] 50
10 [15] 5 [30] 40 [25] 50
10 [15] 5 [25] 40 [30] 50
10 15 [5] 25 [40] 30 [50]
10 15 5 25 40 30 50
Vetor está 3-ordenado

h = 2
[10] 15 [5] 25 [40] 30 [50]
[5] 15 [10] 25 [40] 30 [50]
5 [15] 10 [25] 40 [30] 50
5 15 [10] 25 [40] 30 [50]
5 15 10 25 40 30 50
Vetor está 2-ordenado

h = 1 (Insertion Sort normal)
5 15 [10] 25 40 30 50
5 [10] 15 25 40 30 50
5 10 15 25 40 [30] 50
5 10 15 25 [30] 40 50

5 10 15 25 30 40 50
```
-> implementação: <br>
```c
void shellSort(int v[], int tam, int h[], int quant_incr){ //obs: o último elemento de h tem que ser sempre 1!!!
    int i, j, k, aux, h;
    
    for(k=0; k<quant_incr; k++){
        h = h[k];
        for(i=h; i<tam; i++){
            aux = v[i];
            for(j=i-h; j>=0 && v[j]>aux; j-=h){
                v[j+h] = v[j];
            }
            v[j+h] = aux;
        }
    }
}
```