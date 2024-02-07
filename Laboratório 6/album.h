/* Bibliotecas disponíveis*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
  Nó usado na árvore binária de busca
*/
typedef struct No{
  int figura; 
  int qtd; 
  struct No *esq, *dir;
  /* struct No *pai; */   /*Nó pai, opcional*/
} No;


/*
  Ponteiro para nó 
*/
typedef No * p_no;

int tamanho(int x); /*Função que mostra o tamanho (casa decimal) de um número*/
/* 
  Função que cria uma árvore vazia 
  retorna ponteiro para árvore.
*/
p_no cria_arvore();

/* 
  Função que destroi árvore
*/
void destroi_arvore(p_no raiz);


/*
  Função que insere uma figura na arvore
*/
p_no insere_figura(p_no raiz, int figura);


/*
  Função que remove uma figura da árvore de album.
  Verifique os requisitos do laboratório, que podem ou não
  estar dentro da função
*/
p_no remove_figura(p_no raiz, int figura);

/*
  Função que busca nó da árvore com número da figura
*/
p_no busca_figura(p_no raiz, int figura);


/*
  Função que troca figurinhas,
  figura_i -> figura de entrada
  figura_o -> figura de saída

  retorna árvore atualizada, ou NULL se não houver figuras 
  a serem trocadas
*/
p_no troca_figura(p_no raiz, int figura_i, int figura_o);