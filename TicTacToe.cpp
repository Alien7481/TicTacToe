#include <iostream>
#include <cctype>

using std::cout;
using std::cin;

char board[3][3];
enum { EMPTY = ' ', CROSS ='X', ZERO = 'O' };

char player_char;
char computer_char;

void init() {
	setlocale(LC_ALL, "ru_RU");
	do {
		cout << "—делайте свой выбор [X/0]: ";
		cin >> player_char;
		player_char = toupper(player_char); //UPPER CASE
	} while (player_char != 'X' && player_char != '0');
	
	computer_char = (player_char == 'X' ? '0' : 'X');

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = EMPTY;
}

bool is_full() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (board[i][i] == EMPTY)
				return 0;
	}
	return 1;
}

bool is_gameover() {
	for (int i = 0; i < 3; i++) {
		if (board[i][0]!=EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return true;
	}

	for (int i = 0; i < 3; i++) {
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[i][0] == board[2][i])
			return true;
	}

	if (board[0][0] != EMPTY && board[0][0] == board[1][1] == board[2][2])
		return true;

	if (board[0][2] != EMPTY && board[0][2] == board[1][1] == board[2][0])
		return true;

	return is_full();
}



void get_coords() {
	int row, col;
	do {
		cout << "¬ведите координаты x: [1;3], y: [1;3]: ";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col >2 || row < 0 || row >2 || board[row][col]!=EMPTY);
	board[row][col] = player_char;
}

void make_move() {
	
}

void print() {
	for (int i = 0; i < 3; i++) {
		cout << ' ' << board[i][0];
		for (int j = 1; j < 3; j++) {
			cout << " | " << board[i][j];
		}
		cout << "\n";

		if (i == 2)
			break;
		for (int j = 0; j < 3; j++) {
			cout << "---" << ((j==2)? '\n': '+');
		}

	}
	
}



