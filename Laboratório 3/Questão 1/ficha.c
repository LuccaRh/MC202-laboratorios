#include "ficha.h"


float calcula_media_CR (ficha * ptr_estudante, int n)
{
  float media = 0;
  int i;
  for (i = 0; i<n; i++){
    media += ptr_estudante[i].CR/n;
  }
  return media;
}


ficha * cria_fichario (int n)
{
  ficha *v = malloc(n * sizeof(ficha)); /*Criação de vetor de ficha, com n fichas*/
  /*Setando todos os RA para zero*/
  int i;
  for (i = 0; i<n; i++){
    v[i].RA = 0;
  }
  return v;
}


void imprime_ficha(ficha * estudante)
{
  if ((*estudante).RA != 0){ /*Se RA for diferente de zero, ou seja, tem uma ficha no local, imprimir*/
    printf("%.2f %d %s %s\n", (*estudante).CR, (*estudante).RA, (*estudante).primeiro_nome, (*estudante).ultimo_nome);
  }
}


int insere_ficha (ficha ** ptr_estudante, int * n, ficha estudante)
{
  int a = 0, c;
  for (c = 0; c<*n; c++){
    if ((*ptr_estudante)[c].RA != 0){
      a++; /*Ver se tem espaços sobrando (RA igual a zero)*/
    }
    else{ /*Se tiver, adicionar a ficha estudante*/
      strcpy((*ptr_estudante)[c].primeiro_nome, estudante.primeiro_nome);
      strcpy((*ptr_estudante)[c].ultimo_nome, estudante.ultimo_nome); 
      (*ptr_estudante)[c].RA = estudante.RA;
      (*ptr_estudante)[c].CR = estudante.CR;
      return 1;
    }
  }
  if (a == (*n)){ /*Se tiver cheio (todos RA diferentes de zero), mostrar erro*/
    printf("Erro inserindo %s\n", estudante.primeiro_nome);
    return 0;
  }
  return 0;
}



ficha le_ficha(){
  ficha estudante;
  scanf("%s %s %d %f", estudante.primeiro_nome, estudante.ultimo_nome, &estudante.RA, &estudante.CR);
  return estudante;
}