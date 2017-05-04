#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Schreibe ein Programm, das mehrere eingegebene Sätze
//alphabetisch sortiert.
 
char* bubblesort(char *array, size_t length) {
	for (int i = 0; i < length - 1; ++i) {
		for (int j = 0; j < length - i - 1; ++j) {
			if (array[j] > array[j + 1])
			{
				char tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				printf("\n%c", array[j]);
			}
		}
	}
	return array;
}
 
int main() {
	const size_t buffer_size= 100;
	char buffer[buffer_size] = {};
	char* satz[100] = {NULL};
	size_t length = 0;
	puts("How many sentencens do you whant?");
	unsigned int numberOfArrays = 0;
	int maxLength = 0;
	scanf_s(" %i", &numberOfArrays);
	getchar();
	for (int i = 0; i < numberOfArrays; i++) {
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
	printf("%i", maxLength);
	//bubblesort(*satz, 2);
	//calloc 
	for (int q = 0; q < maxLength; q++) {
		for (int j = 0; j < numberOfArrays - 1; j++) {
			for (int i = 0; i < numberOfArrays - j - 1; i++) { //- j
				for (int w = 0; w < q ; w++) {
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
				if (q == 0) {
					if (satz[i][0] > satz[i + 1][0]) {
						char *temp = satz[i];
						satz[i] = satz[i + 1];
						satz[i + 1] = temp;
					}
				}
				
			}
		}
	} 
	puts("------------"); 
	for (int i = 0; i < numberOfArrays; i++) {
		//printf("%d\n", strlen(satz[i])-1);
		//printf("%c\n", satz[i][0]);
		printf("%s", satz[i]);
		free(satz[i]);
		satz[i] = NULL;
	} 
	getchar();
	return 0;
}

