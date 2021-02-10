#include "Board.h"
#include <iostream>
#include <cctype>
#include <string>
#include <Windows.h>
#include <fstream>
bool Board::can_promote_pawn() {
	if (table_of_chessboard[_next_move.y][_next_move.x]->_colour == Colour::White && table_of_chessboard[_next_move.y][_next_move.x]->getPieceType()==PieceType::Pawn && _next_move.y == 7) {
		return 1;
	}
	else if ((table_of_chessboard[_next_move.y][_next_move.x]->_colour == Colour::Black && table_of_chessboard[_next_move.y][_next_move.x]->getPieceType() == PieceType::Pawn &&_next_move.y == 0)) {
		return 1;
	}
	return 0;
}
void Board::promote_pawn() {
	std::cout << "Choose what do you want" << std::endl <<
		"1. Queen   2.Rook   3.Bishop   4.Knight" << std::endl;
	int type;
	std::cin >> type;
	while (type < 0 || type>4) {
		std::cout << "Wrong number! Type again" << std::endl;
		std::cin >> type;
	}
	switch (type) {
	case 1:
		if (_actual_turn == Turn::White) {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Queen(Colour::White, _next_move.y, _next_move.x);
		}
		else {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Queen(Colour::Black, _next_move.y, _next_move.x);

		}
		break;
	case 2:
		if (_actual_turn == Turn::White) {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Rook(Colour::White, _next_move.y, _next_move.x);
		}
		else {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Rook(Colour::Black, _next_move.y, _next_move.x);

		}
		break;
	case 3:
		if (_actual_turn == Turn::White) {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Bishop(Colour::White, _next_move.y, _next_move.x);
		}
		else {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Bishop(Colour::Black, _next_move.y, _next_move.x);

		}
		break;
	case 4:
		if (_actual_turn == Turn::White) {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Knight(Colour::White, _next_move.y, _next_move.x);
		}
		else {
			delete  table_of_chessboard[_next_move.y][_next_move.x];
			table_of_chessboard[_next_move.y][_next_move.x] = new Knight(Colour::Black, _next_move.y, _next_move.x);

		}
		break;
	default:
		break;

	}
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
	for (int y = 2; y < 6; y++) {
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
		if (table_of_chessboard[y][x]->_array_of_moves_with_value.size() < 1) {
			std::cout << "Not possible moves, type another Piece" << std::endl;
			return false;
		}
		if (_actual_turn == Turn::White) {
			if (table_of_chessboard[y][x]->_colour == Colour::White )return true;
		}
		else if (_actual_turn == Turn::Black) {
			if (table_of_chessboard[y][x]->_colour == Colour::Black ) return true;
		}
	}
	return false;
}
bool Board::valid_cords_next_move(char y, char x) {
	if (y < 8 && y >= 0 && x < 8 && x >= 0) {
		if (_actual_turn == Turn::White) {
			if (table_of_chessboard[y][x]->_colour == Colour::Black || table_of_chessboard[y][x]->_colour == Colour::None ) return true;
		}
		else if (_actual_turn == Turn::Black) {
			if (table_of_chessboard[y][x]->_colour == Colour::White || table_of_chessboard[y][x]->_colour == Colour::None ) return true;
		}

	}
	return false;
}
void Board::check_for_check_mate() {
	bool tmp_black=false, tmp_white=false;
	for (auto& y : table_of_chessboard) {
		for (auto& x : y) {
			if (x->_colour == Colour::Black) {
				for (auto& b : x->_array_of_moves_with_value) {
					if (std::get<2>(b) > 9500) {
						tmp_black = true;
					}

				}

			}
			else if (x->_colour == Colour::White) {
				for (auto& b : x->_array_of_moves_with_value) {
					if (std::get<2>(b) < -9500) {
						tmp_white = true;
					}

				}

			}
		}
	}
	if (tmp_black == true) { std::cout << "White King in CheckMate!" << std::endl; }

	if (tmp_white == true) { std::cout << "Black King in CheckMate!" << std::endl; }
}
bool Board::check_for_win_or_draw() {
	int count_of_figures = 0;
	bool white_king_alive = false;
	bool black_king_alive = false;
	for (auto& b : table_of_chessboard) {
		for (auto& x : b) {
			if (x->getPieceType() != PieceType::None) {
				count_of_figures++;
				if (x->getPieceType() == PieceType::King && x->_colour == Colour::White) {
					white_king_alive = true;
				}
				else if (x->getPieceType() == PieceType::King && x->_colour == Colour::Black) {
					black_king_alive=true;
				}
			}
		}
	}
	if (!white_king_alive) {
		std::cout << " Black Pieces Win !" << std::endl;
		return 1;
	}
	else if (!black_king_alive) {
		std::cout << " White Pieces Win !" << std::endl;
		return 1;
	}
	if (count_of_figures <= 2) {
		std::cout << " Draw" << std::endl;
		return 1;
	}
	return 0;

}
void Board::update_all_moves() {
	for (auto& b : table_of_chessboard) {
		for (auto& i : b) {
			if (i->getPieceType() != PieceType::None) {
				i->all_posible_moves_with_value(table_of_chessboard);
			}
		}
	}

}
void Board::castling() {
	bool valid = false;
	// White castling
	if ((table_of_chessboard[0][0]->get_move_count() == 0 || table_of_chessboard[0][7]->get_move_count() == 0) && table_of_chessboard[0][4]->get_move_count() == 0) {
		// left rook
		if (table_of_chessboard[0][0]->get_move_count() == 0 && table_of_chessboard[0][1]->getPieceType() == PieceType::None &&
			table_of_chessboard[0][2]->getPieceType() == PieceType::None && table_of_chessboard[0][3]->getPieceType() == PieceType::None) {
			valid = true;
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::Black) {
						for (auto& values : x->_array_of_moves_with_value) {
							char y = std::get<0>(values);
							char x = std::get<1>(values);
							if (y == 0 && (x == 1 || x == 2 || x == 3 || x == 4)) valid = false;
							if (valid == false) break;
						}
					}
				}
			}
			if (valid == true) {
				table_of_chessboard[0][4]->_array_of_moves_with_value.push_back(std::make_tuple(0, 2, 3));
			}

		}
		valid = false;
		//right rook
		if (table_of_chessboard[0][7]->get_move_count() == 0 && table_of_chessboard[0][6]->getPieceType() == PieceType::None &&
			table_of_chessboard[0][5]->getPieceType() == PieceType::None) {
			valid = true;
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::Black) {
						for (auto& values : x->_array_of_moves_with_value) {
							char y = std::get<0>(values);
							char x = std::get<1>(values);
							if (y == 0 && (x==4 || x==5 || x==6)) valid = false;
							if (valid == false) break;
						}
					}
				}
			}
			if (valid == true) {
				table_of_chessboard[0][4]->_array_of_moves_with_value.push_back(std::make_tuple(0, 6, 3));
			}

		}
		
	}
	if ((table_of_chessboard[7][0]->get_move_count() == 0 || table_of_chessboard[7][7]->get_move_count() == 0) && table_of_chessboard[7][4]->get_move_count() == 0) {
		// left rook
		if (table_of_chessboard[7][0]->get_move_count() == 0 && table_of_chessboard[7][1]->getPieceType() == PieceType::None &&
			table_of_chessboard[7][2]->getPieceType() == PieceType::None && table_of_chessboard[7][3]->getPieceType() == PieceType::None) {
			valid = true;
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::White) {
						for (auto& values : x->_array_of_moves_with_value) {
							char y = std::get<0>(values);
							char x = std::get<1>(values);
							if (y == 7 && (x == 1 || x == 2 || x == 3 || x == 4)) valid = false;
							if (valid == false) break;
						}
					}
				}
			}
			if (valid == true) {
				table_of_chessboard[7][4]->_array_of_moves_with_value.push_back(std::make_tuple(7, 1, -3));
			}

		}
		valid = false;
		//right rook
		if (table_of_chessboard[7][7]->get_move_count() == 0 && table_of_chessboard[7][6]->getPieceType() == PieceType::None &&
			table_of_chessboard[7][5]->getPieceType() == PieceType::None) {
			valid = true;
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::White) {
						for (auto& values : x->_array_of_moves_with_value) {
							char y = std::get<0>(values);
							char x = std::get<1>(values);
							if (y == 7 && (x == 4 || x == 5 || x == 6)) valid = false;
							if (valid == false) break;
						}
					}
				}
			}
			if (valid == true) {
				table_of_chessboard[7][4]->_array_of_moves_with_value.push_back(std::make_tuple(7, 6,- 3));
			}

		}

	}
}
void Board::print_to_center() { for (int i = 0; i < 40; i++) std::cout << " "; }
void Board::print_board() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	print_to_center();
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "--------------------------------" << std::endl;
	print_to_center();
	std::cout << "|";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "    A  B  C  D  E  F  G  H    ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "|" << std::endl;
	print_to_center();
	int x, y;
	for (y = 7; y >= 0; y--) {
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "|";
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << " " <<std::to_string(y+1) << " ";
		for (x = 0; x < 8; x++) {
			if ((x + y) % 2 == 0) {
				SetConsoleTextAttribute(hConsole, 160);
			}
			else {
				SetConsoleTextAttribute(hConsole, 96);
			}
			std::cout << ' ';

			if (table_of_chessboard[y][x]->_colour == Colour::Black) {
				if ((x + y) % 2 == 0) {
					SetConsoleTextAttribute(hConsole, 160);
				}
				else {
					SetConsoleTextAttribute(hConsole, 96);
				}
			}
			else {
				if ((x + y) % 2 == 0) {
					SetConsoleTextAttribute(hConsole, 167);
				}
				else {
					SetConsoleTextAttribute(hConsole, 103);
				}

			}
			std::cout << table_of_chessboard[y][x]->getSymbol();
			std::cout << ' ';

		}
		SetConsoleTextAttribute(hConsole, 11);
		std::cout << " " << std::to_string(y+1 ) << " ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "|" << std::endl;
		print_to_center();
	}
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "|";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "    A  B  C  D  E  F  G  H    ";
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "|" << std::endl;
	print_to_center();
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "--------------------------------" << std::endl;
}
void Board::reset_board() {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			delete table_of_chessboard[y][x];
		}
	}
	init_new_table();
	_actual_turn = Turn::White;
}
void Board::get_cords_to_move() {
	std::string cords;
	bool tmp = true;
	while (tmp == true) {
		std::cout << "Write cords Piece that you want to move  " << std::endl;
		std::cin >> cords;
		if (cords.size() >= 2) {
			
			cords[0] = std::toupper(cords[0]) - 17;
			if (valid_cords_actual(cords[1]-49, cords[0]-48)) {
				tmp = false;
				_actual.y = cords[1] - 49;
				_actual.x = cords[0] - 48;
			}
		}
		if(tmp==true)std::cout << "Invalid cords, type again" << std::endl;
		cords.clear();
	}
	tmp = true;
	while (tmp == true) {
		std::cout << "Write where you want to move your figure" << std::endl;
		std::cin >> cords;
		if (cords.size() >= 2) {
			cords[0] = std::toupper(cords[0]) - 17;
			if (valid_cords_next_move(cords[1] - 49, cords[0] - 48)) {
				tmp = false;
				_next_move.y = cords[1] - 49;
				_next_move.x = cords[0] - 48;
			}
		}
		if (tmp == true )std::cout << "Invalid cords, type again" << std::endl;
		cords.clear();
	}
}
bool Board::move_piece() {
	bool valid = false;

	for (auto& b : table_of_chessboard[_actual.y][_actual.x]->_array_of_moves_with_value) {
		if (std::get<0>(b) == _next_move.y && std::get<1>(b) == _next_move.x) {
			valid = true;
		}
		if (valid == true) break;
	}
	
	if (valid == true) {
		// beating in flight for Pawn
		if (table_of_chessboard[_actual.y][_actual.x]->getPieceType() == PieceType::Pawn &&
			table_of_chessboard[_next_move.y][_next_move.x]->getPieceType() == PieceType::None && _actual.x!=_next_move.x) {
			if (table_of_chessboard[_next_move.y - 1][_next_move.x]->getPieceType() == PieceType::Pawn &&
				table_of_chessboard[_actual.y][_actual.x]->_colour != table_of_chessboard[_next_move.y - 1][_next_move.x]->_colour) {
				write_logs_from_games(_actual.y,_actual.x,_next_move.y,_next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y-1][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
			}
			else if(table_of_chessboard[_next_move.y + 1][_next_move.x]->getPieceType() == PieceType::Pawn &&
				table_of_chessboard[_actual.y][_actual.x]->_colour != table_of_chessboard[_next_move.y + 1][_next_move.x]->_colour){
				write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y + 1][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y , _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
			}
		}
		// castling 
		else if (table_of_chessboard[_actual.y][_actual.x]->getPieceType() == PieceType::King && table_of_chessboard[_next_move.y][_next_move.x ]->getPieceType() == PieceType::None) {
			// long castle
			if (_next_move.x == 6) {
				// King swap
				write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
				// Rook swap
				write_logs_from_games(_actual.y, 7, _next_move.y, 5, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][7], table_of_chessboard[_next_move.y][5]);
				table_of_chessboard[_next_move.y][5]->update_cords_piece(_next_move.y, 5);
				delete table_of_chessboard[_actual.y][7];
				table_of_chessboard[_actual.y][7] = new Piece(Colour::None, _actual.y, 7);
			}
			// short castle
			else if (_next_move.x == 2) {
				// King swap
				write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
				// Rook swap
				write_logs_from_games(_actual.y, 0, _next_move.y, 3, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
				std::swap(table_of_chessboard[_actual.y][0], table_of_chessboard[_next_move.y][3]);
				table_of_chessboard[_next_move.y][3]->update_cords_piece(_next_move.y, 3);
				delete table_of_chessboard[_actual.y][0];
				table_of_chessboard[_actual.y][0] = new Piece(Colour::None, _actual.y, 0);

			}

		}

		// others 
		else  {
			write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol());
			std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y][_next_move.x]);
			table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
			delete table_of_chessboard[_actual.y][_actual.x];
			table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
		}
		if (can_promote_pawn()) promote_pawn();
		if (_actual_turn == Turn::White) {
			_actual_turn = Turn::Black;
		}
		else _actual_turn = Turn::White;
		return true;
	}
	else { std::cout << "Wrong move, type again" << std::endl; }
	return false;
}
void Board::menu_for_chess() {
	std::cout << "Welcome to Chess program by Mateusz Stopa" << std::endl <<"-------------------------------------------------------------------"<< std::endl;
	std::cout << "1.New game" << std::endl << "2.How to play" <<std::endl<< "3.Read logs from games"<< std::endl << "Type X to exit" << std::endl;
	char option;
	std::cin >> option;
	while (option != 'X') {
		switch (option) {
		case '1':
			std::cout << " Type option which you want" << std::endl << "1. Player vs Player" << std::endl << "2. Player vs AI" << std::endl;
			std::cin >> option;
			if (option == '1') {
				player_vs_player();

			}
			else if (option == '2') {
				player_vs_AI();
			}
			else { std::cout << "Wrong number, type again!"<<std::endl; }
			break;
		case '2' :
			std::cout << std::endl << "1. First write letter of a cords then number" << std::endl <<
				"2.Default white pieces start" << std::endl << "3. Names of figure with shortcut:" << std::endl <<
				"P-Pawn" << std::endl << "R-Rook" << std::endl << "C-Knight" << std::endl << "B-Bishop" << "Q-Queen" << std::endl << "K-King" << std::endl <<
				" Back to menu in 10 s" << std::endl;
			Sleep(10000);
			break;
		case'3':
			read_logs_from_games();
			break;
		default:
			std::cout << " Wrong number, type again!" << std::endl;
			break;

		}
		std::cout << "1.New game" << std::endl << "2.How to play" << std::endl << "3.Read logs from games" << std::endl << "Type X to exit" << std::endl;
		std::cin >> option;
	}


}
void Board::player_vs_player() {
	bool win_check = false;
	logs.clear();
	while (win_check == false) {
		print_board();
		if (_actual_turn == Turn::White) {
			std::cout << "White Turn";
		}
		else std::cout << "Black Turn";
		std::cout << std::endl;
		update_all_moves();
		castling();
		check_for_check_mate();
		get_cords_to_move();
		move_piece();
		if (check_for_win_or_draw()) win_check = true;
	}
	logs_from_games.push_back(logs);

}
void Board::player_vs_AI() {

}

void Board::write_logs_from_games(char actual_y, char actual_x, char next_y, char next_x,char symbol,char color) {
	logs.push_back(std::make_tuple(actual_y, actual_x, next_y, next_x,symbol,color));
}
bool Board::read_logs_from_games() {
	std::cout << logs_from_games.size() << " games are available to seen" << std::endl;
	if (logs_from_games.size() == 0) { std::cout << " Return to main menu" << std::endl; return 0; }
	std::cout << "Choose one" << std::endl;
	int i;
	std::cin >> i;
	while(i> logs_from_games.size() || i<1){
		std::cout << "Wrong number, type again!" << std::endl;
		std::cout << logs_from_games.size() << " games are available to seen" << std::endl;
		std::cout << "Choose one" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl << "------------------" << std::endl << "Game " << i << ":" << std::endl;
	for (auto& x : logs_from_games[i - 1]) {
		int counter_of_rows = 1;
		std::cout << counter_of_rows << ". From " << std::get<0>(x) << std::get<1>(x) << " To" << std::get<2>(x) << std::get<3>(x) << ".";
		if (std::get<4>(x) == 'W') {
			std::cout << "White, ";
		}
		else if (std::get<4>(x) == 'B') {
			std::cout << "Black, ";
		}
		else {
			std::cout << "Error, ";
		}
		switch (std::get<5>(x)) {
		case 'P':
			std::cout << "Pawn" << std::endl;
			break;
		case 'R':
			std::cout << "Rook" << std::endl;
			break;
		case 'C':
			std::cout << "Knight" << std::endl;
			break;
		case 'B':
			std::cout << "Bishop" << std::endl;
			break;
		case 'Q':
			std::cout << "Queen" << std::endl;
			break;
		case 'K':
			std::cout << "King" << std::endl;
			break;
		}


	}
	return 1;

}
Board::Board() {
	init_new_table();
	_actual_turn = Turn::White;
	menu_for_chess(); 
}

Board::~Board() {
	for (auto& i : table_of_chessboard) {
		for (auto& b : i) {
			if (b != nullptr) {
				delete b;
			}
		}
	}
}





