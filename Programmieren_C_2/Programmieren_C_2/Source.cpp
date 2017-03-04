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
	/* 
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
	*/
	/*
		Definieren Sie ein Array 'data' mit 100 Elementen vom Typ double.Schreiben
		Sie eine Schleife, die die folgende Sequenz von Werten im Arrays speichert :
		1 / (2 * 3 * 4), 1 / (4 * 5 * 6), 1 / (6 * 7 * 8) ... bis zu 1 / (200 * 201 * 202)
		Schreiben Sie eine weitere Schleife, die das folgende errechnet : data[0] -
		data[1] + data[2] - data[3] + ... - data[99].Multiplizieren Sie das Ergebnis
		mit 4.0, fügen 3.0 und Geben Sie das Ergebnis auf der Konsole aus.
		Erkennen Sie die Wert, den Sie bekommen ?
	*/
	double data[100];
	double resultData = 0;
	for (int i = 2; i <= 100; i+=2) {
		data[i] = 1 / (double)((i)*(i + 1)*( i+ 2)); 
	}
	for (int i = 0; i < 100; i+=2) {
		resultData += data[i];
	}

	for (int i = 1; i < 100; i+=2) {
		resultData -= data[i];	 
	}
	resultData *= 4;
	resultData += 3;
	printf("Resultat data[] = %lf");

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