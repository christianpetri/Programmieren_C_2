#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	//int number;
	int summe = 0;
	char zahl[100] = {0};

	puts("Please enter a number");
	fgets(zahl, 100, stdin);
	 
	for (int i = 0; i < sizeof(zahl)-1; i++) {
		if(zahl[i] != '\n' && zahl[i] != '\0')
		summe += zahl[i]-'0';
	}
	/*
	scanf_s(" %d",&number);
	while (number > 0) {
		summe += number % 10;
		number /= 10;
	} 
	*/
	printf("%d", summe); 
	getchar();
	return 0;
}  