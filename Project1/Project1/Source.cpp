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
			printf("\nPlayer %u: Please enter a number between 1-9 ", playerNumber + 1);
			playerInput = 10;
			scanf_s(" %u", &playerInput); 
			if (playerInput < 0 && playerInput>9) {
				puts("The Number must be between 1 and 9");
			}
			/*
			while (playerInput == 10) {
				
				scanf_s(" %u", &playerInput);	
				printf(" hello %d", playerInput);
			} 
			*/
			playerInput = abs(playerInput)-1;
			if (!(playingfield[playerInput] == 'o') && !(playingfield[playerInput] == 'x')) {
				if (playerNumber) {
					playingfield[playerInput] = 'o';
				}
				else {
					playingfield[playerInput] = 'x';
				}
			}
			for (int i = 0; i < 2; i++) {
				if (
					(playingfield[i] == 'o' && playingfield[i + 3] == 'o' && playingfield[i + 6] == 'o')
					||
					(playingfield[i] == 'x' && playingfield[i + 3] == 'x' && playingfield[i + 6] == 'x')
					||
					(playingfield[i*3] == 'x' && playingfield[i*3 + 1] == 'x' && playingfield[i * 3 + 2] == 'x')
					||
					(playingfield[i * 3] == 'o' && playingfield[i * 3 +1] == 'o' && playingfield[i * 3+2] == 'o')
					||
					(playingfield[0] == 'x' && playingfield[4] == 'x' && playingfield[8] == 'x')
					||
					(playingfield[0] == 'o' && playingfield[4] == 'o' && playingfield[8] == 'o')
					||
					(playingfield[2] == 'x' && playingfield[4] == 'x' && playingfield[6] == 'x')
					||
					(playingfield[2] == 'o' && playingfield[4] == 'o' && playingfield[6] == 'o')
					
					) {
					gameOver = 1;
					printf("\nPlayer %u won!", playerNumber + 1);
				}
			}
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
		if (playerNumber > 1) {
			playerNumber = 0;
		}
		gameCounter++;
		if (gameCounter > 8) {
			gameOver = 1;
		}
	} 
	//scanf_s(" %d", &input);
	
	getchar(); 
	return 0;
}
