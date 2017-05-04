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
	char* satz[100];
	size_t length = 0;
	for (int i = 0; i < 2; i++) {  
		fgets(buffer, sizeof(buffer), stdin);
		length = strnlen_s(buffer,buffer_size)+1;
		satz[i] = (char*)malloc(length);
		if (!satz[i]) {
			break;
		} 
		strcpy_s(satz[i], length , buffer);
		//printf("%s", satz[i]); 
		//printf("\n%d\n", i);
	}
	 
	//bubblesort(*satz, 2);
	//calloc 
	for (int i = 0; i < 2-1; i++) { 
		if (*satz[i] > *satz[i + 1]) {
			char *temp = satz[i];
			satz[i] = satz[i + 1];
			satz[i + 1] = temp;
		}
		
	}
	 
	for (int i = 0; i < 2; i++) {
		printf("%d\n", strlen(satz[i])-1);
		printf("%s\n\n", satz[i]);
		free(satz[i]);
		satz[i] = NULL;
	}
	 
	getchar();
	return 0;
}

