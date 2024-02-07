#include "restaurante.h"

void troca(Item *a, Item *b){
    Item t;
    t = *a;
    *a = *b;
    *b = t;
}

p_fp criar_filaprio(int tam) {
    p_fp fprio = malloc(sizeof(FP));
    fprio->v = malloc(tam * sizeof(Item));
    fprio->n = 0;
    fprio->tamanho = tam;
    return fprio;
}

void insere(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n -1);
}

void sobe_no_heap(p_fp fprio, int k) {
    int PAI = (k-1)/2;
    if (k > 0 && fprio->v[PAI].chave < fprio->v[k].chave) {
        troca(&fprio->v[k], &fprio->v[PAI]);
        sobe_no_heap(fprio, PAI);
    }
}

Item extrai_maximo(p_fp fprio) {
    Item item = fprio->v[0];
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    fprio->v[fprio->n + 1] = fprio->v[fprio->n + 5];
    return item;
}

void desce_no_heap(p_fp fprio, int k) {
    int maior_filho;
    int F_ESQ = 2*k+1;
    int F_DIR = 2*k+2;
    if (F_ESQ < fprio->n) {
        maior_filho = F_ESQ;
        if (F_DIR < fprio->n && fprio->v[F_ESQ].chave < fprio->v[F_DIR].chave)
            maior_filho = F_DIR;
        if (fprio->v[k].chave < fprio->v[maior_filho].chave) {
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, maior_filho);
        }
    }
}

void muda_prioridade(p_fp fprio, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        sobe_no_heap(fprio, k);
    } 
    else {
        fprio->v[k].chave = valor;
        desce_no_heap(fprio, k);
    }
}

void destroi_filaprio(p_fp fila){
    free(fila->v);
    free(fila);
}

void imprime_fila_completa(p_fp fila){
    int i, j, a, len = 2;
    Item *array = malloc(fila->n * sizeof(Item));
    for (i = 0; i<fila->n; i++){
        array[i] = fila->v[i];
    }
    for (i = 0; i < fila->n; ++i) 
        {
            for (j = i + 1; j < fila->n; ++j) 
            {
                if (array[i].chave < array[j].chave) 
                {
                    a = array[i].chave;
                    array[i].chave = array[j].chave;
                    array[j].chave = a;
                }
            }
        }
    for (i = 0; i< fila->n; i++){
        printf("%0*d %0*d %s\n", len, array[i].chave, len, array[i].qtd, array[i].snome);
    }
    free(array);
}

/*Funções para min heap, praticamente espelho das de maxheap*/
void sobe_no_minheap(p_fp fprio, int k) {
    int PAI = (k-1)/2;
    if (k > 0 && fprio->v[PAI].chave > fprio->v[k].chave) {
        troca(&fprio->v[k], &fprio->v[PAI]);
        sobe_no_minheap(fprio, PAI);
    }
}
void inseremin(p_fp fprio, Item item) {
    fprio->v[fprio->n] = item;
    fprio->n++;
    sobe_no_minheap(fprio, fprio->n -1);
}

void desce_no_heapmin(p_fp fprio, int k) {
    int menor_filho;
    int F_ESQ = 2*k+1;
    int F_DIR = 2*k+2;
    if (F_ESQ < fprio->n) {
        menor_filho = F_ESQ;
        if (F_DIR < fprio->n && fprio->v[F_ESQ].chave > fprio->v[F_DIR].chave)
            menor_filho = F_DIR;
        if (fprio->v[k].chave > fprio->v[menor_filho].chave) {
            troca(&fprio->v[k], &fprio->v[menor_filho]);
            desce_no_heapmin(fprio, menor_filho);
        }
    }
}
void muda_prioridademin(p_fp fprio, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        desce_no_heapmin(fprio, k);
    } 
    else {
        fprio->v[k].chave = valor;
        sobe_no_minheap(fprio, k);
    }
}
/*Similar a extrai_maximo, usada para deletar o mesmo item que foi deletado no max, logo, faz um loop para achar
esse elemento, é trocado com o último elemento do min, esse ultimo faz a descida para ajustar tudo,
e o que foi trocado é deletado, ou seja, é igualado a um espaço vazio da array de itens*/
void deletemin(p_fp fprio, Item item){
    int i;
    for (i = 0; i<fprio->n; i++){
        if (strcmp(fprio->v[i].snome, item.snome) == 0){
            troca(&fprio->v[i], &fprio->v[fprio->n]);
            desce_no_heapmin(fprio, i);
            fprio->n--;
            fprio->v[fprio->n + 1] = fprio->v[fprio->n + 5];
        }
    }
}