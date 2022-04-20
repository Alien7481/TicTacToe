#include <iostream>
#include "tictactoe.h"
using std::cout;

int main() 
{
	init();

	while (!is_gameover()) {
		 make_next_move();
	}
	print();
}