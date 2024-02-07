#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX_NOME 50


typedef struct
{
  char  primeiro_nome[TAM_MAX_NOME], ultimo_nome[TAM_MAX_NOME];
  int   RA;
  float CR;
} ficha;

int busca_ficha (ficha * ptr_estudante, int n, int RA);

float calcula_media_CR (ficha * ptr_estudante, int n);

ficha * cria_fichario (int n);

void imprime_ficha(ficha * estudante);

int insere_ficha (ficha ** ptr_estudante, int *n, ficha estudante);

ficha le_ficha();

int remove_ficha (ficha * ptr_estudante, int n, int RA);