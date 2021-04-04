#include <stdio.h>

int main() {
	char s[256];
	char *p;
	while(scanf("%s",s)==1) {
		p=strchr(s,','); if(p) *p=0;
		printf("%s\n",s);
	}
}
