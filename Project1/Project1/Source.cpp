#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<conio.h> 
#include <math.h>

int getNumberFromPlayer() {
	char *p, s[100] = { 0 };
	int n;
	while (fgets(s, sizeof(s), stdin)) {
		n = strtol(s, &p, 10);
		if (p == s || *p != '\n') {
			printf("Please enter an integer between 1 to 9: ");
		}
		else if (n < 1 || n > 9) {
			printf("Please enter an integer between 1 to 9: ");
			continue;
		}
		else break;
	}
	return n;
}
bool isGameOver(char playingfield[], int playerNumber) {
	for (int i = 0; i < 3; i++) {
		if (
			//horizontal
			(playingfield[i] == 'o' && playingfield[i + 3] == 'o' && playingfield[i + 6] == 'o')
			||
			(playingfield[i] == 'x' && playingfield[i + 3] == 'x' && playingfield[i + 6] == 'x')
			||
			//vertical
			(playingfield[i * 3] == 'x' && playingfield[i * 3 + 1] == 'x' && playingfield[i * 3 + 2] == 'x')
			||
			(playingfield[i * 3] == 'o' && playingfield[i * 3 + 1] == 'o' && playingfield[i * 3 + 2] == 'o')
			||
			//cross
			(playingfield[0] == 'x' && playingfield[4] == 'x' && playingfield[8] == 'x')
			||
			(playingfield[0] == 'o' && playingfield[4] == 'o' && playingfield[8] == 'o')
			||
			(playingfield[2] == 'x' && playingfield[4] == 'x' && playingfield[6] == 'x')
			||
			(playingfield[2] == 'o' && playingfield[4] == 'o' && playingfield[6] == 'o')

			) {
			
			printf("\nPlayer %u won!", playerNumber + 1);
			return 1;
			break;
		} 
	}
	return 0;
}
void drawPlayfield(char playingfield[]){
	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf(" %4c", playingfield[i]);
		if (i == 2 || i == 5) {
			printf("\n");
		}
	}
	printf("\n");
}

int checkIfFieldIsOccupied(char playingfield[], int playerInput, int playerNumber) {
	if (!(playingfield[playerInput] == 'o') && !(playingfield[playerInput] == 'x')) {
		if (playerNumber) {
			playingfield[playerInput] = 'o';
		}
		else {
			playingfield[playerInput] = 'x';
		}
		return 0;
	}
	else {
		return 1;
	}

}


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
			while (checkIfFieldIsOccupied(playingfield, playerInput, playerNumber)) {
				playerInput = getNumberFromPlayer(); //9
				playerInput -= 1;
			} 
			gameOver = isGameOver(playingfield, playerNumber);  
			drawPlayfield(playingfield);
			
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
	getchar(); 
	return 0;
}

