# Métodos de Ordenação VI
## Radix Sort/Ordenação de Raízes
- Ordenação pelos dígitos dos valores que queremos ordenar, começando pelo menos significativo;
- Toma-se $n$ como a quantidade de dígitos do maior número;
- Usa uma lista de filas;
- A cada dígito, percorremos o vetor (tamanho $m$, ou seja, $m$ números), então temos $O(n \times m)$;
- Assumindo $n$ como INT_MAX, temos $O(m)$;
- Estável.

```
Analisando o primeiro dígito O(n):
12 92 33 25 86 57 37 48

fila[0]
fila[1]
fila[2] 12 92
fila[3] 33
fila[4]
fila[5] 25
fila[6] 86
fila[7] 57 37
fila[8] 48
fila[9]

12 92 33 25 86 57 37 48

Analisando o segundo dígito:
12 92 33 25 86 57 37 48

fila[0]
fila[1] 12
fila[2] 25
fila[3] 33 37
fila[4] 48
fila[5] 57
fila[6]
fila[7]
fila[8] 86
fila[9] 92

12 25 33 37 48 57 86 92
```

## Comparação entre todos os Algoritmos
- Insertion Sort;
  - Arquivos com menos de 20 elementos;
  - Estável;
  - Melhor que o bubblesort;
- Selection Sort;
  - Arquivos com menos que 1000 elementos;
- Shell Sort;
  - Arquivos de tamanho moderado;
  - 2x mais lento que o quicksort;
  - Não possui pior caso;
  - Menos operações em arquivos parcialmente ordenados;
- Heap Sort;
  - 2x mais complexo de o quicksort;
  - Não precisa de memória adicional;
  - Executa sempre em $O(n \log n)$;
  - Útil quando não pode haver variações em tempo de execução;
- Merge Sort;
  - Executa sempre em $O(n \log n)$;
  - Precisa de memória adicional;
  - Útil quando não pode haver variações em tempo de execução;
- Quick Sort;
  - Mais eficiente;
- No geral:
  - Para $n > 25$, quicksort com o pivô sendo a mediana de três elementos;
  - Para $n < 25$, ordenação simples (inserction sort, por exemplo);
- Métodos extras:
  - Shakesort;
  - Treesort;
  - Bucketsort.

## Cota Inferior para Ordenação
- É impossível obter um algoritmo baseado em comparação com complexidade melhor que $O(n \log n)$.