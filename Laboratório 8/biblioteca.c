#include "biblioteca.h"

p_entrada cria_lista(){
  return NULL;
}

void destroi_lista(p_entrada lista) {
  if (lista != NULL) {
    destroi_lista(lista->prox);
    free(lista);
  }
}

p_entrada adiciona_entrada(p_entrada lista) {
  p_entrada novo;
  novo = malloc(sizeof(NoEntrada));
  scanf("%s %d %d", novo->snome, &novo->ano, &novo->id);
  scanf("%[^\n]%*c", novo->titulo);
  novo->prox = lista;
  return novo;
}

void imprime_lista(p_entrada lista) {
  if (lista != NULL){
    printf("%d %d %s%s\n", lista->id, lista->ano, lista->snome, lista->titulo);
    imprime_lista(lista->prox);
  }
}

void remove_por_id(p_entrada lista, int id)
{
  p_entrada temp = lista, ant;
  if (temp != NULL && temp->id == id) {
      lista = temp->prox;
      printf("Removido cadastro %d\n", temp->id);
      free(temp);
      return;
  }
  while (temp != NULL && temp->id != id) {
      ant = temp;
      temp = temp->prox;
  }
  if (temp == NULL)
      return;
  ant->prox = temp->prox;
  printf("Removido cadastro %d\n", temp->id);
  free(temp);
}

void troca_conteudo(p_entrada a, p_entrada b) 
{ 
  NoEntrada t;
  t.ano = a->ano;
  t.id = a->id;
  strcpy(t.snome, a->snome);
  strcpy(t.titulo, a->titulo);
  a->ano = b->ano;
  a->id = b->id;
  strcpy(a->snome, b->snome);
  strcpy(a->titulo, b->titulo);
  b->ano = t.ano;
  b->id = t.id;
  strcpy(b->snome, t.snome);
  strcpy(b->titulo, t.titulo);
} 

void ordena(p_entrada lista, char categoria[], char a)
{ 
  int troca; 
  p_entrada temp; 
  p_entrada lptr = NULL; 
  if (lista == NULL) 
    return; 
  do
  { 
    troca = 0; 
    temp = lista; 
    while (temp->prox != lptr) 
    { 
      if (a == 'a'){
        if (strcmp(categoria, "ano") == 0){
          if (temp->ano > temp->prox->ano){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "id") == 0){
          if (temp->id > temp->prox->id){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "titulo") == 0){
          if (strcmp(temp->titulo, temp->prox->titulo) > 0){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "sobrenome") == 0){
          if (strcmp(temp->snome, temp->prox->snome) > 0){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
      }
      else if (a == 'd'){
        if (strcmp(categoria, "ano") == 0){
          if (temp->ano < temp->prox->ano){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "id") == 0){
          if (temp->id < temp->prox->id){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "titulo") == 0){
          if (strcmp(temp->titulo, temp->prox->titulo) < 0){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
        else if (strcmp(categoria, "sobrenome") == 0){
          if (strcmp(temp->snome, temp->prox->snome) < 0){ 
            troca_conteudo(temp, temp->prox); 
            troca = 1; 
          } 
        }
      }
      temp = temp->prox; 
    } 
    lptr = temp; 
  } while (troca); 
}