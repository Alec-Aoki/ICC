# Métodos de Busca I

- Tabela: estrutura de dados que armazena os dados;
- Registros: elementos/dados;
- **Chave**: inteiro associado a cada registro, usado para diferenciá-los (identificador);
  - **Interna**: dentro do registro;
  - **Externa**: tabela de chaves com ponteiros que apontam para os registros;
  - **Primária**: cada chave pertence a um único registro (não pode haver chaves repetidas);
  - **Secundária**: chaves não-primárias;
- **Busca**: encontrar o registro com a chave procurada;
  - **Interna**: totalmente na memória;
  - **Externa**:  totalmente na memória auxiliar;
  - **Mista**.

## Tipos de Busca

- Sequencial;
- Binária;
- Interpolação;
- Árvores;
- Hashing.

## Busca Sequencial

- Complexidade: $O(n)$;
- Aplicável em um vetor *sequencial* ou *encadeado*;
- Percorre-se o vetor inteiro comparando cada elemento com a chave buscada;
```c
/*Vetor sequencial*/
int buscaSequencial(int v[], int tamV, int chave){
  for(int i = 0; i < tamV; i++){
    if(v[i] == chave){
      return i;
    }
  }

  return ERRO;
}
```
- Melhorias:
  - **Sentinela**;
  - **Recuperação recorrente de registros**: reordernar a tabela continuamente de forma que os registros mais acessados sejam deslocados para o início do vetor;
    - **Mover-para-frente**: o registro encontrado é movido para o início do vetor;
    - **Transposição**: o registro encontrado é trocado com o anterior;
  - **Tabela de índices**;
    - Forma uma tabela auxiliar com elementos obtidos pulando de $k$ em $k$ na tabela original (**ordenada**);
    - Localizamos em que intervalo dessa tabela auxiliar está a chave procurada;
    - Procuramos sequencialmente nesse intervalo;
  - Observação: todas essas melhorias mantém a complexidade $O(n)$, mas podem reduzir o tempo de busca na prática;
- Observação: o vetor estar ordenado não é, necessariamente, uma melhoria;
  - Vantagem: podemos parar a busca se encontrarmos uma chave maior que a procurada;
  - Desvantagem: temos que inserir ordenadamente ($O(n)$) e ordernar o vetor ($O(n \log(n))$).