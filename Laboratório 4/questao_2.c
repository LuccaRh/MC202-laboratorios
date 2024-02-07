#include "robot.h"

int main(){
    posicao pos;
    pos.x = 1;
    pos.y = 1;
    double * largura = calloc(2, sizeof(double));
    double * angulo = calloc(2, sizeof(double));
    scanf("%lf %lf %lf %lf", &largura[0], &largura[1], &angulo[0], &angulo[1]); 
    robo * robot = cria_robo(largura, angulo, 2);
    printf("ROBO CRIADO: (%.2lf, %.2lf)\n", robot->angulos[0], robot->angulos[1]);
    while (pos.x != 0 && pos.y != 0){
        scanf("%lf %lf", &pos.x, &pos.y);
        cinematica_inversa_vetorial(pos, robot, 100);
        printf("PROXIMO ESTADO (%.2lf, %.2lf)\n", robot->angulos[0], robot->angulos[1]);
    }
    
    destroi_robo(robot);
    free(largura);
    free(angulo);
    return 0;
}