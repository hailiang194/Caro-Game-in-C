#ifndef CHECK_OVERLINE_H_
	#define CHECK_OVERLINE_H_

#include "info-game.h"
#include "logic-in-game.h"

int is_out_of_board(int x, int y);
int can_place(const int board[HEIGHT][WIDTH] ,int x, int y);

//HORIZONTAL
int get_num_by_horizontal_top(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int get_num_by_horizontal_bottom(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int is_win_by_horizontal(const int board[HEIGHT][WIDTH], int lastX, int lastY);

//VERTICAL
int get_num_by_vertical_left(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int get_num_by_vertical_right(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int is_win_by_vertical(const int board[HEIGHT][WIDTH], int lastX, int lastY);

//DIAGONAL
int get_num_by_diagonal_from_left_top(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int get_num_by_diagonal_from_left_bottom(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int is_win_by_diagonal_from_left(const int board[HEIGHT][WIDTH], int lastX, int lastY);

int get_num_by_diagonal_from_right_top(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int get_num_by_diagonal_from_right_bottom(const int board[HEIGHT][WIDTH], int lastX, int lastY);
int is_win_by_diagonal_from_right(const int board[HEIGHT][WIDTH], int lastX, int lastY);

int is_win_by_diagonal(const int board[HEIGHT][WIDTH], int lastX, int lastY);

//RESULT
int have_winner(const int board[HEIGHT][WIDTH], int lastX, int lastY);

int is_out_of_board(int x, int y)
{
	return ((x < 0 || x > WIDTH) || (y < 0 || y > HEIGHT));
}

int can_place(const int board[HEIGHT][WIDTH],int x, int y)
{
	return (board[x][y] == NONE_MARK);
}


int get_num_by_horizontal_top(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	int result = 0;
	for(int i = 1; i < 5; i++)
	{
		if(is_out_of_board(lastX, lastY - i))
			break;

		if(board[lastX][lastY - i + 1] != board[lastX][lastY - i])
			break;

		result++;
	}

	return result;
}

int get_num_by_horizontal_bottom(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	int result = 0;

	for(int i = 1; i < 5; i++)
	{
		if(is_out_of_board(lastX, lastY))
			break;
		
		if(board[lastX][lastY + i] != board[lastX][lastY + i - 1])
			break;

		result++;
	}

	return result;
}

int is_win_by_horizontal(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	return (get_num_by_horizontal_top(board, lastX, lastY) + get_num_by_horizontal_bottom(board, lastX, lastY) >= 4);
}


int get_num_by_vertical_left(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	int result = 0;

	for(int i = 1; i < 5; i++)
	{
		//printf("(%d, %d)\n", lastX - i, lastY);
		if(is_out_of_board(lastX - i, lastY))
			break;
		if(board[lastX - i + 1][lastY] != board[lastX - i][lastY])
			break;

		result++;
	}

	return result;
}

int get_num_by_vertical_right(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	int result = 0;

	for(int i = 1; i < 5; i++)
	{
		if(is_out_of_board(lastX + i, lastY))
			break;
		if(board[lastX + i - 1][lastY] != board[lastX + i][lastY])
			break;

		result++;
	}

	return result;
}

int is_win_by_vertical(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	return (get_num_by_vertical_left(board, lastX, lastY) + get_num_by_vertical_right(board, lastX, lastY) >= 4);
}

int have_winner(const int board[HEIGHT][WIDTH], int lastX, int lastY)
{
	return (is_win_by_horizontal(board, lastX, lastY) || is_win_by_vertical(board, lastX, lastY));
}
#endif