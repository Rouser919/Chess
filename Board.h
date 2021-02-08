#pragma once
#include "Piece.h"
enum class Turn {White,Black};
class Board
{
private:
	 Piece *table_of_chessboard[8][8];
	 Turn _actual_turn;
	 cords _actual, _next_move;
	 bool is_White_King_in_check_mate;
	 bool is_Black_King_in_check_mate;
	 bool promote_pawn(Turn actual);
	 void init_new_table();
	 bool valid_cords_actual(char y, char x);
	 bool valid_cords_next_move(char y, char x);
	 void check_for_check_mate();
public:
	Board();
	~Board() {};
	void reset_board();
	void get_cords_to_move();
	bool move_piece();
}; 
