#include "album.h"


void imprime(p_no raiz, int leng){
    if (raiz == NULL){
        return;
    }
    imprime(raiz->esq, leng);
    printf("%0*d %d\n", leng, raiz->figura, raiz->qtd);
    imprime(raiz->dir, leng);
}

int main(){
    char com;
    int n, k, leng;
    p_no album;
    while (1){
        scanf("%c", &com);
        if (com == 'A'){
            scanf("%d", &n);
            leng = tamanho(n);
            album = cria_arvore();
            printf("ALBUM CRIADO PARA %d FIGURINHAS\n", n);
        }
        else if (com == 'I'){
            scanf("%d", &k);
            int i;
            for (i = 0; i<k; i++){
                int figura;
                scanf("%d", &figura);
                album = insere_figura(album, figura);
            }
            printf("%d FIGURINHAS INSERIDAS\n", k);
        }
        else if (com == 'T'){
            int fig1, fig2;
            scanf("%d %d", &fig1, &fig2);
            album = troca_figura(album, fig1, fig2);
            if (busca_figura(album, fig2) != NULL){
                printf("%0*d TROCADA PELA %0*d\n", leng, fig1, leng, fig2);
            }
            else{
                printf("%0*d NAO TROCADA\n", leng, fig1);
            }
        }
        else if (com == 'P'){
            imprime(album, leng);
        }
        else if (com == 'F'){
            destroi_arvore(album);
            break;
        }
    }
    return 0;
}