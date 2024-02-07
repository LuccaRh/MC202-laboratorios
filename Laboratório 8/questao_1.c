#include "biblioteca.h"

int main(){
    char com;
    p_entrada lista = cria_lista();
    while(1){
        scanf("%c", &com);
        if (com == 'I'){
            lista = adiciona_entrada(lista);
        }
        else if (com == 'P'){
            printf("Livros cadastrados = [\n");
            imprime_lista(lista);
            printf("]\n");
        }
        else if (com == 'R'){
            int id;
            scanf("%d", &id);
            remove_por_id(lista, id);
        }
        else if (com == 'O'){
            char categoria[15];
            char ordem;
            scanf("%s %c", categoria, &ordem);
            ordena(lista, categoria, ordem);
        }
        else if (com == 'F'){
            destroi_lista(lista);
            break;
        }
    }
    return 0;
}