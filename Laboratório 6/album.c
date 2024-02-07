#include "album.h"


int tamanho(int x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}

p_no cria_arvore(){
  return NULL;
}

void destroi_arvore(p_no raiz){
  if (raiz == NULL){
    return;
  }
  destroi_arvore(raiz->esq);
  destroi_arvore(raiz->dir);
  free(raiz);
}

/*Insere elementos separando por tamanho, se for menor ou igual do que o atual, vai para 
esquerda, se for maior, vai para direita*/
p_no insere_figura(p_no raiz, int figura){
    p_no novo;
    if (raiz == NULL){
      novo = malloc(sizeof(No));
      novo->esq = novo->dir = NULL;
      novo->figura = figura;
      novo->qtd = 1;
      return novo;
    }
    if (figura < raiz->figura)
        raiz->esq = insere_figura(raiz->esq, figura);
    else if (figura == raiz->figura)
        raiz->qtd += 1;
    else
        raiz->dir = insere_figura(raiz->dir, figura);  
    return raiz;
}

void remover_sucessor(p_no raiz){
  p_no min = raiz->dir;
  p_no pai = raiz;
  while (min->esq != NULL){
    pai = min;
    min = min->esq;
  }
  if (pai->esq == min)
    pai->esq = min->dir;
  else
    pai->dir = min->dir;
  raiz->figura = min->figura;
}

p_no remove_figura(p_no raiz, int figura){
  if (raiz == NULL)
    return NULL;
  if (figura < raiz->figura)
    raiz->esq = remove_figura(raiz->esq, figura);
  else if (figura > raiz->figura)
    raiz->dir = remove_figura(raiz->dir, figura);
  else if (raiz->esq == NULL)
    return raiz->dir;
  else if (raiz->dir == NULL)
    return raiz->esq;
  else
    remover_sucessor(raiz);
  return raiz;
}

p_no busca_figura(p_no raiz, int figura){
  if (raiz == NULL || raiz->figura == figura)
    return raiz;
  if (figura < raiz->figura)
    return busca_figura(raiz->esq, figura);
  else
    return busca_figura(raiz->dir, figura);
}

p_no troca_figura(p_no raiz, int figura_i, int figura_o){
  p_no busca = busca_figura(raiz, figura_i);
  if (busca != NULL){ /*Se a figura existe*/
    if (busca->qtd > 1){ /*Se existe uma copia dela*/
        busca->qtd -= 1;
        insere_figura(raiz, figura_o);
        return raiz;
    }
    else{
      return raiz;
    }
  }
  else{
    return raiz;
  }
}