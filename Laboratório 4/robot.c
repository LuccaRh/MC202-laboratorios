#include "robot.h"

robo *cria_robo(double *elos, double *angulos, int n)
{
    robo *novo_robo = (robo *)malloc(1 * sizeof(robo));

    if (novo_robo == NULL)
    {
        printf("Erro ao criar robo!\n");
        exit(1);
    }

    novo_robo->elos = (double *)malloc(n * sizeof(double));
    novo_robo->angulos = (double *)malloc(n * sizeof(double));

    if (novo_robo->elos == NULL)
    {
        printf("Erro ao criar robo!\n");
        exit(1);
    }
    if (novo_robo->angulos == NULL)
    {
        printf("Erro ao criar robo!\n");
        exit(1);
    }

    novo_robo->n = n;
    int i;
    for (i = 0; i < n; i++)
    {
        novo_robo->elos[i] = elos[i];
        novo_robo->angulos[i] = angulos[i];
    }

    return novo_robo;
}

void destroi_robo(robo *r1)
{
    free(r1->elos);
    free(r1->angulos);
    free(r1);
}

robo *copia_robo(robo *r1)
{
    robo *novo_robo = cria_robo(r1->elos, r1->angulos, r1->n);
    return novo_robo;
}

double rad2degree(double radian)
{
    return radian * (180 / PI);
}

double degree2rad(double degree)
{
    return degree * (PI / 180);
}

double diff_quad(posicao p1, posicao p2)
{
    double dx, dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return sqrt((dx * dx) + (dy * dy));
}

void compute_gradient2d(posicao dest, robo *r2, double gradient[2])
{
    posicao pose_i = cinematica_direta(r2);
    double fx = diff_quad(dest, pose_i);

    robo *r2_plus1 = copia_robo(r2);
    robo *r2_plus2 = copia_robo(r2);

    r2_plus1->angulos[0] += SAMPLING_DIST;
    r2_plus2->angulos[1] += SAMPLING_DIST;

    posicao pos_plus1, pos_plus2;

    pos_plus1 = cinematica_direta(r2_plus1);
    pos_plus2 = cinematica_direta(r2_plus2);

    double fx_plus1 = diff_quad(dest, pos_plus1);
    double fx_plus2 = diff_quad(dest, pos_plus2);

    gradient[0] = (fx_plus1 - fx) / SAMPLING_DIST;
    gradient[1] = (fx_plus2 - fx) / SAMPLING_DIST;

    destroi_robo(r2_plus1);
    destroi_robo(r2_plus2);
}

double modulo(double num)
{
    if (num < 0)
    {
        return num * (-1);
    }
    else
    {
        return num;
    }
}

posicao cinematica_direta(robo *r)
{
    posicao pos;
    if (r->n == 1)
    {
        double teta = degree2rad(r->angulos[0]);
        pos.x = r->elos[0] * cos(teta);
        pos.y = r->elos[0] * sin(teta);
        return pos;
    }
    else
    {
        double teta = degree2rad(r->angulos[0]);
        double alfa = degree2rad(r->angulos[0] + r->angulos[1]);
        pos.x = r->elos[0] * cos(teta) + r->elos[1] * cos(alfa);
        pos.y = r->elos[0] * sin(teta) + r->elos[1] * sin(alfa);
        return pos;
    }
}

void cinematica_inversa_escalar(posicao dest, robo *r1)
{
    double teta = degree2rad(r1->angulos[0]);
    double xd = r1->elos[0] * cos(teta), yd = r1->elos[0] * sin(teta);
    if (modulo(dest.x - xd) < 0.01 && modulo(dest.y - yd) < 0.01)
    {
        return;
    }
    else
    {
        if (dest.x < xd)
        {
            r1->angulos[0] = r1->angulos[0] + 0.1;
            cinematica_inversa_escalar(dest, r1);
        }
        else
        {
            r1->angulos[0] = r1->angulos[0] - 0.1;
            cinematica_inversa_escalar(dest, r1);
        }
    }
}

void cinematica_inversa_vetorial(posicao dst, robo *r, int iter)
{
    double gradi[2];
    compute_gradient2d(dst, r, gradi);
    r->angulos[0] = r->angulos[0] - r->elos[0] * degree2rad(r->angulos[0]);
    
}