#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654
#define SAMPLING_DIST 0.001
#define LR 0.001
#define TOL1 0.01
#define TOL2 0.2


/*
  Definindo um tipo, usando struct, para
  armazenar robos, seus elos e angulos. 
  Variavel n armazena o numero de elos.
*/
typedef struct{
    double *elos;
    double *angulos;
    int n;
} robo;


/*
  Definindo um tipo, usando struct, para armazenar posicao no plano cartesiano
*/
typedef struct{
    double x,y;
} posicao;

double modulo(double num);
/* 
funcao que cria um robo a partir de vetoresde elos e angulos, ambos de tamanho 'n'.
*/
robo * cria_robo(double * elos, double *angulos, int n);

/*
    Função que destroi um robô, liberando seu espaço em memória.
*/
void destroi_robo(robo * r1);

/*
  Cria uma nova cópia de um robô
*/
robo * copia_robo(robo * r1);

/*
  Funcao que converte radiano para graus
*/
double rad2degree(double radian);

/*
  Funcao que converte de graus para radianos
*/
double degree2rad(double degree);

/*
  Diferença de dois pontos no plano cartesiano
*/
double diff_quad(posicao p1, posicao p2);


/*
  Função que computa o gradiente, que pode ser utilizada na questão 2.
  Recebe uma posição destino, um robô com dois elos e um vetor gradiente de duas posições (um para cada ângulo).
*/
void compute_gradient2d(posicao dest, robo * r2, double gradient[2]);


/* -------------- FUNCOES A SEREM DESENVOLVIDAS --------------*/


/*
  Função que computa a cinemática direta do robô.
  Recebe um ponteiro para um robô e retorna a posição no plano.
  Deve funcionar tanto para robôs de um e dois graus de liberdade.
*/
posicao cinematica_direta(robo *r);

/*
  Função que computa a cinemática inversa por aproximação numérica recursiva.
  Recebe uma posição destino e um robô com um grau de liberdade.
  Deve atualizar o angulo no próprio r1.
*/
void cinematica_inversa_escalar(posicao dest, robo *r1);


/*
  Função que computa a cinemática inversa por aproximação numérica recursiva.
  Recebe uma posição destino e um robô com dois graus de liberdade.
  Deve atualizar o angulo no próprio r2.

  Além disso pode receber um inteiro 'iter' para reduzir o número máximo de iterações.
*/
void cinematica_inversa_vetorial(posicao dst, robo *r, int iter)