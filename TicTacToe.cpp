#include <iostream>
#include <cctype>

using std::cout;
using std::cin;

char bord[3][3];
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
}

void get_coords(int& row, int& col) {
	
	do {
		cout << "¬ведите координаты x: [1;3], y: [1;3]: ";
		cin >> col >> row;
		col--;
		row--;
	} while (col < 0 || col >2 || row < 0 || row >2 || bord[row][col]!=EMPTY);

}

void make_move() {
	
}

void print(const char board[3][3]) {
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


// тест
bool is_full(const char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (board[i][i] == EMPTY)
				return 0;
	}
	return 1;
}