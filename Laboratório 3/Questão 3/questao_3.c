#include "ficha.h"

typedef struct {
  char le;
  int num;
}entrada;

int main ()
{
  entrada comando;
  ficha *vetorficha; 
  int * fullsize = malloc(sizeof(int));
  int cont = 1, cred = 0;
  
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
        cred = insere_ficha(&vetorficha, fullsize, estudante);
        if (cred == 2){
          cont++;
        } 
      }
    }

    else if (comando.le == 'P'){
      int i;
      for (i = 0; i<(*fullsize)*cont; i++){
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