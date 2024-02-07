#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*Matriz*/
char ** CriarmatrizChar(int l, int c){
    char **matriz;
    int i;
    matriz = malloc(l * sizeof(char *)); 
    for (i = 0; i<l; i++){
        matriz[i] = malloc(c * sizeof(char));
    }
    return matriz;
}

int ** Criarmatriz(int l, int c){
    int **matriz;
    int i;
    matriz = malloc(l * sizeof(int *)); 
    for (i = 0; i<l; i++){
        matriz[i] = malloc(c * sizeof(int));
    }
    return matriz;
}

void AlocarElementos(int l, int c, char ** matriz){
    int i, j;
    for (i = 0; i<l; i++){
        for (j = 0; j<c; j++){
            char c = getchar();
            if (c == '\n' || c == ' '){
                c = getchar();
            }
            matriz[i][j] = c;
        }
    }
}

int ** CopiaMatriz(int l, int c, char ** matriz){
    int ** copia = Criarmatriz(l, c);
    int i, j;
    for (i = 0; i<l; i++){
        for (j = 0; j<c; j++){
            if (matriz[i][j] == '0'){
                copia[i][j] == 0;
            }
            if (matriz[i][j] == '1'){
                copia[i][j] == 1;
            }
            if (matriz[i][j] == 'R'){
                copia[i][j] == 2;
            }
            if (matriz[i][j] == 'G'){
                copia[i][j] == 3;
            }
        }
    }
    return copia;
}

void ApagarMatriz(int l, int ** matriz){
    int i, j;
    for (i = 0; i<l; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void ApagarMatrizChar(int l, char ** matriz){
    int i, j;
    for (i = 0; i<l; i++){
        free(matriz[i]);
    }
    free(matriz);
}


/*Labirinto*/
typedef struct{
    int x;
    int y;
}pos;

pos acharR(int l, int c, int ** matriz){
    int i, j;
    pos r;
    for (i = 0; i<l; i++){
        for (j = 0; j<c; j){
            if (matriz[i][j] == 2){
                r.x = i;
                r.y = j;
                return r;
            }
        }
    }
}

void proxima_posicao(int x, int y, int k, int *nl, int *nc) {
    static int movimentos[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    *nl = x + movimentos[k][0];
    *nc = y + movimentos[k][1];
}

int Rhistorico(int ** historico, int s, int px, int py){
    /*Revisão de histórico de movimentos*/
    int i;
    for (i = 0; i<s; i++){
        if (historico[s][0] == px && historico[s][1] == py){
            return 0;
        }
    }
    return 1;
}

int labirintoR(int ** matriz, int ** historico, int ** caminho, int x, int y, int l, int c, int s){
    int k, px, py;
    s = 1;
    if (matriz[x][y] == 3){
        return 1;
    }
    for (k = 0; k<4; k++){
        proxima_posicao(x, y, k, &px, &py);
        if ((px >= 0) && (px < l) && (py >= 0) && (py < c) && (matriz[px][py] == 0) 
        && Rhistorico(historico, s, px ,py) == 1){
            s++;
            historico[s][0] = px;
            historico[s][1] = py;
            if (labirintoR(matriz, historico, caminho, px, py, l, c, s)){
                return 1;
            }
        }
    }
    return 0;
}

int labirinto(int l, int c, int ** matriz, int ** historico, int ** caminho, int s){
    int x, y;
    pos r = acharR(l, c, matriz);
    x = r.x;
    y = r.y;
    historico = Criarmatriz(1000, 2);
    caminho = Criarmatriz(100, 2);
    historico[0][0] = x;
    historico[0][1] = y;
    caminho[0][0] = x;
    caminho[0][1] = y;
    return labirintoR(matriz, historico, caminho, x, y, l, c, s);
}
/*
Achar R
Começar a movimentar por 0
Guardar posições ja passadas, e do caminho atual
Ir para posições com 0, e que não foram passadas
Até encontrar G;
*/


int main(){
    int i, l, c, s;
    scanf("%d %d", &l, &c);
    char ** matriz = CriarmatrizChar(l, c);
    AlocarElementos(l, c, matriz);
    int ** matrizc = CopiaMatriz(l, c, matriz);
    int ** historico = Criarmatriz(1000, 2);
    int ** caminho = Criarmatriz(100, 2);
    labirinto(l, c, matrizc, historico, caminho, s);
    for (i = 0; i<s; i++){
        printf("(%d %d)\n", historico[s][0], historico[s][1]);
    }
    ApagarMatrizChar(l, matriz);
    ApagarMatriz(l, matrizc);
    ApagarMatriz(1000, historico);
    ApagarMatriz(100, caminho);
    return 0;
}