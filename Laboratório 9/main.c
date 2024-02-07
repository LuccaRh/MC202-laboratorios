#include "restaurante.h"

/*Criar Hash que possui nome, index min, e index max.
Vai ser usado para o comando 'M', assim não precisando criar dois for loops para pegar o index de cada heap.
Fazer uma função hash
Fazer uma função para criar o hash
Fazer uma função para inserir elementos no hash
Fazer uma função para deletar elementos do hash
Fazer uma função para mudar index de um elemento (simplismente indo até ele, e trocar os index).
*/

int main(){
    char com;
    int len = 2;
    p_fp fila = criar_filaprio(99);
    p_fp min = criar_filaprio(99);
    p_no hash = criar_hash();
    while(1){
        scanf("%c", &com);
        if (com == 'I'){
            Item novo;
            scanf("%s %d %d", novo.snome, &novo.chave, &novo.qtd);
            insere(fila, novo, hash, min);
        }
        else if (com == 'P'){
            imprime_fila_completa(fila);
        }
        else if (com == 'A'){
            Item mesa = extrai_maximo(fila, hash);
            printf("Mesa disponivel para Sr(a) %s\n", mesa.snome);
            deletemin(min, hash, mesa);
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
            i = hashf(sobre);
            muda_prioridade(fila, hash, hash[i].indexmax, p);
            muda_prioridademin(min, hash, hash[i].indexmin, p);
            free(sobre);
        }
        else if (com == 'F'){
            destroi_filaprio(fila);
            destroi_filaprio(min);
            free(hash);
            break;
        }
    }
    return 0;
}