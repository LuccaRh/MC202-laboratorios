#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX_NOME 50

/*
  Nó de entrada usado para uma lista ligada
*/
typedef struct NoEntrada{
  char nome[TAM_MAX_NOME];
  int RA, hora, min;
  struct NoEntrada *prox;
} NoEntrada;


/*
  Ponteiro para nó de entrada
*/
typedef struct NoEntrada * p_entrada;


/*
  Função que cria uma lista ligada vazia (NULL)
*/
p_entrada cria_lista();

/*
  Destroi uma lista ligada, destruindo os elementos
  internos também
*/
void destroi_lista(p_entrada lista);


/*
  Lê elementos da entrada padrão, salvando-os em um
  nó de entrada.
  Retorna o ponteiro para o nó preenchido.
*/
p_entrada le_entrada();

/*
  Adiciona um nó à lista ligada.
  Recebe uma lista e um elemento, ambos por meio de ponteiros.
  Retorna a lista atualizada
*/
p_entrada adiciona_entrada(p_entrada lista, p_entrada entrada);

/*
  Imprime uma lista ligada, usando o padrão do roteiro.
*/
void imprime_lista(p_entrada lista);

/*
  Remove elemento de determinado <ra>
*/
p_entrada remove_por_ra(p_entrada lista, int ra);

/*
  Imprime moda de acordo com os padrões do roteiro
*/
void imprime_moda(p_entrada lista);

void moda(int a, int b, int c, int d);