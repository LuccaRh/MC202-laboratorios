#include"funcoes.h"

/*As funções caps, size e strcmp2 foram implementadas apenas porque não era possível
usar a biblioteca string.h*/
/*Função usada para transformar uma string em maiusculo
Char em c é uma tradução de um número para uma letra, por exemplo, o número 97 é traduzido
para a letra "a". 
Logo, as letras maiusculas estão reservadas num número 32 anterior ao minusculo, assim
se a = 97, A = 97 - 32*/
void caps(char s[]){
    int i;
/*For loop até final da string*/
    for (i = 0; s[i]!='\0'; i++) {
/*Ver se a a letra é minuscula, se for, transforma-la em maiuscula*/
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] -32;
        }
    }
}
/*Função que mostra o comprimento de uma string*/
int size(char palavra[]){
    int comprimento = 0;
    while (palavra[comprimento] != '\0') {
        comprimento += 1;
    }
    return comprimento;
}
/*Função que ve se duas strings são iguais, se for, retorna o número 0*/
int strcmp2(const char *s1, const char *s2) {
  const unsigned char *us1 = (const unsigned char *) s1;
  const unsigned char *us2 = (const unsigned char *) s2;
  while (*us1 == *us2 && *us1 != '\0') {
    us1++;
    us2++;
  }
  return (*us1 > *us2) - (*us1 < *us2);
}
int analise_caractere(char c, char s[]){
	int i, a = 0, comprimento;
    comprimento = size(s);
	caps(s);
    if(c >= 'a' && c <= 'z'){
	    c = c - 32;
    }
	for (i=0; i<=comprimento; i++){
		if (c == s[i]){
			a+= 1;}
	}
	return a;
}
void add(char r[], char s[]){
    int i;
    if (strcmp2(s, "TTT") == 0 || strcmp2(s, "TTC") == 0){
        i = size(r);
        r[i] = 'F';
    }
    else if(strcmp2(s, "TTA") == 0 || strcmp2(s, "TTG") == 0 || strcmp2(s, "CTT") == 0
    || strcmp2(s, "CTC") == 0 || strcmp2(s, "CTA") == 0 || strcmp2(s, "CTG") == 0){
        i = size(r);
        r[i] = 'L';
    }
    else if (strcmp2(s, "ATT") == 0 || strcmp2(s, "ATC") == 0 || strcmp2(s, "ATA") == 0 ){
        i = size(r);
        r[i] = 'I';
    }
    else if (strcmp2(s, "ATG") == 0){
        i = size(r);
        r[i] = 'M';
    }
    else if (strcmp2(s, "GTT") == 0 || strcmp2(s, "GTC") == 0 || strcmp2(s, "GTA") == 0 
    || strcmp2(s, "GTG") == 0 ){
        i = size(r);
        r[i] = 'V';
    }
    else if (strcmp2(s, "TCT") == 0 || strcmp2(s, "TCC") == 0 || strcmp2(s, "TCA") == 0 
    || strcmp2(s, "TCG") == 0 ){
        i = size(r);
        r[i] = 'S';
    }
    else if (strcmp2(s, "CCT") == 0 || strcmp2(s, "CCC") == 0 || strcmp2(s, "CCA") == 0 
    || strcmp2(s, "CCG") == 0 ){
        i = size(r);
        r[i] = 'P';
    }
    else if (strcmp2(s, "ACT") == 0 || strcmp2(s, "ACC") == 0 || strcmp2(s, "ACA") == 0 
    || strcmp2(s, "ACG") == 0 ){
        i = size(r);
        r[i] = 'T';
    }
    else if (strcmp2(s, "GCT") == 0 || strcmp2(s, "GCC") == 0 || strcmp2(s, "GCA") == 0 
    || strcmp2(s, "GCG") == 0 ){
        i = size(r);
        r[i] = 'A';
    }
    else if (strcmp2(s, "TAT") == 0 || strcmp2(s, "TAC") == 0){
        i = size(r);
        r[i] = 'Y';
    }
    else if (strcmp2(s, "TAA") == 0 || strcmp2(s, "TAG") == 0 || strcmp2(s, "TGA") == 0){
        i = size(r);
        r[i] = '*';
    }
    else if (strcmp2(s, "CAT") == 0 || strcmp2(s, "CAC") == 0){
        i = size(r);
        r[i] = 'H';
    }
    else if (strcmp2(s, "CAA") == 0 || strcmp2(s, "CAG") == 0){
        i = size(r);
        r[i] = 'Q';
    }
    else if (strcmp2(s, "AAT") == 0 || strcmp2(s, "AAC") == 0){
        i = size(r);
        r[i] = 'N';
    }
    else if (strcmp2(s, "AAA") == 0 || strcmp2(s, "AAG") == 0){
        i = size(r);
        r[i] = 'K';
    }
    else if (strcmp2(s, "GAT") == 0 || strcmp2(s, "GAC") == 0){
        i = size(r);
        r[i] = 'D';
    }
    else if (strcmp2(s, "GAA") == 0 || strcmp2(s, "GAG") == 0){
        i = size(r);
        r[i] = 'E';
    }
    else if (strcmp2(s, "TGT") == 0 || strcmp2(s, "TGC") == 0){
        i = size(r);
        r[i] = 'C';
    }
    else if (strcmp2(s, "TGG") == 0){
        i = size(r);
        r[i] = 'W';
    }
    else if (strcmp2(s, "CGT") == 0 || strcmp2(s, "CGC") == 0 || strcmp2(s, "CGA") == 0 
    || strcmp2(s, "CGG") == 0 ){
        i = size(r);
        r[i] = 'R';
    }
    else if (strcmp2(s, "AGT") == 0 || strcmp2(s, "AGC") == 0){
        i = size(r);
        r[i] = 'S';
    }
    else if (strcmp2(s, "AGA") == 0 || strcmp2(s, "AGG") == 0){
        i = size(r);
        r[i] = 'R';
    }
    else if (strcmp2(s, "GGT") == 0 || strcmp2(s, "GGC") == 0 || strcmp2(s, "GGA") == 0 
    || strcmp2(s, "GGG") == 0 ){
        i = size(r);
        r[i] = 'G';
    }
}
void converte_nucleo(char n[], char a[]){
    int i, comprimento = 0;
    caps(n);
    comprimento = size(n);
    for (i=0; i<comprimento; i += 3){
        char vet[4];
        vet[0] = n[i];
        vet[1] = n[i+1];
        vet[2] = n[i+2];
        add(a, vet);
    }
}

int freq_motivo(char p[], char m[]){
    char tra[1000];
    converte_nucleo(p, tra);
    int i, j, a = 0, compp, compm, b = 0;
    compp = size(p);
    compm = size(m);
	for (i=0; i<compp; i++){
        for (j = 0; j<compm; j++){
            if (m[j] == p[i+j]){
			    a++;
            }
        }
        if (a == compm){
            b++;
            a = 0;
        }
	}
	return b;
}

void conteudo_gc(char n[], int j){
    int comp = size(n), i, k;
    for (i=0; i<=(comp-j); i++){
        char trtr[j+2];
        for (k = 0; k<j; k++){
            trtr[k] = n[i+k];
        }
        float c = (float) analise_caractere('C', trtr);
        float g = (float) analise_caractere('G', trtr);
        float res = (c+g)/j;
        printf("%.2f ", res);
	}
}