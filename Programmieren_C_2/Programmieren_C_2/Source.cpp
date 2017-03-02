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

void aufgabe() {
	/*Schreiben Sie ein Programm, das fünf Werte vom Typ double von der Tastatur
	einliest und Sie in einem Array speichert. Berechnen Sie den Kehrwert jedes
	Wertes ( der Kehrwert von x ist 1.0 / x) und speichern Sie diese in einem
	separaten Array. Geben Sie jeden Kehrwert und die Summe aller Kehrwerte
	auf der Konsole aus.*/
	 
	const int sizeOfArray = 5;
	double werte[sizeOfArray];
	double resultat[sizeOfArray];
	double sum=0;
	for (int i = 0; i < sizeof(werte) / sizeof(double); i++) {
		printf("Geben Sie Wert %i ein:", i);
		scanf_s("%lf", &werte[i]);
		resultat[i] = 1 / (double)werte[i];
	}
	for (int i = 0; i < sizeof(werte) / sizeof(double); i++) {
		printf("wert[%i] = %00lf der Kehrwert ist %00lf \n", i ,werte[i], resultat[i]);
		sum += resultat[i];
	}
	printf("Summer der Kehrwerte = %lf", sum); 
	getchar();
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
	//pointer();
	aufgabe();
	getchar();
}