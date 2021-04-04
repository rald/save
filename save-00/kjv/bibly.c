#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {

	textcolor(0x00,0xFF,0x00);
	background(0x00,0x00,0x00);
	cls();
	gotoxy(1,1);



	return 0;
}
