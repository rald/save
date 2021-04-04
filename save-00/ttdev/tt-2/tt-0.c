#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 256

void cls() {
	printf("\033[2J");
}

void gotoxy(int x,int y) {
	printf("\033[%d;%df",y,x);
}

void textcolor(int r,int g,int b) {
	printf("\033[38;2;%d;%d;%dm",r,g,b);
}

void background(int r,int g,int b) {
	printf("\033[48;2;%d;%d;%dm",r,g,b);
}

void hidecursor() {
	printf("\033[?25l");
}

void showcursor() {
	printf("\033[?25h");
}

void addWord(char ***d,int *n,char *w) {
	(*d)=realloc((*d),sizeof(**d)*((*n)+1));
	(*d)[(*n)++]=w;
}

int main() {

	char **d=NULL;
	int n=0;

	char w[WORD_MAX];

	int i;
	FILE *fin;

	cls();

	fin=fopen("w2.txt","r");

	while(fscanf(fin,"%s",w)==1) {
		addWord(&d,&n,w);
	}

	for(i=0;i<n;i++) printf("%s",d[i]);

	return 0;
}
