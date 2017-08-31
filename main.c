#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "info-game.h"
#include "process-in-game.h"
#include "check-overline.h"
#include "process-char.h"

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

int main()
{
	int board[HEIGHT][WIDTH] = {0};
	int *isX = (int *)malloc(sizeof(int));

	int *lastX = (int *)malloc(sizeof(int));
	int *lastY = (int *)malloc(sizeof(int));

		setup(board, isX, lastX, lastY);

		show_game_scene(board, isX, lastX, lastY);
		getch();
	return 0;
}

void show_game_scene(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	update(board, isX, lastX, lastY);

	*isX = !(*isX);

	if(have_winner(board,*lastX,*lastY))
	{
		if(*isX)
			printf("X WIN\n");
		else
			printf("O WIN\n");
	}
	else
		printf("END IN A DRAW\n");
}