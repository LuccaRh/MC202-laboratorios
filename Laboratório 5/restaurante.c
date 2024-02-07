#include "restaurante.h"

p_entrada cria_lista(){
  p_entrada raiz;
  raiz = NULL;
  return raiz;
}

void destroi_lista(p_entrada lista) {
if (lista != NULL) {
    destroi_lista(lista->prox);
    free(lista);
  }
}

p_entrada le_entrada(){
  NoEntrada novo;
  scanf("%s %d %d %d", novo.nome, &novo.RA, &novo.hora, &novo.min);
  p_entrada novo_no = &novo;
  return novo_no;
}

p_entrada adiciona_entrada(p_entrada lista, p_entrada entrada){
  entrada->prox = lista;
  return entrada;
}

void imprime_lista(p_entrada lista) {
    if (lista != NULL) {
        imprime_lista(lista->prox);
        printf("%d:%d %d %s", lista->hora, lista->min, lista->RA, lista->nome);
    }
}

p_entrada remove_por_ra(p_entrada lista, int ra){
  p_entrada atual;
  p_entrada remove;
  for (atual = lista; atual != NULL; atual = atual->prox){
    if ((atual->RA = ra)){
      remove = atual;
      atual = atual->prox;
      free(remove);
    }
  }
  return lista;
}

void moda(int a, int b, int c, int d){
  int camp1, camp2;
  if (b>=a){
    camp1 = b;
  }
  else{
    camp1 = a;
  }
  if (d>=c){
    camp2 = d;
  }
  else {
    camp2 = c;
  }
  if (camp2>=camp1){
    if ((camp2 = d)){
      printf("Moda: 14h");
    }
    else{
      printf("Moda: 13h");
    }
  }
  else{
    if ((camp1 = b)){
      printf("Moda: 12h");
    }
    else{
      printf("Moda: 11h");
    }
  }
}

void imprime_moda(p_entrada lista){
  int a,b,c,d; /*11, 12, 13, 14*/
  p_entrada caminho = lista;
  while (caminho != NULL){
    if (caminho->hora == 11){
      a += 1;
    }
    else if (caminho->hora == 12){
      b += 1;
    }
    else if (caminho->hora == 13){
      c += 1;
    }
    else if (caminho->hora == 14){
      d += 1;
    }
    caminho = caminho->prox;
  }
  moda(a, b, c, d);
}