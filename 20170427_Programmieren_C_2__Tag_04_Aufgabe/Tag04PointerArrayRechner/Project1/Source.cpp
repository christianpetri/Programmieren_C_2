#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*Tag04 - Pointer und Array – Aufgaben
1. Schreiben Sie das "Hat-Size" Programm "array_06.c" neu(siehe Stoff von Tag02).
Verwenden Sie Pointer und Pointer Indirektionen anstatt Arraynamen.
2. Schreiben Sie ein Rechnerprogramm mit den folgenden Eigenschaften :
-es unterstützt positive und negative ganze Zahlen und Gleitkommazahlen
- erlaubt Eingaben von mehrfachen Operationen wie z.B. 1.5 + 4.1 - 7 / 7
- mit dem ^ Operator werden Exponentialrechnungen ausgeführt z.B. 2 ^ 3 gibt 8
- ein vorhergehendes Resultat kann mit = am Anfang des Input Strings in die
Rechnung einfliessen, z.B.wenn ein früheres Resultat 3 war gibt = *2 + 7 gleich 15
- die Eingabe "2 + 2*4 – 4*-2.22" wird als((2 + 2) * 4 - 4) *(-2.22) gerechnet.
Verwenden Sie Pointer - Notationen wo möglich.
Konzeptvorschlag:
1. Zuerst wird ein Input String eingelesen, welcher vom Benutzer eingegeben wurde.
2. Das Programm wird beendet, wenn der Benutzer 'ende' eingab.
3. Alle Spaces werden zuerst im Input String entfernt.
4. das erste Zeichen wird auf '=' geprüft und falls es zutrifft, wird das frühere Resultat
in die Rechnung einbezogen.
*/
/*
Array object
Pointer speichert eine Memory Adresse
*/

void main() {

	double lastResult = 0;
	int runCalculator = 1; 
	
	while (runCalculator) {
		char input[100] = { NULL };
		char result[100] = { NULL };
		double number[100] = { NULL };
		char operant[100] = { NULL };
		double calResult = 0;
		int digitCounter = 0;
		int operantCounter = 0; 
		//double temp = 0;

		fgets(input, sizeof(input), stdin);
		//printf("input=%s", input);

		if( strcmp("ende\n", input) == 0) {
			 runCalculator = 0; 
			 puts("Have a nice day!");
			 continue;
		}
		int j = 0;
		for (int i = 0; i < sizeof(input); i++) {
			if (input[i] != ' ') {
				result[j] = input[i];
				j++;
			}
		} 
		//double strtod(const char *str, char **endptr)       
		char *str = result;
		char *p = str;
		while (*p) { // While there are more characters to process...
			if (result[0] == '=' && digitCounter == 0) {
				number[0] = lastResult;
				//printf("%lf", number[0]);
				digitCounter++;
				p++;
				continue;
			}  
			//temp = strtod(p, &p);
			if (isdigit(*p)) { // Upon finding a digit, ... // || *p == '-'
				number[digitCounter] = strtod(p, &p); // Read a number, ...
				//printf("%lf", number[digitCounter]); // and print it.
				digitCounter++;
			}
		 	else { // Otherwise, move on to the next character.				
				if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%' || *p == '^') {
					operant[operantCounter] = *p;
					//printf(" %c ", *p); // and print it.
					operantCounter++;
				}
				p++;
			}
		}
		//printf("\n%d + %d", digitCounter, operantCounter);
		/*
		if (operantCounter != digitCounter-1 && (result[0] != '=' || operantCounter != digitCounter)) { 
				puts("\nUps something went wrong!! Please try again\n");
				continue; 
		}
		*/
		for (int i = 0; i < operantCounter; i++) {
			printf("(");
		}
		for (int i = 0; number[i]; i++) {
			//printf("\n%d + %d", digitCounter, operantCounter);
			if (i < 1) {
				printf(" %lf %c ", number[i], operant[i]);
			}
			else {
				printf("%lf ) %c ", number[i], operant[i]);
			} 
		}		 
		calResult = number[0];
		for (int i = 1; i < 100; i++) {
			switch (operant[i - 1]) {
				case '+':	calResult += number[i]; break;
				case '-':	calResult -= number[i]; break;
				case '*':	calResult *= number[i]; break;
				case '/':	calResult /= number[i]; break;
				case '^':	calResult= pow(calResult,number[i]); break;
				case '%':	calResult= long (calResult) % long(number[i]); break; 
			}
		}
		lastResult = calResult;
		printf("= %lf", calResult);
		puts("\n\nPlease enter your calculation:\n");
	}
	getchar(); //prevents the window from closing, hit enter to close it
}