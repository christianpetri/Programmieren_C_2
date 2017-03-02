#include <stdio.h>



void rechnen() {
	float number1, number2, result;
	char opt; 
	scanf_s(" %f", &number1);
	scanf_s(" %c", &opt);
	scanf_s(" %f", &number2);
	switch (opt) {
	case '+':	printf(" = %f", number1 + number2); break;
	case '-':	printf(" = %f", number1 - number2); break;
	case '*':	printf(" = %f", number1 * number2); break;
	case '/':	printf(" = %f", number1 / (float)number2); break;
	case '%':	printf(" = %d", (long)number1 % (long)number2); break;
	}
}

void pointer() {
	int number = 99;
	int *pnumber = &number;

	printf("%u", pnumber);
	printf(" %u %i \n", sizeof(int), sizeof(int));

	int value = 99;
	int *pnumber2 = &value; 
	printf("%p %i", pnumber2, pnumber2); 
	int primes[] = {1,2,3};
	printf("\\n %i", sizeof(primes));
}	

void main() {
	/* Unterrichts Themen
	Pointer
	Array Multi
	Malloc
	functions
	struct
	files flie *file;
	*/
	//rechnen(); //Übung 1
	 
	/*
	memory
	void main(){
	int number = 99;
	int *pnumber;
	pnumber = &number;
	}
	Heap
	Stack (
	1005	number 99
	8892	pnumber 1005
	)
	Global
	Code

	*/
	pointer();
	getchar();
}