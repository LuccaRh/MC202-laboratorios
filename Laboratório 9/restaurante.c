#include "restaurante.h"

/*Hash funçoes*/

p_no criar_hash (){
    p_no hash = malloc(MAX_HASH * sizeof(No));
    int i;
    for (i = 0; i<MAX_HASH; i++){
        hash[i].vazio = NULO;
    }
    return hash;
}

int hashf(char nome[]){
    int len = strlen(nome);
    unsigned int hash_value = 0;
    int i;
    for (i = 0; i<len; i++){
        hash_value += nome[i];
        hash_value = (hash_value * nome[i]) % MAX_HASH;
    }
    return hash_value;
}

void insere_hash(p_no hash, No pessoa){
    int value = hashf(pessoa.nome);
    int i;
    for (i = 0; i<MAX_HASH; i++){
        int index = (i + value) % MAX_HASH;
        if (hash[index].vazio == NULO){
            hash[index] = pessoa;
            return;
        }
    }
}

void delete_hash(p_no hash, char nome[]){
    int value = hashf(nome);
    int i;
    for (i = 0; i<MAX_HASH; i++){
        int index = (i + value) % MAX_HASH;
        if (hash[index].vazio != NULO && strcmp(hash[index].nome, nome) == 0){
            hash[index].vazio = NULO;
            return; 
        }
    }
}

void trocaindexmax(p_no hash, char a[], char b[]){
    int first = hashf(a);
    int secon = hashf(b);
    No t;
    t.indexmax = hash[first].indexmax;
    hash[first].indexmax = hash[secon].indexmax;
    hash[secon].indexmax = t.indexmax;
}
void trocaindexmin(p_no hash, char a[], char b[]){
    int first = hashf(a);
    int secon = hashf(b);
    No t;
    t.indexmin = hash[first].indexmin;
    hash[first].indexmin = hash[secon].indexmin;
    hash[secon].indexmin = t.indexmin;
}


/*Max Heap funçoes*/
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

void insere(p_fp fprio, Item item, p_no hash, p_fp min) {
    fprio->v[fprio->n] = item;
    fprio->n++;
    min->v[min->n] = item;
    min->n++;
    No novoh = {.indexmax = (fprio->n)-1, .indexmin = (fprio->n)-1};
    strcpy(novoh.nome, item.snome);
    insere_hash(hash, novoh);
    sobe_no_heap(fprio, fprio->n -1, hash);
    sobe_no_minheap(min, min->n -1, hash);
}

void sobe_no_heap(p_fp fprio, int k, p_no hash) {
    int PAI = (k-1)/2;
    if (k > 0 && fprio->v[PAI].chave < fprio->v[k].chave) {
        trocaindexmax(hash, fprio->v[k].snome, fprio->v[PAI].snome);
        troca(&fprio->v[k], &fprio->v[PAI]);
        sobe_no_heap(fprio, PAI, hash);
    }
}

Item extrai_maximo(p_fp fprio, p_no hash) {
    Item item = fprio->v[0];
    trocaindexmax(hash, fprio->v[0].snome, fprio->v[(fprio->n) - 1].snome);
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, hash, 0);
    delete_hash(hash, fprio->v[fprio->n + 1].snome);
    fprio->v[fprio->n + 1] = fprio->v[fprio->n + 5];
    return item;
}

void desce_no_heap(p_fp fprio, p_no hash, int k) {
    int maior_filho;
    int F_ESQ = 2*k+1;
    int F_DIR = 2*k+2;
    if (F_ESQ < fprio->n) {
        maior_filho = F_ESQ;
        if (F_DIR < fprio->n && fprio->v[F_ESQ].chave < fprio->v[F_DIR].chave)
            maior_filho = F_DIR;
        if (fprio->v[k].chave < fprio->v[maior_filho].chave) {
            trocaindexmax(hash, fprio->v[k].snome, fprio->v[maior_filho].snome);
            troca(&fprio->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio, hash, maior_filho);
        }
    }
}

void muda_prioridade(p_fp fprio, p_no hash, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        sobe_no_heap(fprio, k, hash);
    } 
    else {
        fprio->v[k].chave = valor;
        desce_no_heap(fprio, hash, k);
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



/*Min Heap funçoes*/
void sobe_no_minheap(p_fp fprio, int k, p_no hash) {
    int PAI = (k-1)/2;
    if (k > 0 && fprio->v[PAI].chave > fprio->v[k].chave) {
        trocaindexmin(hash, fprio->v[k].snome, fprio->v[PAI].snome);
        troca(&fprio->v[k], &fprio->v[PAI]);
        sobe_no_minheap(fprio, PAI, hash);
    }
}

void desce_no_heapmin(p_fp fprio, p_no hash, int k) {
    int menor_filho;
    int F_ESQ = 2*k+1;
    int F_DIR = 2*k+2;
    if (F_ESQ < fprio->n) {
        menor_filho = F_ESQ;
        if (F_DIR < fprio->n && fprio->v[F_ESQ].chave > fprio->v[F_DIR].chave)
            menor_filho = F_DIR;
        if (fprio->v[k].chave > fprio->v[menor_filho].chave) {
            trocaindexmin(hash, fprio->v[k].snome, fprio->v[menor_filho].snome);
            troca(&fprio->v[k], &fprio->v[menor_filho]);
            desce_no_heapmin(fprio, hash, menor_filho);
        }
    }
}
void muda_prioridademin(p_fp fprio, p_no hash, int k, int valor) {
    if (fprio->v[k].chave < valor) {
        fprio->v[k].chave = valor;
        desce_no_heapmin(fprio, hash, k);
    } 
    else {
        fprio->v[k].chave = valor;
        sobe_no_minheap(fprio, k, hash);
    }
}

void deletemin(p_fp fprio, p_no hash, Item item){
    int i;
    for (i = 0; i<fprio->n; i++){
        if (strcmp(fprio->v[i].snome, item.snome) == 0){
            trocaindexmin(hash, fprio->v[i].snome, fprio->v[fprio->n - 1].snome);
            troca(&fprio->v[i], &fprio->v[fprio->n - 1]);
            desce_no_heapmin(fprio, hash, i);
            fprio->n--;
            fprio->v[fprio->n + 1] = fprio->v[fprio->n + 5];
        }
    }
}