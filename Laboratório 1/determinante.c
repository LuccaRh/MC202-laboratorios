#include"funcoes.h"

int main(){

    int v1,v2,v3,v4;

    int m[2][2];

    float det = 0;
    printf("Digite os 4 numeros:");
    scanf("%d %d %d %d", &v1, &v2, &v3, &v4);
    m[0][0] = v1;
    m[0][1] = v2;
    m[1][0] = v3;
    m[1][1] = v4;

    float cateto = cateto_from_matrix(m);
    if (cateto > 0){
        printf("Determinante positivo!\n");
        printf("Hipotenusa do triangulo retangulo igual a %0.2f", cateto);
    } else if (cateto < 0){
        printf("Determinante Negativo!");
    }else {printf("Determinante Nulo!");}
    return 0;
}