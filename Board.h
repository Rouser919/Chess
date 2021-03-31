#pragma once
#include "Piece.h"
#include <memory>
enum class Turn {White,Black};
enum class WhoPlay{Player,Computer};
class Board
{
private:
	 typedef std::vector<std::tuple<char, char, char, char,char,char,char> > typ_logs;
	 WhoPlay _actual_player;
	 bool valid_promote_for_computer = false;
	 std::array<std::unique_ptr<Piece>, 8> table_of_chessboard[8];
	 Turn _actual_turn;
	 cords _actual, _next_move;
	 typ_logs _logs;
	 typ_logs tmp;
	 std::vector<typ_logs> _logs_from_games;
	 const int _depth_search = 1;
	 void change_next_move(char y, char x) { _next_move.y = y, _next_move.x = x; }
	 void change_actual_move(char y, char x) { _actual.y = y, _actual.x = x; }
	 bool can_promote_pawn();
	 void promote_pawn();
	 void init_new_table();
	 bool valid_cords_actual(char y, char x);
	 bool valid_cords_next_move(char y, char x);
	 bool validate_move();
	 void check_for_check_mate();
	 bool check_for_win_or_draw();
	 void update_all_moves();
	 void castling();
	 static void print_to_center();
	 void print_board();
	 void reset_board();
	 void get_cords_to_move();
	 bool move_piece();
	 void undo_move();
	 void menu_for_chess();
	 void player_vs_player();
	 void player_vs_AI(int type);
	 void write_logs_from_games(char actual_y, char actual_x, char next_y, char next_x,char symbol,char color,char beating='x');
	 bool read_logs_from_games();
	 void begin_of_breadth_search();
	 double breadth_search(char depth);
public:
	Board();
	~Board()=default;
}; 

