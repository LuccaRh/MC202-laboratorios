#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 50

typedef struct {
  char le;
  int num;
}entrada;

/*
  Definindo um tipo, usando struct, para
  armazenar fichas de estudantes.
*/
typedef struct
{
  char  primeiro_nome[TAM_MAX_NOME], ultimo_nome[TAM_MAX_NOME];
  int   RA;
  float CR;
} ficha;


/*
   Função que recebe um ponteiro para um vetor de fichas, um inteiro n que
   diz o tamanho do vetor e um inteiro que representa o RA de um estudante.
   A função devolve o índice do registro do(a) estudante no vetor de fichas
   ou então -1 caso contrário.
*/
int busca_ficha (ficha * ptr_estudante, int n, int RA);

float calcula_media_CR (ficha * ptr_estudante, int n);

ficha * cria_fichario (int n);

void imprime_ficha(ficha * estudante);

int insere_ficha (ficha ** ptr_estudante, int *n, ficha estudante);

ficha le_ficha();

/*
   Função que recebe um ponteiro para um vetor de fichas, um inteiro n que diz
   o tamanho do vetor e um inteiro que representa o RA de um estudante. Se
   existir um registro com o RA então o mesmo é zerado e a função devolve 1;
   caso contrário ela devolve 0.
*/
int remove_ficha (ficha * ptr_estudante, int n, int RA);