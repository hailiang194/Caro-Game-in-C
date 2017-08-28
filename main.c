#include <stdio.h>
#include <stdlib.h>

#include "info-game.h"
#include "process-in-game.h"


int main()
{
	int board[WIDTH][HEIGHT] = {0};
	int *isX = (int *)malloc(sizeof(int));

	setup(board, isX);

	game_scence(board);
	return 0;
}
