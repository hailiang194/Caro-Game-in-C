#ifndef LOGIC_IN_GAME_H_
	#define LOGIC_IN_GAME_H_

#include "info-game.h"

int is_out_of_board(int x, int y);
int can_place(const int board[HEIGHT][WIDTH] ,int x, int y);
int is_true_mark_place(const int board[HEIGHT][WIDTH] ,int x, int y);

int is_out_of_board(int x, int y)
{
	return ((x < 0 || x > WIDTH) || (y < 0 || y > HEIGHT));
}

int can_place(const int board[HEIGHT][WIDTH],int x, int y)
{
	return (board[x][y] == NONE_MARK);
}

int is_true_mark_place(const int board[HEIGHT][WIDTH], int x, int y)
{
	return (!is_out_of_board(x, y) && can_place(board, x, y));
}

#endif