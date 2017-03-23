#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include <ctype.h>

int main(){
	/*
	char input[] = "A ;bilrd; ;came do55;55wn the walk";
	printf("Parsing the input string '%s'\n", input);
	char delimiter[] = ";5l";
	char *token = strtok(input, delimiter);

	while (token) {
		puts(token);
		token = strtok(NULL, delimiter);
	}

	printf("Contents of the input string now: '");
	for (size_t n = 0; n < sizeof input; ++n)
		input[n] ? printf("%c", input[n]) : printf("\\0");
	puts("'");
	*/
	/*• Schreiben Sie ein Programm, das ein Text von der Tastatur
	einliest und die Häufigkeit aller Wörter ausgibt.
		• Die Gross - und Kleinschreibung soll nicht beachtet werden.
		• Der eingegeben Text kann innerhalb einer maximalen Länge,
		beliebig gross sein.
		*/
	char input[100];
	char result[100][100] = {0};
	fgets(input, sizeof(input),stdin);
	//puts(input);
	for (int i = 0; i < sizeof(input); i++) { 
		input[i] = tolower(input[i]);
	} 
	char delimiter[] = " ";
	char *token = strtok(input, delimiter);
	int i = 0;
	int found = 0; 
	//char currentWord[100] = { NULL };
	//currentWord = token;
	while (token) {  
		if (i > 0) {
			for (int p = 0; p < i; p++) {
				if(strcmp(result[p], token) == 0) {
					found = 1;
					puts("found");
					break;
				}
			}
		} 
			if (!found) {
				strcpy(result[i], token);
			}
			found = 0;
		//puts(token);
		token = strtok(NULL, delimiter);
		i++;
	} 
	 
	for (int i = 0; i < 100; i++) { //sizeof(result) / sizeof(result[0])
			printf("%s " , result[i]); 
	}
	int counter;
	getchar();
	return 0;
}