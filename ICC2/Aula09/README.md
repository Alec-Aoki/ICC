# Métodos de Ordenação VI
## Radix-Sort
- ordenação pelos dígitos dos valores que queremos ordenar, começando pelo menos significativo
- toma-se $n$ como a quantidade de dígitos do maior número
- usa uma lista de filas
- a cada dígito, percorremos o vetor (tamanho $m$, ou seja, $m números$), então temos $O(n \times m)$
- assumindo $n$ como INT_MAX, temos $O(m)$
- estável

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

## Cota Inferior para Ordenação
