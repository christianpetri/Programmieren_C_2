#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	//double result;
	char input[100];
	char result[100];
	

	fgets(input, sizeof(input), stdin);
	int j = 0;
	for (int i = 0; i < sizeof(input); i++) {
		if (input[i] != ' ') {
			result[j] = input[i];
			j++;
		}
	}
	printf("input=%s", input);
	printf("input=%s", result);
	getchar();
	 
}