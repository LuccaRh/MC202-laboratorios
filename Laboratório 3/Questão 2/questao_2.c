#include "ficha.h"


int main ()
{
  entrada comando;
  ficha *vetorficha; 
  int * fullsize = malloc(sizeof(int));
  
  while (comando.le != 'F'){  
    scanf("%c", &comando.le); 
    if (comando.le == 'N'){
      scanf("%d", &comando.num); 
      *fullsize = comando.num; 
      vetorficha = cria_fichario(comando.num);
    }

    else if (comando.le == 'I'){ 
      scanf("%d", &comando.num); 
      int i;
      for (i = 0; i<comando.num; i++){ 
        ficha estudante = le_ficha();
        insere_ficha(&vetorficha, fullsize, estudante);
      }
    }

    else if (comando.le == 'P'){
      int i;
      for (i = 0; i<*fullsize; i++){
        ficha *teste = &vetorficha[i]; 
        imprime_ficha(teste);
      }
    }

    else if (comando.le == 'C'){
      float media = calcula_media_CR(vetorficha, *fullsize);
      printf("CR da turma: %.2f\n", media);
    }

    else if (comando.le == 'B'){
      scanf("%d", &comando.num);
      int b = busca_ficha(vetorficha, *fullsize, comando.num);
      if (b == -1){
        printf("RA %d inexistente\n", comando.num);
      }
    }

    else if (comando.le == 'R'){
      scanf("%d", &comando.num);
      int r = remove_ficha(vetorficha, *fullsize, comando.num);
      if (r == 0){
        printf("RA %d inexistente\n", comando.num);
      }
      else {
        printf("RA %d removido\n", comando.num);
      }
    }
  }
  free(fullsize);
  free(vetorficha);
  return 0;
}