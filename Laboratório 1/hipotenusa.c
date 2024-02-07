#include"funcoes.h"
#include <stdio.h>

int main(){
	double cateto1, cateto2, hipo;
	printf("Por favor, digite os dois catetos (ou dois números negativos para parar):\n");
	while (1){
		scanf("%lf %lf", &cateto1, &cateto2);
		if (cateto1 < 0 | cateto2 < 0){
			break;		
		}
		hipo = hipotenusa(cateto1, cateto2);
		printf("hipotenusa eh %0.2lf", hipo);
	}
	return 0;
}