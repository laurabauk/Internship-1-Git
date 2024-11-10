#include<stdio.h>
#define playerOne 'X'
#define playerTwo 'O'

void resetBoard(char board[][3]);
void printBoard(char board[][3]);
int makeMove(char board[][3], char, int);
int checkWin(char board[][3]);
int checkFull(char board[][3]);

int main() {

	char board[3][3];
	char currentPlayer = playerOne;
	int position;


	resetBoard(board);
	printBoard(board);

	while (1) {

		printf("\nIgrac %c, za odabir polja unesi broj 1-9:\t", currentPlayer);
		scanf_s("%d", &position);

		if (position < 1 || position > 9) {
		printf("\nNevazece polje! Pokusaj ponovo.\n");
		continue;
		}

		if (makeMove(board, currentPlayer, position)) {
			// Provjera pobjede
			if (checkWin(board)) {
				printf("\nIgrac %c je pobjednik!\n", currentPlayer);
				break;
			}
			// Provjera nerjesenog rezultata
			if (checkFull(board) == 1 && checkWin(board) == 0) { // Ako je ploca puna i nema pobjednika, onda je rezultat nerjesen
				printf("\nRezultat je nerjesen!\n");
				break;
			}

			currentPlayer = (currentPlayer == playerOne) ? playerTwo : playerOne;
		}
		else {
			printf("\nPolje je vec zauzeto! Pokusaj ponovo.\n");
		}

	} // Petlja se prestane izvrsavati kada netko pobjedi ili kada je rezultat nerjesen

	return 0;
}

void resetBoard(char board[][3]) {
	char k = '1';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
				board[i][j] = k;
				k++;
		}
	}
}
void printBoard(char board[][3]) {
	printf("-------------\n");
	for (int i = 0; i < 3; i++) {
		printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
		printf("-------------\n");
	}
}
int makeMove(char board[][3], char currentPlayer, int position) {
	int i = (position-1) / 3; // redak
	int j = (position-1) % 3; // stupac

	if (board[i][j] != playerOne && board[i][j] != playerTwo) {
		board[i][j] = currentPlayer;
		printBoard(board);
		return 1;
	}
	return 0;
}
int checkWin(char board[][3]) {
	// Provjera okomito i vodoravno
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] || board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return 1;
		}
	}
	// Provjera dijagonala
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return 1;
	}
	return 0;
}
int checkFull(char board[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <3; j++) {
			if(board[i][j] != playerOne && board[i][j] != playerTwo){
				return 0; // Ako postoji polje na kojem nije X ni O, onda ploca nije puna
			}
		}
	}
	return 1; // Ploca je puna
}
