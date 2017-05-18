#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
//Schreibe ein Programm, das mehrere eingegebene Sätze
//alphabetisch sortiert.
 
int main() {
	const size_t buffer_size= 100; //Buffer size
	char buffer[buffer_size] = {}; //declare and intit buffer
	char* satz[100] = {NULL}; // declare and init the satz pointer array
	size_t length = 0; // for each iteration store the the string length of the buffer + 1
	int maxLength = 0;
	puts("How many sentencens do you want? (max 100 sentencens and max chracters per sentence is 100"); 
	unsigned int numberOfArrays = 0; //delcare and intit numberOfArrays
	scanf_s(" %i", &numberOfArrays); //ask the user how many sentences the user wants to process and store it
	getchar();
	for (int i = 0; i < numberOfArrays; i++) { //get user input and store it
		fgets(buffer, sizeof(buffer), stdin);
		length = strnlen_s(buffer,buffer_size)+1;
		if (length > maxLength)
			maxLength = length;
		satz[i] = (char*)malloc(length);
		if (!satz[i]) {
			break;
		} 
		strcpy_s(satz[i], length , buffer);
		//printf("%s", satz[i]); 
		//printf("\n%d\n", i);
	}
	//printf("%i", maxLength);
	//Bubble sort the satz pointer array
	for (int q = 0; q < maxLength; q++) {
		for (int j = 0; j < numberOfArrays - 1; j++) {
			for (int i = 0; i < numberOfArrays - j - 1; i++) {
				if (q == 0) { //sort the arrays
					if (satz[i][0] > satz[i + 1][0]) {
						char *temp = satz[i];
						satz[i] = satz[i + 1];
						satz[i + 1] = temp;
					}
				}
				for (int w = 0; w < q ; w++) { //sort the strings
					if (satz[i][w] == satz[i+1][w]) {
						if (satz[i][w+1] > satz[i + 1][w+1]) {
							char *temp = satz[i];
							satz[i] = satz[i + 1];
							satz[i + 1] = temp;
						} 
					}
					else {
						break;
					}
				} 
			}
			/*
			puts("------------"); //see the sorting action 
			for (int g = 0; g < numberOfArrays; g++) {
				printf("%s", satz[g]); 
			}
			*/
		}
	} 
	puts("------------"); 
	for (int i = 0; i < numberOfArrays; i++) { //print the result and free the memory
		printf("%s", satz[i]);
		free(satz[i]);
		satz[i] = NULL;
	} 
	getchar();
	return 0;
}

