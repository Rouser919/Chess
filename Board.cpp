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
		if (tmp == true)std::cout << "Invalid cords, type again" << std::endl;
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
			table_of_chessboard[_next_move.y][_next_move.x]->getPieceType() == PieceType::None && _actual.x != _next_move.x) {
			if (table_of_chessboard[_next_move.y - 1][_next_move.x]->getPieceType() == PieceType::Pawn &&
				table_of_chessboard[_actual.y][_actual.x]->_colour != table_of_chessboard[_next_move.y - 1][_next_move.x]->_colour) {
				write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol(), 'L');
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y - 1][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
			}
			else if (table_of_chessboard[_next_move.y + 1][_next_move.x]->getPieceType() == PieceType::Pawn &&
				table_of_chessboard[_actual.y][_actual.x]->_colour != table_of_chessboard[_next_move.y + 1][_next_move.x]->_colour) {
				write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol(), 'L');
				std::swap(table_of_chessboard[_actual.y][_actual.x], table_of_chessboard[_next_move.y + 1][_next_move.x]);
				table_of_chessboard[_next_move.y][_next_move.x]->update_cords_piece(_next_move.y, _next_move.x);
				delete table_of_chessboard[_actual.y][_actual.x];
				table_of_chessboard[_actual.y][_actual.x] = new Piece(Colour::None, _actual.y, _actual.x);
			}
		}
		// castling 
		else if (table_of_chessboard[_actual.y][_actual.x]->getPieceType() == PieceType::King && table_of_chessboard[_next_move.y][_next_move.x]->getPieceType() == PieceType::None) {
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
		else {
			write_logs_from_games(_actual.y, _actual.x, _next_move.y, _next_move.x, table_of_chessboard[_actual.y][_actual.x]->getSymbol(), table_of_chessboard[_actual.y][_actual.x]->get_color_symbol(), table_of_chessboard[_next_move.y][_next_move.x]->getSymbol());
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
void Board::undo_move() {
	// check for castling
	// 0- prev y, 1- prev x, 2 actual y,3 actual x, 4 symbol,5 color
	int king = _logs.size() - 2;
	int rook = _logs.size() - 1;
	if ((std::get<4>(_logs[king]) == 'K') && ((std::get<2>(_logs[king]) == 7) || (std::get<2>(_logs[king]) == 0))) {
		// castling
		if (std::get<5>(_logs[rook]) == std::get<5>(_logs[king]) && std::get<2>(_logs[rook])== std::get<2>(_logs[king])) {
			if (table_of_chessboard[std::get<2>(_logs[rook])][std::get<3>(_logs[rook])]->get_move_count() == 1 &&
				table_of_chessboard[std::get<2>(_logs[king])][std::get<3>(_logs[king])]->get_move_count() == 1) {
				// pass color test and move test
				//long castle
				if (std::get<3>(_logs[rook]) == 3 && std::get<3>(_logs[king]) == 2){
					// King swap
					std::swap(table_of_chessboard[std::get<0>(_logs[king])][4], table_of_chessboard[std::get<2>(_logs[king])][2]);
					table_of_chessboard[std::get<2>(_logs[king])][4]->update_cords_piece(std::get<2>(_logs[king]),4);
					table_of_chessboard[std::get<2>(_logs[king])][4]->decrease_move_count_for_undo_move();
					delete table_of_chessboard[std::get<2>(_logs[king])][2];
					table_of_chessboard[std::get<2>(_logs[king])][2] = new Piece(Colour::None, std::get<2>(_logs[king]), 2);
					// Rook swap
					std::swap(table_of_chessboard[std::get<2>(_logs[rook])][3], table_of_chessboard[std::get<2>(_logs[rook])][0]);
					table_of_chessboard[std::get<2>(_logs[rook])][0]->update_cords_piece(std::get<2>(_logs[rook]), 0);
					table_of_chessboard[std::get<2>(_logs[rook])][0]->decrease_move_count_for_undo_move();
					delete table_of_chessboard[std::get<2>(_logs[rook])][3];
					table_of_chessboard[std::get<2>(_logs[rook])][3] = new Piece(Colour::None, std::get<2>(_logs[rook]), 3);
					_logs.erase(_logs.begin()+king, _logs.end());

				}
				else if (std::get<3>(_logs[rook]) == 5 && std::get<3>(_logs[king]) == 6) {
					// King swap
					std::swap(table_of_chessboard[std::get<0>(_logs[king])][4], table_of_chessboard[std::get<2>(_logs[king])][6]);
					table_of_chessboard[std::get<2>(_logs[king])][4]->update_cords_piece(std::get<2>(_logs[king]), 4);
					table_of_chessboard[std::get<2>(_logs[king])][4]->decrease_move_count_for_undo_move();
					delete table_of_chessboard[std::get<2>(_logs[king])][6];
					table_of_chessboard[std::get<2>(_logs[king])][6] = new Piece(Colour::None, std::get<2>(_logs[king]), 6);
					// Rook swap
					std::swap(table_of_chessboard[std::get<2>(_logs[rook])][5], table_of_chessboard[std::get<2>(_logs[rook])][7]);
					table_of_chessboard[std::get<2>(_logs[rook])][7]->update_cords_piece(std::get<2>(_logs[rook]), 0);
					table_of_chessboard[std::get<2>(_logs[rook])][7]->decrease_move_count_for_undo_move();
					delete table_of_chessboard[std::get<2>(_logs[rook])][5];
					table_of_chessboard[std::get<2>(_logs[rook])][5] = new Piece(Colour::None, std::get<2>(_logs[rook]), 5);
					_logs.erase(_logs.begin() + king, _logs.end());

				}

			}

		}
		
	}
	// beating in flight by Pawn
	else if (std::get<6>(_logs[_logs.size() - 1]) == 'L') {
		// White captures black
		if (std::get<2>(_logs[_logs.size() - 1]) == 5) {
			std::swap(table_of_chessboard[std::get<0>(_logs[_logs.size()-1])][std::get<1>(_logs[_logs.size() - 1])], table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])]);
			table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->decrease_move_count_for_undo_move();
			delete table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])];
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])] = new Piece(Colour::None, std::get<2>(_logs[_logs.size() - 1]),std::get<3>(_logs[_logs.size() - 1]));
			delete  table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) - 1][std::get<3>(_logs[_logs.size() - 1])];
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) - 1][std::get<3>(_logs[_logs.size() - 1])] = new  Pawn(Colour::Black, std::get<2>(_logs[_logs.size() - 1]) - 1, std::get<3>(_logs[_logs.size() - 1]) );
			// not important if move_count is equal or more than 1, just need to be mooved
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) - 1][std::get<3>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<2>(_logs[_logs.size() - 1]) - 1, std::get<3>(_logs[_logs.size() - 1]) );
			_logs.erase(_logs.end());
		}
			//black captures white
		else if (std::get<2>(_logs[_logs.size() - 1]) == 2) {
			std::swap(table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])], table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])]);
			table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->decrease_move_count_for_undo_move();
			delete table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])];
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])] = new Piece(Colour::None, std::get<2>(_logs[_logs.size() - 1]), std::get<3>(_logs[_logs.size() - 1]));
			delete  table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) + 1][std::get<3>(_logs[_logs.size() - 1])];
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) + 1][std::get<3>(_logs[_logs.size() - 1])] = new  Pawn(Colour::Black, std::get<2>(_logs[_logs.size() - 1]) + 1, std::get<3>(_logs[_logs.size() - 1]));
			// not important if move_count is equal or more than 1, just need to be mooved
			table_of_chessboard[std::get<2>(_logs[_logs.size() - 1]) + 1][std::get<3>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<2>(_logs[_logs.size() - 1]) + 1, std::get<3>(_logs[_logs.size() - 1]));
			_logs.erase(_logs.end());
			}

		}
		else {
		delete table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])];
		switch (std::get<6>(_logs[_logs.size() - 1])) {
		case 'P':
			if (std::get<5>(_logs[_logs.size() - 1])=='W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Pawn(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Pawn(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case 'R':
			if (std::get<5>(_logs[_logs.size() - 1]) == 'W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Rook(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Rook(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case 'C':
			if (std::get<5>(_logs[_logs.size() - 1]) == 'W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Knight(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Knight(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case 'B':
			if (std::get<5>(_logs[_logs.size() - 1]) == 'W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Bishop(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Bishop(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case'Q':
			if (std::get<5>(_logs[_logs.size() - 1]) == 'W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Queen(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Queen(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case 'K':
			if (std::get<5>(_logs[_logs.size() - 1]) == 'W') {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new King(Colour::Black, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			else {
				table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new King(Colour::White, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			}
			break;
		case ' ':
			table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])] = new Piece(Colour::None, std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
			break;
		default:
			break;
		}
		std::swap(table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])], table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])]);
		table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<0>(_logs[_logs.size() - 1]), std::get<1>(_logs[_logs.size() - 1]));
		table_of_chessboard[std::get<0>(_logs[_logs.size() - 1])][std::get<1>(_logs[_logs.size() - 1])]->decrease_move_count_for_undo_move();
		// not important if move_count is equal or more than 1, just need to be mooved
		table_of_chessboard[std::get<2>(_logs[_logs.size() - 1])][std::get<3>(_logs[_logs.size() - 1])]->update_cords_piece(std::get<2>(_logs[_logs.size() - 1]), std::get<3>(_logs[_logs.size() - 1]));
		_logs.erase(_logs.end());

		std::cout << "s";
		}

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
				std::cout << "Type 1 for play as white, type 2 for play as black" << std::endl;
				std::cin >> option;
				if (option == '1' || option == '2')player_vs_AI(option);
			}
			else { std::cout << "Wrong number, type again!"<<std::endl; }
			break;
		case '2' :
			std::cout << std::endl << "1.First write letter of a cords then number" << std::endl <<
				"2.Default white pieces start" << std::endl << "3.Names of figure with shortcut:" << std::endl <<
				"P-Pawn" << std::endl << "R-Rook" << std::endl << "C-Knight" << std::endl << "B-Bishop" << std ::endl << "Q-Queen" << std::endl << "K-King" << std::endl <<
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
	bool good_data = false;
	_logs.clear();
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
		if (!move_piece()) {
			do {
				get_cords_to_move();
			} while (!move_piece());
		}

		if (check_for_win_or_draw()) win_check = true;
	}
	_logs_from_games.push_back(_logs);

}
// Need good handle it
void Board::player_vs_AI(int type) {
	bool win_check = false;
	bool good_data = false;
	_logs.clear();
	if (type == '1') {
		while (win_check == false) {
			_actual_turn = Turn::White;
			print_board();
			std::cout << "Your turn";
			std::cout << std::endl;
			update_all_moves();
			castling();
			check_for_check_mate();
			get_cords_to_move();
			if (!move_piece()) {
				do {
					get_cords_to_move();
				} while (!move_piece());
			}
			if (check_for_win_or_draw()) {
				win_check = true;
				continue;
			}
			_actual_turn = Turn::Black;
			print_board();
			std::cout << "Computer Turn" << std::endl;
			begin_of_breadth_search();
			move_piece();
			check_for_check_mate();
			if (check_for_win_or_draw()) win_check = true;
		}

	}
	else {
		while (win_check == false) {
			_actual_turn = Turn::White;
			std::cout << "Computer Turn" << std::endl;
			print_board();
			update_all_moves();
			castling();
			begin_of_breadth_search();
			move_piece();
			check_for_check_mate();
			if (check_for_win_or_draw()) {
				win_check = true;
				continue;
			}
			print_board();
			std::cout << "Your turn";
			std::cout << std::endl;
			_actual_turn = Turn::Black;
			update_all_moves();
			castling();
			get_cords_to_move();
			if (!move_piece()) {
				do {
					get_cords_to_move();
				} while (!move_piece());
			}
			check_for_check_mate();
			if (check_for_win_or_draw()) {
				win_check = true;
			}

		}


	}

	_logs_from_games.push_back(_logs);

}
void Board::write_logs_from_games(char actual_y, char actual_x, char next_y, char next_x,char symbol,char color,char beating ) {
	_logs.push_back(std::make_tuple(actual_y, actual_x, next_y, next_x,symbol,color,beating));
}
bool Board::read_logs_from_games() {
	std::cout << _logs_from_games.size() << " games are available to seen" << std::endl;
	if (_logs_from_games.size() == 0) { std::cout << " Return to main menu" << std::endl; return 0; }
	std::cout << "Choose one" << std::endl;
	int i;
	std::cin >> i;
	while(i> _logs_from_games.size() || i<1){
		std::cout << "Wrong number, type again!" << std::endl;
		std::cout << _logs_from_games.size() << " games are available to seen" << std::endl;
		std::cout << "Choose one" << std::endl;
		std::cin >> i;
	}
	std::cout << std::endl << "------------------" << std::endl << "Game " << i << ":" << std::endl;
	for (auto& x : _logs_from_games[i - 1]) {
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
// There must be another base function for breadth_search to do best move for AI
void Board::begin_of_breadth_search() {
	std::tuple<char, char, char, char> move;
	double value = 0, tmp_value = 0;
	cords actual;
	if (Turn::White==_actual_turn) {
		for (auto& b : table_of_chessboard) {
			for (auto& x : b) {
				actual.x = x->_actual.x;
				actual.y = x->_actual.y;
				change_actual_move(actual.y, actual.x);
				if (x->_colour == Colour::White) {
					for (auto& values : x->_array_of_moves_with_value) {
						change_next_move(std::get<0>(values), std::get<1>(values));
						move_piece();
						tmp_value = breadth_search(_depth_search - 1,Colour::White);
						if (tmp_value < value) {
							tmp_value = value;
							move = std::make_tuple(actual.y, actual.x, std::get<0>(values), std::get<1>(values));
						}
						undo_move();

					}
				}
			}
		}

	}
	else {
		for (auto& b : table_of_chessboard) {
			for (auto& x : b) {
				actual.x = x->_actual.x;
				actual.y = x->_actual.y;
				change_actual_move(actual.y, actual.x);
				if (x->_colour == Colour::Black) {
					for (auto& values : x->_array_of_moves_with_value) {
						change_next_move(std::get<0>(values), std::get<1>(values));
						move_piece();
						tmp_value = breadth_search(_depth_search - 1,Colour::Black);
						if (tmp_value > value) {
							tmp_value = value;
							move = std::make_tuple(actual.y, actual.x, std::get<0>(values), std::get<1>(values));
						}
						undo_move();

					}
				}
			}
		}
	}
	change_actual_move(std::get<0>(move), std::get<1>(move));
	change_next_move(std::get<2>(move), std::get<3>(move));
}
double Board::breadth_search(char depth,Colour color) {
	update_all_moves();
	castling();
	double value = 0;
	double max = 0;
	cords actual;
	if (depth >= 0) {
		if (color == Colour::White) {
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::White) {
						actual.x = x->_actual.x;
						actual.y = x->_actual.y;
						change_actual_move(actual.y, actual.x);
						for (auto& values : x->_array_of_moves_with_value) {
							change_next_move(std::get<0>(values), std::get<1>(values));
							move_piece();
							value = std::get<2>(values)+ breadth_search(depth - 1,Colour::White);
							if (value < max) {
								max = value;
							}
							undo_move();
						}
					}
				}
			}
		}
		else if(color == Colour::Black){
			for (auto& b : table_of_chessboard) {
				for (auto& x : b) {
					if (x->_colour == Colour::Black) {
						actual.x = x->_actual.x;
						actual.y = x->_actual.y;
						change_actual_move(actual.y, actual.x);
						for (auto& values : x->_array_of_moves_with_value) {
							change_next_move(std::get<0>(values), std::get<1>(values));
							move_piece();
							value = std::get<2>(values) + breadth_search(depth - 1,Colour::Black);
							if (value > max) {
								max = value;
							}
							undo_move();
						}


					}
				}
			}

		}
		return max;
	}
	else return 0;
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





