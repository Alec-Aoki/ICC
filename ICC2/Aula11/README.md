# Busca Binária
1. Ordernar o vetor;
2. Dividir o vetor no meio;
3. Comparar a chave com o elemento no meio do vetor;
4. Se não for igual, verificar em qual metade do vetor a chave está;
5. Chamar recursivamente com o lado escolhido.
```
chave = 11
1 2 3 4 5 [6] 7 8 9 10 11 12
6 7 8 [9] 10 11 12
9 [10] 11 12
10 [11] 12
```
```c
int buscaBinariaRecursiva(int v[], int inicio, int fim, int chave){
  if(inicio > fim) return ERRO; //chave não encontrada

  int meio = (inicio + fim)/2;
  if(v[meio] == chave){
    return meio;
  }
  else if(chave < v[meio]){
    return buscaBinariaRecursiva(v, inicio, meio-1, chave);
  }
  else{
    return buscaBinariaRecursiva(v, meio+1, fim, chave);
  }
}

int buscaBinariaIterativa(int v[], int tam, int chave){
  int inicio = 0;
  int fim = tam-1;

  while(inicio <= fim){
    int meio = (inicio + fim)/2;
    if(v[meio] == chave) return meio;
    if(chave < v[meio]) fim = meio - 1;
    if(chave > v[meio]) inicio = meio + 1;
  }

  return ERRO;
}
```

# Busca por Interpolação
- Chaves uniformemente distribuídas (são separadas por um intervalo (quase) constante);
  - Exemplo: ```2 5 8```, intervalo de 3;
- Similar à busca binária, mas ```meio = inicio + (fim - inicio) * ((chave - v[inicio]) / (v[fim] - v[inicio]))```;
- Complexidade média: $O(\log(\log(n)))$ (chave ordenenadas e uniformemente distribuídas);
- Pior complexidade: $O(n)$.
```c
int buscaInterpolacao(int v[], int tam, int chave){
  int inicio = 0;
  int fim = tam-1;

  while(inicio <= fim){
    int meio = inicio + (fim - inicio) * ((chave - v[inicio]) / (v[fim] - v[inicio]));
    if(v[meio] == chave) return meio;
    if(chave < v[meio]) fim = meio - 1;
    if(chave > v[meio]) inicio = meio + 1;
  }

  return ERRO;
}
```

# Busca em Tabela Hash
- **Endereçamento Direto**: os elementos da tabela são os próprios índice;
  - ```v[chave] = chave```;
  - Função de mapeamento: $f(x) = x$;
  - Vantagem: busca em $O(1)$;
  - Desvantagem: desperdício de memória;
- **Endereçamento Indireto** (Hashing);
  - Função que dado uma chave, retorna o índice;
  - $f(x) \neq x$;
  -  A busca continua $O(1)$;

## Hashing
- Dividir um conjunto de elementos em um conjunto finito de $B$ classes (chamadas *buckets*), de $0$ a $B-1$;
- Função hash: $h(k)$, $k$ a chave, que pertence ao bucket $h(k)$;
  - Pode ser utilizada para inserir, remover e buscar;
  - Determinística: a função sempre fornece o mesmo resultado para a mesma entrada;
    - Colisão: quando a função hash produz o mesmo endereço para duas chaves diferentes;
      - Chaves com endereços iguais são chamadas sinônimos;
  - Desvantagem: os elementos não estão armazenados sequencialmente;
- Uma boa função hash distribui uniformemente os dados, evita colisões e é fácil de computar;
  - Exemplo:
    - **Chaves inteiras**: dado ```k``` o valor da chave e ```B``` o tamanho do espaço de endereçamento, temos ```posChave = k%B```;
    - **Chaves tipo string**: tratar cada caractere como seu valor em ASCII e a soma desses valores como ```k```;
    - ```B``` ser primo ajuda;
- Se desejamos armazenar $n$ elementos em uma tabela de $m$ espaços, $n \gt m$, chamamos de $\alpha$ a quantidade ideal de elemento em cada posição, $\alpha = \frac{n}{m}$.
- **Tipos de Hashing**;
  - Estático;
    - Espaço de endereçamento não muda;
    - Fechado;
      - Conjunto de chaves de tamanho limitado;
      - Quantidade de chaves $=  B$;
      - Usa técnicas de rehash para tratar colisões;
        - Função de hash secundária;
        - Overflow progressivo;
    - Aberto;
      - Cojunto de chaves de tamanho ilimitado;
        - A lista pode ser de ponteiros para outra estrutura;
      - Encadeamento de elementos para tratar colisões;
  - Dinâmico;
    - Espaço de endereçamento muda.

### Hashing Fechado
- Técnicas de rehashing;
  - Retorna o próximo bucket livre;
    - Idealmente, evita o agrupamento de dados (melhor espalhamento na tabela);
#### Overflow Progressivo
- Sondagem linear: $h(k) = (h(k) + i) \text{mod} B$, $i \in [1, B-1]$;
  - Incrementamos $i$ de um em um;
- Sondagem quadrádica: $h(k) = (h(k) + c_1 \times i + c_2 \times i^2) \text{mod} B$, $i \in [1, B-1]$.
#### Hashing Secundário
- $ h(k) = (h(k) + i \times haux(k)) \text{mod} B $;
  - $ h(k) = k \text{mod} B $;
  - $ haux(k) = 1 + (k \text{mod} (B - 1)) $.
#### Generalizando
- $ h(k, i) = (k + 1) \text{mod} B $, $ i \in [0, B - 1] $.

### Hashing Aberto
- Cada bucket aponta para uma estrutura de dados (acesso à estrutura em $O(1)$) ;
- Vantagens:
  - A tabela pode armazenar mais itens que o tamanho da tabela (mais itens que a quantidade de buckets);
- Desvantagens:
  - A complexidade de tempo irá depender da estrutura apontada pelo bucket.

## Boas Funções de Hash
- Resto da divisão por primo: $h(k) = k \text{mod} B$, $B$ primo maior ou igual ao tamanho da tabela;
- Multiplicação por primo: $h(k) = ((k \times c_1) \text{mod} 1) \times T$, $T$, $T$ o tamanho da tabela;
- Universal:
  - Escolhe dois valores aleatórios, $A$ e $B$ de um conjunto de constantes menores que $P$ primo, que deve ser maior que a maior chave;
  - $h(k) = ((A \times k + B) \text{mod} P) \text{mod} T$.