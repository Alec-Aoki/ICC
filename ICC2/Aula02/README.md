# BINARY SEARCH
1. dividir o vetor no meio
2. comparar a chave com o elemento no meio do vetor
3. se não for igual, verificar em qual metade do vetor a chave está
4. chamar recursivamente com o lado escolhido <br />
exemplo:
```
chave = 11
1 2 3 4 5 [6] 7 8 9 10 11 12
6 7 8 [9] 10 11 12
9 [10] 11 12
10 [11] 12
```
-> foram realizadas somente 4 comeprações! <br />
-> pior caso: **O(log(n))**

## Implementação
```c
int busca_binaria(int v[], int inicio, int fim, int chave){
    if(inicio > fim) return -1;
    int meio = (inicio + fim)/2;
    if(v[meio] == chave) return meio;
    if(v[meio] > chave) return busca_binaria(v, inicio, meio-1, chave);
    else{return busca_binaria(v, meio+1, fim, chave);}
}
```
