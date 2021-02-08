#include "Board.h"
#include <iostream>
#include <cctype>
/*
enum class Turn { White, Black };
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
public:
	Board();
	~Board() {};
	void reset_board();
	bool get_cords_to_move();
	void move_piece();
	void check_for_check_mate(Turn actual);
};
*/
bool Board::promote_pawn(Turn actual) {
	if (table_of_chessboard[_next_move.y][_next_move.x]->_colour == Colour::White && _next_move.y == 7) {
		return 1;
	}
	else if ((table_of_chessboard[_next_move.y][_next_move.x]->_colour == Colour::Black && _next_move.y == 0)) {
		return 1;
	}
	return 0;
}
void Board::init_new_table() {
	table_of_chessboard[0][0] = new Rook(Colour::White, 0, 0);
	table_of_chessboard[0][1] = new Knight(Colour::White, 0, 1);
	table_of_chessboard[0][2] = new Bishop(Colour::White, 0, 2);
	table_of_chessboard[0][3] = new Queen(Colour::White, 0, 3);
	table_of_chessboard[0][4] = new King(Colour::White, 0, 4);
	table_of_chessboard[0][5] = new Bishop(Colour::White, 0, 5);
	table_of_chessboard[0][6] = new Knight(Colour::White, 0,6);
	table_of_chessboard[0][7] = new Rook(Colour::White, 0, 7);
	table_of_chessboard[1][0] = new Pawn(Colour::White, 1, 0);
	table_of_chessboard[1][1] = new Pawn(Colour::White, 1, 1);
	table_of_chessboard[1][2] = new Pawn(Colour::White, 1, 2);
	table_of_chessboard[1][3] = new Pawn(Colour::White, 1, 3);
	table_of_chessboard[1][4] = new Pawn(Colour::White, 1, 4);
	table_of_chessboard[1][5] = new Pawn(Colour::White, 1, 5);
	table_of_chessboard[1][6] = new Pawn(Colour::White, 1, 6);
	table_of_chessboard[1][7] = new Pawn(Colour::White, 1, 7);
	for (int y = 2; y < 7; y++) {
		for (int x = 0; x < 8; x++) {
			table_of_chessboard[y][x] = new Piece(Colour::None, y, x);
		}
	}
	table_of_chessboard[7][0] = new Rook(Colour::Black, 7, 0);
	table_of_chessboard[7][1] = new Knight(Colour::Black, 7, 1);
	table_of_chessboard[7][2] = new Bishop(Colour::Black, 7, 2);
	table_of_chessboard[7][3] = new Queen(Colour::Black, 7, 3);
	table_of_chessboard[7][4] = new King(Colour::Black, 7, 4);
	table_of_chessboard[7][5] = new Bishop(Colour::Black, 7, 5);
	table_of_chessboard[7][6] = new Knight(Colour::Black, 7, 6);
	table_of_chessboard[7][7] = new Rook(Colour::Black, 7, 7);
	table_of_chessboard[6][0] = new Pawn(Colour::Black, 6, 0);
	table_of_chessboard[6][1] = new Pawn(Colour::Black, 6, 1);
	table_of_chessboard[6][2] = new Pawn(Colour::Black, 6, 2);
	table_of_chessboard[6][3] = new Pawn(Colour::Black, 6, 3);
	table_of_chessboard[6][4] = new Pawn(Colour::Black, 6, 4);
	table_of_chessboard[6][5] = new Pawn(Colour::Black, 6, 5);
	table_of_chessboard[6][6] = new Pawn(Colour::Black, 6, 6);
	table_of_chessboard[6][7] = new Pawn(Colour::Black, 6, 7);
}
bool Board::valid_cords_actual(char y, char x) {
	if (y < 8 && y >= 0 && x < 8 && x >= 0) {
		if (_actual_turn == Turn::White) {
			if (table_of_chessboard[y][x]->_colour == Colour::White)return true;
		}
		else if (_actual_turn == Turn::Black) {
			if (table_of_chessboard[y][x]->_colour == Colour::Black) return true;
		}
	}
	return false;
}
bool Board::valid_cords_next_move(char y, char x) {
	if (y < 8 && y >= 0 && x < 8 && x >= 0) {
		if (_actual_turn == Turn::White) {
			if (table_of_chessboard[y][x]->_colour == Colour::Black || table_of_chessboard[y][x]->_colour == Colour::None) return true;
		}
		else if (_actual_turn == Turn::Black) {
			if (table_of_chessboard[y][x]->_colour == Colour::White || table_of_chessboard[y][x]->_colour == Colour::None) return true;
		}

	}
	return false;
}
Board::Board() {
	init_new_table();
	_actual_turn == Turn::White;
	is_White_King_in_check_mate = false;
	is_Black_King_in_check_mate = false;
}
void Board::reset_board() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			delete table_of_chessboard[y][x];
		}
	}
	init_new_table();
	_actual_turn == Turn::White;
	is_White_King_in_check_mate = false;
	is_Black_King_in_check_mate = false;
}
void Board::get_cords_to_move() {
	std::cout << "Write cords Piece that you want to move  " << std::endl;
	std::string cords;
	bool tmp = true;
	while (tmp==true) {
		std::cout << "Write cords Piece that you want to move  " << std::endl;
		std::cin >> cords;
		if (cords.size() >= 2) {
			cords[1] = cords[1] - 17;
			if (valid_cords_actual(cords[0], cords[1])) {
				tmp = false;
				_actual.y = cords[0];
				_actual.x = cords[1];
			}
		}
		else {
			std::cout << "Invalid cords, type again" << std::endl;
		}
		cords.clear();
	}
	tmp = true;
	while (tmp == true) {
		std::cout << "Write where you want to move your figure"  << std::endl;
		std::cin >> cords;
		if (cords.size() >= 2) {
			cords[1] = cords[1] - 17;
			if (valid_cords_next_move(cords[0], cords[1])) {
				tmp = false;
				_actual.y = cords[0];
				_actual.x = cords[1];
			}
		}
		else {
			std::cout << "Invalid cords, type again" << std::endl;
		}
		cords.clear();
	}
}
bool Board::move_piece() {
	bool valid = false;
	for (auto& b : table_of_chessboard[_actual.y][_actual.x]->_array_of_moves_with_value) {
		if (std::get<0>(b) == _next_move.y && std::get<1>(b) == _next_move.x) {
			valid = true;
		}
	}
	if (valid == true) {
		std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y][_next_move.x]);
		delete table_of_chessboard[_actual.y][_actual.x];
		table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
		if (_actual_turn == Turn::White) {
			_actual_turn == Turn::Black;
		}
		else _actual_turn == Turn::White;
		check_for_check_mate();
		return true;
	}
	return false;
}
void Board::check_for_check_mate() {
	for (auto& y : table_of_chessboard) {
		for (auto& x : y) {
			if (x->_colour == Colour::White) {
				for (auto& b : x->_array_of_moves_with_value) {
					if (std::get<2>(b) > 9500) {
						is_Black_King_in_check_mate = true;
					}

				}

			}
			else if (x->_colour == Colour::Black) {
				for (auto& b : x->_array_of_moves_with_value) {
					if (std::get<2>(b) < -9500) {
						is_White_King_in_check_mate = true;
					}

				}

			}
		}
	}

}




