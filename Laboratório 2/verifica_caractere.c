#include "funcoes.h"

int main(){
	char cha;
	char s[MAX];
	int teste = 0;
	scanf("%c", &cha);
	scanf("%s", s);
	teste = analise_caractere(cha, s);
	printf("%d", teste);
	return 0;
}