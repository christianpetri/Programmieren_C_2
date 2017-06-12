#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define BUFFLEN 20
#define RECHNUNGLEN 200

int main() 
{
  bool ende=false;                          // Flag zum Beenden des Programmes
  char input_data[BUFFLEN];                 // Buffer zum Einlesen der Input Daten
  char rechnung[RECHNUNGLEN] = {0};         // Buffer zum Speichern der Rechnung
  bool rechnung_gelesen = false;            // Flag das das Einlesen der Rechnung beendet
  size_t index;                             // Index fuer den aktuellen Charakter in 'rechnung'
  size_t to;                                // Index zum kopieren der 'rechnung' auf sich selbst
  size_t rechnung_laenge;                   // Speichert die Laenge der 'rechnung'
  double result;                            // Speichert das Resultat
  char *endptr;                             // Speichert die Adresse auf den naechsten Charakter nach einem Wert
  char op;                                  // Speichert den Operator
  double operand;                           // Speichert den Operand


  while (!ende)
	 {
		// Die Rechnung einlesen
		printf("Gib die Rechnung ein (max. 200 Zeichen) oder \"ende\" fuer beenden\n");
		*rechnung = '\0';
		do
		  {
			 fgets(input_data, BUFFLEN, stdin);
			 if ('\n' == *(input_data + strlen(input_data)-1))
				{
				  // eine Rechnung wurde erkannt ('\n' am Ende von input_data) -> entferne '\n'
				  *(input_data + strlen(input_data)-1) = '\0';
				  strcat(rechnung, input_data);
				  rechnung_gelesen = true;
				}
			 else 
				{
				  // die eingelesene Rechnung ist noch nicht vollständig
				  strcat(rechnung, input_data);
				}
		  }
		while (!rechnung_gelesen);

		if (strcmp("ende", rechnung) == 0)
		  {
			 return 0;
		  }

		printf("Rechnung: %s\n", rechnung);
		// Leerzeichen entfernen
		rechnung_laenge = strlen(rechnung);
		for(index = 0, to = 0; index <= rechnung_laenge; index++)
		  {
			 if ( *(rechnung + index) != ' ' ) 
				{
				  *(rechnung + to++) = *(rechnung + index);
				}
		  } 
		rechnung_laenge = strlen(rechnung);
		//printf("Rechung ohne Leerzeichen: %s\n", rechnung);

		// Erstes Zeichen auf '=' pruefen
		index = 0;
		if (*(rechnung + index) == '=')
		  {
			 index++;
		  }
		else 
		  {
			 result = strtod(rechnung + index, &endptr);
			 index = endptr - rechnung;
		  }
		while (index < rechnung_laenge)
		  {
			 // Operator lesen
			 op = *(rechnung + index++);

			 // Operand lesen

			 operand = strtod(rechnung + index, &endptr);
			 index = endptr - rechnung;
			 switch (op)
				{
				case '+':
				  result += operand;
				  break;
				case '-':
				  result -= operand;
				  break;
				case '*':
				  result *= operand;
				  break;
				case '/':
				  result /= operand;
				  break;
				case '^':
				  result = pow(result,operand);
				  break;
				default:
				  printf("Diese Operation ist ungueltig!\n");
				  break;
				}
		  }

		printf("\nDas Resultat ist: %f\n", result);
	 }
  

		return 0;
}
