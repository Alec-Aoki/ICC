# Boas Práticas/Convenções/Estilos
-> recomendações gerais <br>
-> podem variar de acordo com o contexo! <br>

## Padrões de Nomenclatura
- usar nomes significativos
    ```c
    int x, y, z; //errado
    int numOfApples, numOfPears, totalFruits; //correto
    ```
- evitar informações enganosas
    ```c
    ALUNOS listaAlunos[]; //não estamos usando uma estrutura de dados lista!
    ALUNOS arrayAlunos[];
    ```
- fazer distinções significativas
    ```c
    int data1, data2;
    void process_data(int data1, int data2);
    
    int ageOfStudent, idOfStudent;
    void register_students(int age, int id);
    ```
- use nomes pronunciáveis
    ```c
    int qtdAlnsCrts; //errado
    int quantidadeAlunosCadastrados; //correto
    ```
- tipos de notação
    - Notação Húngara
    - snake_case
    - PascalCase
    - camelCase
    - kebab-case (URLs)
    - SCREAMING-SNAKE-CASE (constantes)
- comentários
    - explicar **blocos de código complexos** ou o **raciocínio por trás de escolhas específicas**
    - devem ser claros e sucintos
    - **NÃO** devem ser óbvios ou reduntantes
    - **na maioria das vezes, um código bem escrito é autoexplicativo**

## Organização e Estrutura do Código
- indentação e espaçamento
    - utilize um padrão consistente
    - recomendado: 1 tab = 4 espaços por nível de bloco
- modularização
    - separar o código em partes menores e **independentes**
        - facilita reutilização, manutenção e entendimento
- estrutura de arquivos
- escopo e inicialização de variáveis
    - declarar variáveis o mais perto possível de sua utilização
    - inicialize na declaração
    ```c
    int i;
    i = 0; //errado

    int j=0; //correto
    ```
- estruturas de controle
    - manter as variáveis confinadas no escopo da estrutura
- **dicas gerais**
    - consistência > preferência individual (em IDIOMA e BOAS PRÁTICAS)
    - use bibliotecas nativas da linguagem como referência
    - use ferramentas de estilo (C)
        - clang-format
        - cpplint
        - prettier.io
- princípios de design
    - **DRY**: don't repeat yourself
        - modularize
    - **KISS**: keep it simple, stupid
        - evite complicar o código
    - Google Style Guide