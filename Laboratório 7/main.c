#include "restaurante.h"


int main(){
    char com;
    int len = 2;
    p_fp fila = criar_filaprio(99);
    p_fp min = criar_filaprio(99);
    while(1){
        scanf("%c", &com);
        if (com == 'I'){
            Item novo;
            scanf("%s %d %d", novo.snome, &novo.chave, &novo.qtd);
            insere(fila, novo);
            inseremin(min, novo);
        }
        else if (com == 'P'){
            imprime_fila_completa(fila);
        }
        else if (com == 'A'){
            Item mesa = extrai_maximo(fila);
            printf("Mesa disponivel para Sr(a) %s\n", mesa.snome);
            deletemin(min, mesa);
        }
        else if (com == 'L'){
            if (fila->n == 0){
                printf("Fila: []\n");
            }
            else{
                printf("Fila: [%s %0*d ... %s %0*d]\n", fila->v[0].snome, len, fila->v[0].chave, min->v[0].snome, len, min->v[0].chave);
            }
        }
        else if (com == 'R'){
            printf("Raiz: %s %0*d\n", fila->v[0].snome, len, fila->v[0].chave);
        }
        else if (com == 'M'){
            char *sobre = (char *)malloc(50*sizeof(char));
            int p, i;
            scanf("%s %d", sobre, &p);
            for (i = 0; i<fila->n; i++){
                if(strcmp(fila->v[i].snome, sobre) == 0){
                    muda_prioridade(fila, i, p);
                }
            }
            for (i = 0; i<min->n; i++){
                if(strcmp(min->v[i].snome, sobre) == 0){
                    muda_prioridademin(min, i, p);
                }
            }
            free(sobre);
        }
        else if (com == 'F'){
            destroi_filaprio(fila);
            destroi_filaprio(min);
            break;
        }
    }
    return 0;
}