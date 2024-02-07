#include "ficha.h"

int main ()
{
  entrada comando;
  ficha *vetorficha; 
  int * fullsize = malloc(sizeof(int)); 
  
  while (comando.le != 'F'){  
    /*Leitura da letra*/
    scanf("%c", &comando.le); 

    if (comando.le == 'N'){
      /*Leitura do número*/
      scanf("%d", &comando.num); 
      /*ponteiro para tamanho do vetor*/
      *fullsize = comando.num; 
      /*Criação do fichario */
      vetorficha = cria_fichario(comando.num); 
    }

    else if (comando.le == 'I'){ 
      /*Leitura do número*/
      scanf("%d", &comando.num); 
      int i;
      for (i = 0; i<comando.num; i++){ 
        /*Criação de ficha individual, e inserindo ela no vetorficha*/
        ficha estudante = le_ficha(); 
        insere_ficha(&vetorficha, fullsize, estudante);
      }
    }

    else if (comando.le == 'P'){
      int i;
      for (i = 0; i<*fullsize; i++){
        /*Criação de ponteiro para ficha dentro do vetor*/
        ficha * teste = &vetorficha[i]; 
        imprime_ficha(teste);
      }
    }

    else if (comando.le == 'C'){
      float media = calcula_media_CR(vetorficha, *fullsize);
      printf("CR da turma: %.2f\n", media);
    }
  }
  free(fullsize);
  free(vetorficha);
  return 0; 
}