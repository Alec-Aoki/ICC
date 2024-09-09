# MERGE SORT
-> ordenação por intercalação <br />
-> O(nlog(n)) <br />
-> T(n) = O(1), n = 1 <br />
-> T(n) = 2*T(n/2) + O(n), n>1 <br />
1. quebrar o array na metade até que se obtenha arrays unitários
2. ordernar os dois arrays e uní-los
3. repetir

```
{} indica o meio
                9 3 {1} 4 2 5
    9 {3} 1                     4 {2} 5
    {9} 3       {1}          4 {2}      {5}
 {9}     {3}    {1}       {4}    {2}    {5}
     3 9         1           2 4         5
          1 3 9                   2 4 5
                  1 2 3 4 5 9
```

## Implementação
```c
void intercala(int v[], int inicio, int meio, int fim){
    int n1, n2;
    n1 = meio-inicio+1;
    n2 = fim-meio;

    int L[n1+1], R[n2+1];

    for(int i=0; i<n1; i++){
        L[i] = v[inicio+i];
    }
    L[n1] = sizeof(int); //para i não estourar no loop lá debaixo

    for(int i=0; i<n2; i++){
        R[i] = v[meio+i];
    }
    L[n1] = sizeof(int); //para j não estourar no loop lá debaixo

    int i=0, j=0;
    for(int k=inicio; k<=fim; k++){
        if(L[i] < L[j]>){
            v[k] = L[i];
            i++;
        }
        else{
            v[l] = R[j];
            j++;
        }
    }

    return;
}

void mergesort(int v[], int inicio, int fim){
   if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio+1, fim);
        intercala(v, inicio, meio, fim);
    }

    return;
}
```
