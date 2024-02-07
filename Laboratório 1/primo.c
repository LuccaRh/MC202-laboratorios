#include"funcoes.h"

int main(){
	int n, as;
	printf("Digite um numero:");
	scanf("%d", &n);
	as = is_primo(n);
	if (as == 1){
	 	printf("Numero primo!\n");	
	} else { printf("Numero nao primo!\n");}
	return 0;
}