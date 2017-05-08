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
int main() {
	/*
	char single = 0;
	scanf_s("%c", &single, sizeof(single));

	char multiple[10];
	scanf_s("%s", multiple, sizeof(multiple));
	*/

	//Bsp. 05 veranschaulicht, wenn man einem Pointer einen Wert hinzu addiert
	/*
	char multiple[] = "a string";
	//fgets(multiple, sizeof(multiple), stdin);
	char *p = multiple;
	for (int i = 0; i < strnlen(multiple,sizeof(multiple)); i++) {
		printf("multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n", 
			i, multiple[i], i, *(p + 1), i, &multiple[i], i, p + i);
	}
	getchar(); //prevents programm from closing
	*/

	char board[3][3] = {
		{ '1', '2', '3'},
		{ '4','5','6' },
		{ '7','8','9' }
	};
	printf("address of board	:%p\n", board);
	printf("address of &board[0][0]	:%p\n", &board[0][0]);
	printf("address of board[0]	:%p\n", board[0]);

	for (int i = 0; i < sizeof(board); i++) {
		printf("board: %c\n", *(*board + i));
	}
	getchar();

	return 0;
}