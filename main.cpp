#include <iostream>
#include "tictactoe.h"
using std::cout;

int main() 
{
	init();

	while (!is_gameover()) {
		print();
		get_coords();
		print();
	}
}