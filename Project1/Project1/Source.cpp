#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h> 

int getNumberFromPlayer() {
	char *p, s[100];
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
bool isGameOver(char playfield[], int playerNumber) {
	for (int i = 0; i < 3; i++) {
		if (
			//horizontal
			(playfield[i] == 'o' && playfield[i + 3] == 'o' && playfield[i + 6] == 'o')
			||
			(playfield[i] == 'x' && playfield[i + 3] == 'x' && playfield[i + 6] == 'x')
			||
			//vertical
			(playfield[i * 3] == 'x' && playfield[i * 3 + 1] == 'x' && playfield[i * 3 + 2] == 'x')
			||
			(playfield[i * 3] == 'o' && playfield[i * 3 + 1] == 'o' && playfield[i * 3 + 2] == 'o')
			||
			//cross
			(playfield[0] == 'x' && playfield[4] == 'x' && playfield[8] == 'x')
			||
			(playfield[0] == 'o' && playfield[4] == 'o' && playfield[8] == 'o')
			||
			(playfield[2] == 'x' && playfield[4] == 'x' && playfield[6] == 'x')
			||
			(playfield[2] == 'o' && playfield[4] == 'o' && playfield[6] == 'o')

			) {
			
			printf("\nPlayer %u won!", playerNumber + 1);
			return 1;
			break;
		} 
	}
	return 0;
}
void drawPlayfield(char playfield[]){
	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf(" %3c", playfield[i]);
		if (i == 2 || i == 5) {
			printf("\n");
		}
	}
	printf("\n");
}
int checkIfFieldIsOccupied(char playfield[], int playerInput, int playerNumber) {
	if (!(playfield[playerInput] == 'o') && !(playfield[playerInput] == 'x')) {
		if (playerNumber) {
			playfield[playerInput] = 'o';
		}
		else {
			playfield[playerInput] = 'x';
		}
		return 0;
	}
	else {
		puts("Please enter an other number, this field is already occupied");
		return 1;
	}

}

void main(){ 
	puts("Tick Tack Toe");
	int playerNumber = 1;
	char playfield[9];
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
				playfield[i] = i + 1 + 48; //ASCII 0 = 48
				printf(" %3c", playfield[i]);
				if (i == 2 || i == 5) {
					printf("\n");
				}
			}
			printf("\n");
		}
		else { 
			printf("\nPlayer %u: Please enter a number between 1-9 ", playerNumber);
			do{
				playerInput = getNumberFromPlayer()-1;  //-1 array[0-8]				 
			} while (checkIfFieldIsOccupied(playfield, playerInput, playerNumber)); 
			gameOver = isGameOver(playfield, playerNumber);  
			drawPlayfield(playfield);  

			playerNumber++;
			if (playerNumber > 1)
			playerNumber = 0; 

			gameCounter++;
			if (gameCounter > 9) 
			gameOver = 1;
			
		}
	}   
}

