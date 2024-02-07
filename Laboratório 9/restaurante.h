#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX_NOME 50
#define MAX_HASH 99
#define NULO 1000000

typedef struct {
  char nome[TAM_MAX_NOME];
  int indexmax;
  int indexmin;
  int vazio;
} No;

typedef No * p_no;

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

/*Funcoes hash*/
p_no criar_hash();
int hashf(char nome[]);
void insere_hash(p_no hash, No pessoa);
void delete_hash(p_no hash, char nome[]);
void trocaindexmax(p_no hash, char a[], char b[]);
void trocaindexmin(p_no hash, char a[], char b[]);

/*Funcoes max heap*/
void troca(Item *a, Item *b);
p_fp criar_filaprio(int tam);
void insere(p_fp fprio, Item item, p_no hash, p_fp min);
void sobe_no_heap(p_fp fprio, int k, p_no hash);
void desce_no_heap(p_fp fprio, p_no hash, int k);
void muda_prioridade(p_fp fprio, p_no hash, int k, int valor);
Item extrai_maximo(p_fp fprio, p_no hash);
void destroi_filaprio(p_fp fila);
void imprime_fila_completa(p_fp fila);

/*Funcoes min heap*/
void sobe_no_minheap(p_fp fprio, int k, p_no hash);
void desce_no_heapmin(p_fp fprio, p_no hash, int k);
void muda_prioridademin(p_fp fprio, p_no hash, int k, int valor);
void deletemin(p_fp fprio, p_no hash, Item item);