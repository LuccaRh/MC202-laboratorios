#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX_NOME 50

typedef struct {
    char snome[TAM_MAX_NOME];
    int qtd;
    int chave;
} Item;

/*Array com elementos dp tipo Item, possui n elementos, e um tamanho máximo*/
typedef struct {
    Item *v; 
    int n, tamanho;
} FP;

typedef FP * p_fp;


/*************************
Funcoes recomendadas
*************************/
void troca(Item *a, Item *b);
/*Funcao que cria uma nova fila de prioridade*/
p_fp criar_filaprio(int tam);

/*Insere novo item na */
void insere(p_fp fprio , Item item);

/*sobe elemento na heap*/
void sobe_no_heap(p_fp fprio, int k);

/*desce elemento na heap*/
void desce_no_heap(p_fp fprio, int k);

/* muda prioridade de um elemento (deve ser O(lg n))*/
void muda_prioridade(p_fp fprio, int k, int valor);

/*Extrai o maximo*/
Item extrai_maximo(p_fp fprio);

void destroi_filaprio(p_fp fila);

Item le_item_fila();

void imprime_resumo_fila(p_fp fila);

void imprime_fila_completa(p_fp fila);


void sobe_no_minheap(p_fp fprio, int k);

void inseremin(p_fp fprio, Item item);

void desce_no_heapmin(p_fp fprio, int k);

void muda_prioridademin(p_fp fprio, int k, int valor);

void deletemin(p_fp fprio, Item item);