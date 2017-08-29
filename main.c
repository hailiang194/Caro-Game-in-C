#include <stdio.h>
#include <stdlib.h>

#include "info-game.h"
#include "process-in-game.h"
#include "check-overline.h"

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

int main()
{
	int board[HEIGHT][WIDTH] = {0};
	int *isX = (int *)malloc(sizeof(int));

	int *lastX = (int *)malloc(sizeof(int));
	int *lastY = (int *)malloc(sizeof(int));

	setup(board, isX, lastX, lastY);

	//show_game_scene(board, isX, lastX, lastY);

	board[5][5] = X_MARK;
	board[5][6] = X_MARK;
	board[5][7] = X_MARK;
	board[5][8] = X_MARK;
	board[5][9] = X_MARK;
	board[5][10] = X_MARK;
	
	get_num_by_horizontal_bottom(board, 5, 5);
	return 0;
}

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	while(!is_game_over(board, *lastX, *lastY))
		update(board, isX, lastX, lastY);
}