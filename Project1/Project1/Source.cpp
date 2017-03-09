#include <stdio.h>
#include <stdbool.h>
#include<conio.h> 
#include <math.h>

int main(void)

{ 
	puts("Tick Tack Toe");
	int playerNumber = 1;
	char playingfield[9];
	int playerInput; 
	bool gameOver = 1;
	int gameCounter = 0;
	while (true) {
		if (gameOver) {
			//reset varibales
			gameOver = 0;
			playerNumber = 1;
			gameCounter = 0;
			printf("\n");
			for (int i = 0; i < 9; i++) {
				playingfield[i] = i + 1 + 48; //ASCII 0 = 48
				printf(" %4c", playingfield[i]);
				if (i == 2 || i == 5) {
					printf("\n");
				}
			}
			printf("\n");
		}
		else {

			printf("Player %u: Please enter a number between 1-9", playerNumber);
			playerInput = -1;
			scanf_s("%d", &playerInput);
			while (playerInput < 0 && playerInput > 9) {
				puts("The Number must be between 1 and 9");
				scanf_s("%d", &playerInput);
			}
			
			playerInput = abs(playerInput)-1;
			printf("\n");
			for (int i = 0; i < 9; i++) { 
				printf(" %4c", playingfield[i]);
				if (i == 2 || i == 5) {
					printf("\n");
				}
			}
			printf("\n");
			getchar();
		}
		playerNumber++;
		if (playerNumber > 2) {
			playerNumber = 1;
		}
	} 
	//scanf_s(" %d", &input);
	
	getchar(); 
	return 0;
}
