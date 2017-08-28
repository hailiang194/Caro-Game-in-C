#ifndef LOGIC_IN_GAME_H_
	#define LOGIC_IN_GAME_H_

#include "info-game.h"

int is_out_of_board(int x, int y);
int can_place(int x, int y);
int is_true_mark_place(int x, int y);

int is_out_of_board(int x, int y)
{
	return ((x < 0 || x > WIDTH) || (y < 0 || y > HEIGHT));
}

#endif