#ifndef ABB_H
  #define ABB_H

  typedef struct abb_ ABB;

  ABB *abb_criar(void);
  bool abb_apagar(ABB **arvore);
  ABB *abb_inserir(ABB *arvore, int elemento);
  int abb_remover(ABB *arvore, int elemento);
  void abb_imprimir(ABB *arvore);
  bool abb_busca(ABB *arvore, int chave);

#endif