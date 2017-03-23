#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(){
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
	getchar();
	return 0;
}