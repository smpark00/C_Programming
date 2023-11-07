#include <stdio.h>
#include <stdlib.h>
#define N 8
void init_board(char[][N]);
void generate_nqueens(char[][N]);
void print_board(char[][N]);
int num_encounter(char[][N]);
int main()
{
	char chess_board[N][N] = { 0 };
	init_board(chess_board);
	generate_nqueens(chess_board);
	print_board(chess_board);
	printf("The number of cases is %d\n", num_encounter(chess_board));
	return 0;
}

void init_board(char board[][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			board[i][j] = '.';
		}
	}
}

void generate_nqueens(char board[][N]) {
	srand(time(NULL));
	int i = 0, idx_row, idx_col;
	for (i = 0; i < N; i++) {
		while (1) {
			idx_row = rand() % N;
			idx_col = rand() % N;
			if (board[idx_row][idx_col] != 'Q') {
				board[idx_row][idx_col] = 'Q';
				break;
			}
		}
	}
}

void print_board(char board[][N]) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
int num_encounter(char board[][N]) {
	int x[N] = { 0 };
	int y[N] = { 0 };
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'Q') {
				x[count] = i;
				y[count] = j;
				count++;
				
			}
		}
	}
	int x_count[N] = { 0 }; // x의값 012345 가 몇개인지
	int y_count[N] = { 0 }; // y의값 012345 가 몇개인지
	int xcount = 0; // 겹치는 x의 값이 몇개인지
	int ycount = 0; // 겹치는 y의 값이 몇개인지
	for (int i = 0; i < N; i++) {
		x_count[x[i]]++;
		y_count[y[i]]++;
		if (x_count[x[i]] == 2) {
			xcount++;
		}
		if (y_count[y[i]] == 2) {
			ycount++;
		}
	}

	int add_count[2*N] = { 0 };





	/*
	printf("--------------------------\n");
	for (int i = 0; i < N; i++) {
		printf("%d\n", x_count[i]);
	}


	printf("--------------------------\n");
	for (int i = 0; i < N; i++) {
		printf("%d\n", y_count[i]);
	}


	printf("--------------------------\n");

	printf("%d %d\n", xcount, ycount);
	*/

	return 0;
}
