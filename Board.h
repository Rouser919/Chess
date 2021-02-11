#pragma once
#include "Piece.h"
enum class Turn {White,Black};
class Board
{
private:
	 typedef std::vector<std::tuple<char, char, char, char,char,char,char> > typ_logs;
	 typedef std::tuple<char, char, char, char>  move;
	 move moves_from_search;
	 Piece *table_of_chessboard[8][8];
	 Turn _actual_turn;
	 cords _actual, _next_move;
	 typ_logs _logs;
	 std::vector<typ_logs> _logs_from_games;
	 const int _depth_search = 3;
	 bool can_promote_pawn();
	 void promote_pawn();
	 void init_new_table();
	 bool valid_cords_actual(char y, char x);
	 bool valid_cords_next_move(char y, char x);
	 void check_for_check_mate();
	 bool check_for_win_or_draw();
	 void update_all_moves();
	 void castling();
	 void print_to_center();
	 void print_board();
	 void reset_board();
	 void get_cords_to_move();
	 bool move_piece();
	 void undo_move();
	 void menu_for_chess();
	 void player_vs_player();
	 void player_vs_AI();
	 void write_logs_from_games(char actual_y, char actual_x, char next_y, char next_x,char symbol,char color,char beating='x'); // beating for search if it was beating in flight by Pawn 
	 bool read_logs_from_games();
	 int breadth_search(char depth);
	 int quiescenceSearch(char depth, int alpha, int beta);
	 int value_of_table();
public:
	Board();
	~Board();
}; 

