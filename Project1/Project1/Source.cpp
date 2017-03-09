#include <stdio.h>
#include <stdbool.h>
#include<conio.h>

#define line 3
#define COL 3

int main(void)

{ 
	puts("Tick Tack Toe");
	int player[2][9] = {0}; 
	char playingfield[9];
	int input; 
	 
	printf("");
	for (int i = 0; i < 9; i++) {
		playingfield[i] = (char)i;
		printf(" %4i", playingfield[i]);
		if (i == 2 || i == 5) {
			printf("\n");
		}
	} 
	printf("\n");


	scanf_s(" %d", &input);
	printf("Player: yPlease enter a number between 1-9");
	getchar(); 
	return 0;
}
