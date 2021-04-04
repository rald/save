#define _GNU_SOURCE

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
	(*d)[(*n)++]=strdup(w);
}

static bool isZero(int *f) {
	int i;
	for(i=0;i<26;i++) {
		if(f[i]!=0) return false;
	}
	return true;
}

static int *freq(char *w) {
	int i,j;
	char *l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int *f=malloc(sizeof(*f)*26);
	for(i=0;i<26;i++) f[i]=0;
	for(i=0;i<strlen(w);i++) {
		bool found=false;
		for(j=0;j<26;j++) {
			if(toupper(w[i])==l[j]) {
				found=true;
				break;
			}
		}
		if(found) {
			f[j]++;
		}
	}
	return f;
}

bool isAnagram(char *w1,char *w2) {
	int i;
	int *f1=freq(w1);
	int *f2=freq(w2);
	bool ans=true;
	if(isZero(f1)) return false;
	if(isZero(f2)) return false;
	for(i=0;i<26;i++) {
		if(f1[i]<f2[i]) {
			ans=false;
			break;
		}
	}
	free(f1);
	f1=NULL;
	free(f2);
	f2=NULL;
	return ans;
}

void split(int *n,char ***s,char *t,char *d) {
	char *token=strtok(t,d);
	while(token) {
		addWord(s,n,token);
		token=strtok(NULL,d);
	}
}

int cmp(const void *a,const void *b) {
	char *l=*(char**)a;
	char *r=*(char**)b;
	if(strlen(l)<strlen(r)) {
		return 1;
	} else if(strlen(l)>strlen(r)) {
		return -1;
	}
	return strcmp(l,r);
}

void randomize() {
	srand(time(NULL));
}

int rnd(int n) {
	return rand()/(RAND_MAX/(n+1));
}

int main() {

	char **d=NULL;
	int dn=0;

	char **r=NULL;
	int rn=0;

	char **a=NULL;
	int an=0;

	char w[WORD_MAX];

	int i;
	FILE *fin;

	char *p;

	randomize();

	cls();

	fin=fopen("w3.txt","r");

	while(fgets(w,WORD_MAX,fin)) {
		p=strchr(w,'\n'); if(p) *p=0;
		addWord(&d,&dn,w);
	}

	qsort(d,dn,sizeof(*d),cmp);

	for(i=0;i<dn;i++) printf("%s\n",d[i]);

	printf("\n\n%s\n",d[dn%rnd(dn)]);

	return 0;
}
