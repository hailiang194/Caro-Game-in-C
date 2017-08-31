#ifndef PROCESS_IN_GAME_H_
	#define PROCESS_IN_GAME_H_

#include <stdio.h>
#include <ctype.h>
#include <conio.h>

#include "info-game.h"
#include "logic-in-game.h"
#include "process-char.h"

void setup(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

void game_scence(const int board[HEIGHT][WIDTH]);
void control(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

void update(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY);

void setup(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	for(int i = 0; i < WIDTH; i++)
		for(int j = 0; j < HEIGHT; j++)
			board[i][j] = NONE_MARK;

	*isX = TRUE;

	//that mean nothing
	*lastX = -1;
	*lastY = -1;
}

void game_scence(const int board[HEIGHT][WIDTH])
{
	system("cls");
	//print head row
	printf("  ");

	for(int i = 0; i < WIDTH; i++)
		printf("%c ", present_char(i));

	printf("\n");

	//print inside
	for(int y = 0; y < HEIGHT; y++)
	{
		printf("%c ", present_char(y));
		for(int x = 0; x < WIDTH; x++)
			if(board[x][y] == NONE_MARK)
				printf("- ");
			else if(board[x][y] == X_MARK)
				printf("X ");
			else if(board[x][y] == O_MARK)
				printf("O ");

		printf("\n");
	}
}

void control(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	//Input X and Y
	printf("(XY)> ");
	char presentX, presentY;
	fflush(stdin);
	scanf("%c", &presentX);
	scanf("%c", &presentY);

	int x = get_present_number(presentX);
	int y = get_present_number(presentY);

	if(!is_true_mark_place(board, x, y))
		return;
	//else
	if(*isX)
		board[x][y] = X_MARK;
	else if(!*isX)
		board[x][y] = O_MARK;

	*lastX = x;
	*lastY = y;

	*isX = !(*isX);

}

void update(int board[HEIGHT][WIDTH], int *isX, int *lastX, int *lastY)
{
	while(!is_game_over(board, *lastX, *lastY))
	{
		game_scence(board);
		control(board, isX, lastX, lastY);
	}

	game_scence(board);
}

#endif