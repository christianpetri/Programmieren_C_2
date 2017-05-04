#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Schreibe ein Programm, das mehrere eingegebene Sätze
//alphabetisch sortiert.

int main() {
	const size_t buffer_size= 100;
	char buffer[buffer_size] = {};
	char* satz[100];
	size_t length;
	for (int i = 0; i < 2; i++) {  
		fgets(buffer, sizeof(buffer), stdin);
		length = strnlen_s(buffer,buffer_size)+1;
		satz[i] = (char*)malloc(length);
		if (!satz[i]) {
			break;
		}
		strcpy_s(satz[0], length , buffer);
		printf("%s", satz[i]); 
	}
	//calloc
	 
	free(satz);
	 
	getchar();
	return 0;
}