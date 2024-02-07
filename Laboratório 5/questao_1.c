#include "restaurante.h"


int main(){
    char com;
    p_entrada lista = cria_lista();
    while (com != 'F'){
        scanf("%c", &com);
        if (com == 'I'){
            p_entrada no = le_entrada();
            lista = adiciona_entrada(lista, no);
        }
        else if (com == 'P'){
            imprime_lista(lista);
        }
        else if (com == 'R'){
            int ra;
            scanf("%d", &ra);
            lista = remove_por_ra(lista, ra);
        }
        else if (com == 'M'){
            imprime_moda(lista);
        }
    }
    return 0;
}