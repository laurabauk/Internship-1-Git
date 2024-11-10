#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include<stdio.h>
#include<string.h>

int main() {

	int m, n = 0;
	char input[MAX];
	char* text[MAX];
	int wordCount = 0;

	while (1) {
		printf("Unesite max broj znakova po liniji:\t");
		scanf_s("%d", &m);
		printf("Unesite duzinu linija:\t");
		scanf_s("%d", &n);

		if (m > n) {
			printf("\nDuzina linije ne smije biti kraca od max broja znakova! Pokusajte ponovno.\n");
		}
		else {
			break;
		}
	}

	getchar();

	printf("Unesite proizvoljan tekst:\t");
	fgets(input, sizeof(input), stdin);

	// Spremanje svih rijeci u niz "text"

	char* token = strtok(input, " ");

	while (token != NULL) {
		text[wordCount] = _strdup(token);
		wordCount++;
		token = strtok(NULL, " ");
	}

	char currentLine[MAX] = ""; // Sadrzaj trenutne linije
	int lineLength = 0; // Duljina trenutne linije

	for (int i = 0; i < wordCount; i++) {

		if (lineLength + strlen(text[i]) + (lineLength > 0 ? 1: 0) <= m) {
			
			if (lineLength > 0) {
				strcat(currentLine, " ");
				lineLength++;
			}
			strcat(currentLine, text[i]);
			lineLength += strlen(text[i]);
		}

		else {
			int spaces = (n - lineLength) / 2;
			for (int i = 0; i < spaces; i++) {
				printf(" ");
			}
			printf("%s\n", currentLine);

			currentLine[0] = '\0'; // Prijelaz na novu liniju

			strcpy(currentLine, text[i]);
			lineLength = strlen(text[i]);
		}
	}

	// Ispis posljednje linije koja je pohranjena u currentLine ali mozda nije ispisana

	if (lineLength > 0) {
		int spaces = (n - lineLength) / 2;
		for (int i = 0; i < spaces; i++) {
			printf(" ");
		}
		printf("%s\n", currentLine);
	}
	
	return 0;
}