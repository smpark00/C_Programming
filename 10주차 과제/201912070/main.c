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
	srand(time(NULL));
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
	int x_count[N] = { 0 }; // x의값 012345 가 몇개인지 경우의 수 1) 가로로 겹치는 것
	int y_count[N] = { 0 }; // y의값 012345 가 몇개인지 경우의 수 2) 세로로 겹치는 것
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

	int rightdown = 0, rightup = 0; //대각선 오른쪽 위로, 오른쪽 아래로 새는 함수
	int minusarray[N] = { 0 }; // 경우의 수 3) 대각선 오른쪽 아래로, 이 경우, x-y 값이 같은 것을 찾으면 됨
	int plusarray[N] = { 0 };  // 경우의 수 4) 대각선 오른쪽 위로, 이 경우 x+y값이 같은 것을 찾으면 됨
	for (int i = 0; i < N; i++) {
		minusarray[i] = x[i] - y[i];
		plusarray[i] = x[i] + y[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (minusarray[i] == minusarray[j]) {
				rightdown++;
				minusarray[j] = rand() % 9999; // 중복값 제거를 위해 카운트 후, 랜덤 값으로 값을 날려버림
				break;	// 중복값 제거를 위한 break;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (plusarray[i] == plusarray[j]) {
				rightup++;
				plusarray[j] = rand() % 9952; // 중복값 제거를 위해 카운트 후, 랜덤 값으로 값을 날려버림
				break; // 중복값 제거를 위한 break;
			}	
		}
	}
	return xcount+ycount+rightdown+rightup;
}
