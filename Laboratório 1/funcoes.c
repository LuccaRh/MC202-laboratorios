#include"funcoes.h"

double raiz(double num){
    float temp, raiz;
    raiz = num / 2;
    temp = 0;
    while(raiz != temp){
        temp = raiz;
        raiz = ( num/temp + temp) / 2;
    }
	return raiz;
}

int is_primo(int n){
        int a = 0, i;
        for (i = 1; i<n+1; i++){
            if (n%i == 0){
                a += 1;
            }
        }
        if (a == 2){
            return 1;	
        } else {return 0;}
}

float hipotenusa(float cateto1, float cateto2){
	double hipo, soma;
	soma = cateto1*cateto1 + cateto2*cateto2;
	hipo = raiz(soma);
    return hipo;
}

float cateto_from_matrix(int m[2][2]){
    float det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    if (det > 0){
        float hipo = raiz(2)*raiz(det);
        return hipo;
    } else if (det < 0){
        return -1.23;
    }else {
        return 0;}
}