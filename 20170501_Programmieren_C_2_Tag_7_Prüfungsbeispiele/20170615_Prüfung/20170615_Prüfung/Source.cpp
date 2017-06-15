#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	char string[] = "Du bist ein ganz tolles Geniiiiie";
	char delimiter[] = {" " };
	char *ptr;
	char min[100];
	char max[100];
	char temp[100];
	int minNumber = 100, maxNumber = 0;
	 
	ptr = strtok(string," \0");

	while (ptr != NULL) {
		printf("\n %s %d", ptr,strlen(ptr));
		if (strlen(ptr) < minNumber) {
			strcpy(min, ptr);
			minNumber = strlen(ptr);
		}
		if (strlen(ptr) > maxNumber) {
			strcpy(max, ptr);
			maxNumber = strlen(ptr);
		} 
		ptr = strtok(NULL," ");
	}

	printf("\n %d %d %s %s",minNumber,maxNumber, min, max);
	getchar();
	return 0;
}