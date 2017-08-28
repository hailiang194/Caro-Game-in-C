#ifndef PROCESS_IN_GAME_H_
	#define PROCESS_IN_GAME_H_

#include <stdio.h>

#include "info-game.h"
#include "logic-in-game.h"

void setup(int board[HEIGHT][WIDTH], int *isX);
char present_char(int num);
void game_scence(const int board[HEIGHT][WIDTH]);

void control(int board[HEIGHT][WIDTH], int *isX);

void setup(int board[HEIGHT][WIDTH], int *isX)
{
	for(int i = 0; i < WIDTH; i++)
		for(int j = 0; j < HEIGHT; j++)
			board[i][j] = NONE_MARK;

	*isX = TRUE;
}

char present_char(int num)
{
	if(num < 10)
		return num + '0';

	return PRESENT_ALPHABET[(num % 10) % NUM_PRESENT];
}


void game_scence(const int board[HEIGHT][WIDTH])
{
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

#endif