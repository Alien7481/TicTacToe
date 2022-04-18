#include <iostream>
using std::cout;

bool is_full(const char board[3][3]);

int main() 
{
	char c[3][3] = {
		'O', 'X', 'O',
		'x', 'x', 'X',
		'x', 'X', 'x',
	};

	cout << is_full(c);
}