#ifndef PROCESS_IN_GAME_H_
	#define PROCESS_IN_GAME_H_

#include "info-game.h"

void setup(int board[WIDTH][HEIGHT], int *isX);
char present_char(int num);
void game_scence(const int board[WIDTH][HEIGHT]);


void setup(int board[WIDTH][HEIGHT], int *isX)
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


void game_scence(const int board[WIDTH][HEIGHT])
{
	//print head row
	printf("  ");

	for(int i = 0; i < WIDTH; i++)
		printf("%c ", present_char(i));

	printf("\n");

	//print inside
	for(int i = 0; i < HEIGHT; i++)
	{
		printf("%c ", present_char(i));
		for(int j = 0; j < WIDTH; j++)
			if(board[i][j] == NONE_MARK)
				printf("- ");
			else if(board[i][j] == X_MARK)
				printf("X ");
			else if(board[i][j] == O_MARK)
				printf("O ");

		printf("\n");
	}
}

#endif