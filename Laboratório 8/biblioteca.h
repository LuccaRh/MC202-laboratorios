#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


#define TAM_MAX_TITULO 200
#define TAM_MAX_NOME 50


typedef struct NoEntrada{
    char snome[TAM_MAX_NOME];
    char titulo[TAM_MAX_TITULO];
    int ano, id;
    struct NoEntrada *prox;
} NoEntrada;

typedef struct NoEntrada * p_entrada;


p_entrada cria_lista();
void destroi_lista(p_entrada lista);
p_entrada adiciona_entrada(p_entrada lista);
void imprime_lista(p_entrada lista);
void remove_por_id(p_entrada lista, int id);
void ordena(p_entrada lista, char categoria[], char a);