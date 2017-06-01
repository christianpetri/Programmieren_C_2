#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_BUF 5         // maximale Buffergroesse fuer den Satz. Wenn der Satz,
                          // dann muss mit realloc zusaetzlicher Speicher angefordert werden.

#define INC_BUF 5         // Bestimmt die Groesse fuer den zusaetzlichen Speicher.

#define MAX_TEXT 50       // Bestimmt die groesse fuer die Laenge des Satzes. Muss genuegend 
                          // gross gewaehlt werden, da kein dynamisches Memory fur diesen Buffer
                          // implementiert ist.

int main()
{
  char text[MAX_TEXT];                              // Buffer fuer den Satz mit fgets einlesen

  char **sentence=malloc(MAX_BUF*sizeof(char*));    // Speichert die Saetze. Es koennen beliebig viele Saetze gespeichert werden.

  size_t max_sentence=MAX_BUF;                      // Bestimmt die Anzahl Saetze die abgespeichert werden koennen. Wenn diese
                                                    // erreicht wird, dann muss wieder zusaetzlichen Speicher angefordert werden.

  size_t counter_sentence=0;                        // Bestimmt die Anzahl der gepeicherten Saetze

  bool sorted;                                      // Flag fuer den Bubble-Sort. Wenn z.B. Beispiel das Array bereits sortiert
                                                    // vorliegt, dann wird der Vergleich nach bereits nach einem Run beendet.

  while (true)
	 {
		printf("Gib einen Satz ein oder enter fuer ende:\n");
		fgets(text, MAX_TEXT, stdin);
		if (text[0] == '\n') break;

		// entferne das New Line Zeichen
		text[strlen(text)-1] = '\0';

		// pruefe ob das sentence zusaetzliches Memory benoetigt
		if(counter_sentence == max_sentence)
		  {
			 printf("more memory needed...\n");
			 max_sentence += INC_BUF;
			 sentence = realloc(sentence, max_sentence*sizeof(char*));
			 if (sentence == NULL)
				{
				  return 2;           // 2 means memory error
				}
		  }
		*(sentence + counter_sentence) = calloc(strlen(text), sizeof(char));
		strcpy(*(sentence + counter_sentence++), text);
	 }

  printf("Es werden %d Saetze sortiert...\n", counter_sentence);

  // Bubble-Sort
  sorted = false;
  int k=counter_sentence;
  char *tmpChr;
  while (!sorted) 
	 {
		sorted=true;
		for(int i=0; i<k-1; i++)
		  {
			 printf("\ncompare sentences %s with %s", sentence[i], sentence[i+1]);
			 if(strcmp(sentence[i], sentence[i+1]) > 0)
				{
              printf(" --> Swap sentences %s <-> %s", sentence[i], sentence[i+1]);
				  tmpChr = sentence[i];         // Swap
				  sentence[i] = sentence[i+1];  // Swap
				  sentence[i+1] = tmpChr;       // Swap
				  sorted = false;               // Das Array ist noch nicht sortiert. 
                                            // Es braucht min. einen zusaetzlichen Run.
				}
		  }
	 }


  // Ausgabe der sortierten Saetze
  printf("\n\nSortierte Reihenfolge:\n");
  for(int i=0; i<counter_sentence; i++)
	 {
		printf("\n%s", *(sentence + i));
	 }
  printf("\n");


  // free all the memory
  for(int i=0; i<counter_sentence; i++)
	 {
		free(*(sentence + i));   // gibt den Speicher fuer den Satz frei
		*(sentence +i) = NULL;   // Reset den Pointer auf NULL
	 }
  free(sentence);              // gibt den Speicher fuer das Satz-Array frei
  sentence = NULL;             // Reset das Satz-Array auf NULL

  return 0;
}
