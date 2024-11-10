#include<stdio.h>

void printDiamond(int);
void printEvenDiamond(int);

int main() {

	int n;

	while (1) {

		printf("Unesi prirodni broj:\t");
		scanf_s("%d", &n);
		if (n < 1) {
			printf("\nUneseni broj nije prirodan! Pokusaj ponovno.\n");
		}
		else {
			break;
		}
	}

	if (n % 2 == 0) {
		printEvenDiamond(n);
	}
	else {
		printDiamond(n);
	}

	return 0;
}

void printDiamond(int n) {
	
	//Gornja polovica

	for (int i = 0; i < n / 2; i++) { // Redci
		for (int j = n / 2; j > i; j--) { // Razmaci
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) { // Zvjezdice
			printf("*");
		}
		printf("\n");
	}

	//Donja polovica

	for (int i = n / 2; i >= 0; i--) { // Redci
		for (int j = n / 2; j > i; j--) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			printf("*");
		}
		printf("\n");
	}

}

void printEvenDiamond(int n) {

	for (int i = 0; i < n / 2; i++) {
		for (int j = n / 2 - i - 1; j > 0; j--) {
			printf(" ");
		}
		for (int k = 0; k < i +1 ; k++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = n / 2 - 1; i >= 0; i--) {
		for (int j = n / 2 - i - 1; j > 0; j--) {
			printf(" ");
		}
		for (int k = 0; k < i + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}