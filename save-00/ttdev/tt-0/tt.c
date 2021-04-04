#define _GNU_SOURCE

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define WORD_MAX 256
#define WORDLIST_FILE "wordlist.txt"

void cls() {
	printf("\033[2J\033[0;0H");
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

void getAnagrams(char ***a,int *an,char ***d,int *dn,char *rw) {
	int i;
	for(i=0;i<*dn;i++) {
		if(isAnagram(rw,(*d)[i])) {
			addWord(a,an,(*d)[i]);
		}
	}
}

void shuffle(char *w) {
	int i,j,k;
	for(i=strlen(w)-1;i>0;i--) {
		j=rnd(i+1);
		k=w[i];
		w[i]=w[j];
		w[j]=k;
	}
}

void loadWord(char *fn,char ***d,int *dn,int min,int max) {
	FILE *fin=fopen(fn,"r");
	char w[WORD_MAX];
	char *p;
	while(fgets(w,WORD_MAX,fin)) {
		p=strchr(w,'\n'); if(p) *p=0;
		if(strlen(w)>=min && strlen(w)<=max) addWord(d,dn,w);
	}
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

	char *rw;

	char *sw;

	char gw[WORD_MAX];

	randomize();

	cls();

	fin=fopen("w3.txt","r");

	loadWord(WORDLIST_FILE,&d,&dn,4,7);

	loadWord(WORDLIST_FILE,&r,&rn,6,7);

	qsort(d,dn,sizeof(*d),cmp);

	qsort(r,rn,sizeof(*r),cmp);

	rw=d[dn%rnd(dn)];

	getAnagrams(&a,&an,&d,&dn,rw);

/*
	for(i=0;i<an;i++) {
		if(i!=0) printf(", ");
		printf("%s",a[i]);
	}
	printf("\n");
*/

	sw=strdup(rw);

	shuffle(sw);

	printf("\n%s\n\n",sw);

	printf("> ");
	fgets(gw,WORD_MAX,stdin);

	return 0;
}
