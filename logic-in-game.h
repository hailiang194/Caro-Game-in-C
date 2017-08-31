#ifndef LOGIC_IN_GAME_H_
	#define LOGIC_IN_GAME_H_

#include "info-game.h"
#include "check-overline.h"

int is_true_mark_place(const int board[HEIGHT][WIDTH] ,int x, int y);
int have_no_none_mark(const int board[HEIGHT][WIDTH]);
int is_game_over(const int board[HEIGHT][WIDTH], int lastX, int lastY);


int is_true_mark_place(const int board[HEIGHT][WIDTH], int x, int y)
{
	return (!is_out_of_board(x, y) && can_place(board, x, y));
}

int have_no_none_mark(const int board[HEIGHT][WIDTH])
{
	for(int i = 0; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			if(board[i][j] == NONE_MARK)
				return FALSE;

	//there is no none marks
	return TRUE;
}

int is_game_over(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	return (have_no_none_mark(board) || have_winner(board, lastX, lastY));
}

#endif