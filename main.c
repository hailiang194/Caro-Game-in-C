#include <stdio.h>
#include <stdlib.h>

#include "info-game.h"
#include "process-in-game.h"

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

int main()
{
	int board[HEIGHT][WIDTH] = {0};
	int *isX = (int *)malloc(sizeof(int));

	int *lastX = (int *)malloc(sizeof(int));
	int *lastY = (int *)malloc(sizeof(int));

	setup(board, isX, lastX, lastY);

	show_game_scene(board, isX, lastX, lastY);
	return 0;
}

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	while(!is_game_over(board, *lastX, *lastY))
		update(board, isX, lastX, lastY);
}