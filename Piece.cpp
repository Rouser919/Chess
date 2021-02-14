#include "Piece.h"

// PIECE IMPLEMENTATION

Piece::Piece(Colour colour, char y, char x) {
	Piece::_colour = colour;
	_actual.x = x;
	_actual.y = y;
}
void Piece::update_cords_piece(char y, char x) {
	_actual.x = x;
	_actual.y = y;
	increase_move_count();
}
value_of_moves_with_cords Piece::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	return _array_of_moves_with_value;
}

// PAWN IMPLEMENTATION 
Pawn::Pawn(Colour colour, char y, char x) :Piece(colour,y,x) {}
int Pawn::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double Pawn::position_score(char y, char x) {
	if (Pawn::_colour == Colour::White) {
		return Pawn::_scoreBoard[7 - y][x];
	}
	else {
		return -Pawn::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords Pawn::all_posible_moves_with_value(Piece* board[8][8]){ 
	_array_of_moves_with_value.clear();
	if (_colour == Colour::White) {
		if (_actual.y + 1 != 8) {
			// moves forward
			if (board[_actual.y + 1][_actual.x]->getPieceType() == PieceType::None  ) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y+1, _actual.x, position_score(_actual.y + 1, _actual.x)));
			}
			// moves forward by 2 in start
			if (_actual.y == 1 && (board[_actual.y + 2][_actual.x]->getPieceType() == PieceType::None && board[_actual.y + 1][_actual.x]->getPieceType() == PieceType::None)) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 2, _actual.x, position_score(_actual.y + 2, _actual.x)));
			}
			// beating in flight
			if (_actual.y == 4) { 
				if (_actual.x + 1 < 8 && board[_actual.y][_actual.x + 1]->getPieceType() == PieceType::Pawn && board[_actual.y][_actual.x + 1]->get_move_count() == 1 && board[_actual.y+1][_actual.x + 1]->getPieceType() == PieceType::None) {
					_array_of_moves_with_value.push_back(std::make_tuple(_actual.y+1 , _actual.x + 1, position_score(_actual.y+1 , _actual.x + 1) + board[_actual.y+1][_actual.x + 1]->get_value()));
				}
				if (_actual.x - 1 >= 0 && board[_actual.y][_actual.x - 1]->getPieceType() == PieceType::Pawn && board[_actual.y][_actual.x - 1]->get_move_count() == 1 && board[_actual.y + 1][_actual.x - 1]->getPieceType() == PieceType::None) {
					_array_of_moves_with_value.push_back(std::make_tuple(_actual.y+1, _actual.x - 1, position_score(_actual.y+1, _actual.x - 1) + board[_actual.y+1][_actual.x - 1]->get_value()));
				}
			}
			// capture enemy piece left and right 
			if (_actual.x +1 <8 && board[_actual.y + 1][_actual.x + 1]->_colour == Colour::Black  && board[_actual.y + 1][_actual.x + 1]) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x + 1, position_score(_actual.y + 1, _actual.x + 1) + board[_actual.y + 1][_actual.x + 1]->get_value()));
			}
			if ( _actual.x - 1 >= 0 &&board[_actual.y + 1][_actual.x - 1]->_colour == Colour::Black ) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x - 1, position_score(_actual.y + 1, _actual.x - 1) + board[_actual.y + 1][_actual.x - 1]->get_value()));
			}


		}
	}
	else if (_colour == Colour::Black) {
		if (_actual.y -1 >=0) {
			// moves forward
			if (board[_actual.y - 1][_actual.x]->getPieceType() == PieceType::None) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y-1, _actual.x , position_score(_actual.y - 1, _actual.x)));
			}
			// moves forward by 2 in start
			if (_actual.y == 6 && (board[_actual.y - 2][_actual.x]->getPieceType() == PieceType::None) &&  board[_actual.y - 1][_actual.x]->getPieceType() == PieceType::None) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 2, _actual.x, position_score(_actual.y - 2, _actual.x)));
			}
			// beating in flight
			if (_actual.y == 3) {
				if (_actual.x + 1 < 8 && board[_actual.y][_actual.x + 1]->getPieceType() == PieceType::Pawn && board[_actual.y][_actual.x + 1]->get_move_count() == 1 && board[_actual.y - 1][_actual.x + 1]->getPieceType() == PieceType::None) {
					_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x + 1, position_score(_actual.y - 1, _actual.x + 1) + board[_actual.y - 1][_actual.x + 1]->get_value()));
				}
				if (_actual.x - 1 >= 0 && board[_actual.y][_actual.x - 1]->getPieceType() == PieceType::Pawn && board[_actual.y][_actual.x - 1]->get_move_count() == 1 && board[_actual.y - 1][_actual.x - 1]->getPieceType() == PieceType::None) {
					_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x - 1, position_score(_actual.y - 1, _actual.x - 1) + board[_actual.y - 1][_actual.x - 1]->get_value()));
				}
			}
			// capture enemy piece left and right 
			if ( _actual.x + 1 < 8 && board[_actual.y - 1][_actual.x + 1]->_colour == Colour::White ) {
					_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x + 1, position_score(_actual.y - 1, _actual.x + 1) + board[_actual.y - 1][_actual.x + 1]->get_value()));
			}
			if ( _actual.x - 1 >= 0 && board[_actual.y - 1][_actual.x - 1]->_colour == Colour::White ) {
				_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x - 1, position_score(_actual.y - 1, _actual.x - 1) + board[_actual.y - 1][_actual.x - 1]->get_value()));
			}

		}
	}
	return _array_of_moves_with_value; 
}

// ROOK IMPLEMENTATION 

Rook::Rook(Colour colour, char y, char x) :Piece(colour, y, x) {}
int Rook::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double Rook::position_score(char y, char x) {
	if (Rook::_colour == Colour::White) {
		return Rook::_scoreBoard[7 - y][x];
	}
	else {
		return -Rook::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords Rook::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	int i;
		// search for moves of left side x
	for (i = _actual.x-1;i>=0 && board[_actual.y][i]->getPieceType() == PieceType::None; i--) { 
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y,i , position_score(_actual.y, i)));	
		}
	if (i >= 0 && board[_actual.y][i]->_colour != _colour) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y , i, position_score(_actual.y , i) + board[_actual.y ][i]->get_value()));
		}
		// search for moves of right side x
	for (i = _actual.x + 1;i<8 && board[_actual.y][i]->getPieceType() == PieceType ::None; i++) { 
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i)));
		}
	if (i < 8 && board[_actual.y][i]->_colour != _colour) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i) + board[_actual.y][i]->get_value()));
		}
		// look for forward moves from y
	for (i = _actual.y +1; i < 8 && board[i][_actual.x]->getPieceType() == PieceType::None; i++) { 
			_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x)));
		}
	if (i < 8 && board[i][_actual.x]->_colour != _colour) {
			_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x) + board[i][ _actual.x]->get_value()));
		}
		// look for backward moves from y
	for (i = _actual.y - 1; i >=0  && board[i][_actual.x]->getPieceType() == PieceType::None; i--) { 
			_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x)));
		}
	if (i >= 0 && board[i][_actual.x]->_colour != _colour) {
			_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x) + board[i][_actual.x]->get_value()));
		}
	return _array_of_moves_with_value;
}

// BISHOP IMPLEMENTATION 

Bishop::Bishop(Colour colour, char y, char x):Piece(colour,y,x){}
int Bishop::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double Bishop::position_score(char y, char x) {
	if (Bishop::_colour == Colour::White) {
		return Bishop::_scoreBoard[7 - y][x];
	}
	else {
		return -Bishop::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords Bishop::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	int i;
	// search for moves above piece in right diagonal
	for (i = 1; _actual.x + i < 8 && _actual.y + i < 8 && board[_actual.y + i][_actual.x + i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y+i, _actual.x+i, position_score(_actual.y + i, _actual.x + i)));
	}
	if (_actual.x + i < 8 && _actual.y + i < 8 && board[_actual.y + i][_actual.x + i]->_colour!=_colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y+i,_actual.x + i, position_score(_actual.y +i, _actual.x+ i) + board[_actual.y+i][_actual.x+i]->get_value()));
	}
	// search for moves below piece in right diagonal
	for (i = 1; _actual.x - i >= 0 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x - i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x - i, position_score(_actual.y - i, _actual.x - i)));
	}
	if (_actual.x - i >= 0 && _actual.y - i >=0 && board[_actual.y - i][_actual.x - i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x - i, position_score(_actual.y - i, _actual.x - i) + board[_actual.y - i][_actual.x - i]->get_value()));
	}

	// search for moves above piece in left diagonal
	for (i = 1; _actual.x - i >=0 && _actual.y + i < 8 && board[_actual.y + i][_actual.x - i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x - i, position_score(_actual.y + i, _actual.x - i)));
	}
	if (_actual.x - i >= 0 && _actual.y + i < 8 && board[_actual.y + i][_actual.x - i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x - i, position_score(_actual.y + i, _actual.x - i) + board[_actual.y + i][_actual.x - i]->get_value()));
	}
	// search for moves below piece in left diagonal
	for (i = 1; _actual.x + i < 8 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x + i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x + i, position_score(_actual.y - i, _actual.x + i)));
	}
	if (_actual.x + i < 8 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x + i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x + i, position_score(_actual.y - i, _actual.x + i) + board[_actual.y - i][_actual.x + i]->get_value()));
	}
	return _array_of_moves_with_value;
}

// KNIGHT IMPLEMENTATION

Knight::Knight(Colour colour, char y, char x):Piece(colour,y,x) {}
int Knight::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double Knight::position_score(char y, char x) {
	if (Knight::_colour == Colour::White) {
		return Knight::_scoreBoard[7 - y][x];
	}
	else {
		return Knight::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords Knight::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	if (_actual.y + 2 < 8 && _actual.x + 1 < 8 && board[_actual.y + 2][_actual.x + 1]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 2, _actual.x + 1, position_score(_actual.y + 2, _actual.x + 1) + board[_actual.y + 2][_actual.x + 1]->get_value()));
	}
	if (_actual.y + 1 < 8 && _actual.x + 2 < 8 && board[_actual.y + 1][_actual.x + 2]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x + 2, position_score(_actual.y + 1, _actual.x + 2) + board[_actual.y + 1][_actual.x + 2]->get_value()));
	}
	if (_actual.y - 1 >=0 && _actual.x + 2 < 8 && board[_actual.y -1][_actual.x + 2]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x + 2, position_score(_actual.y - 1, _actual.x + 2) + board[_actual.y - 1][_actual.x + 2]->get_value()));
	}
	if (_actual.y - 2 >= 0 && _actual.x + 1 < 8 && board[_actual.y - 2][_actual.x + 1]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 2, _actual.x + 1, position_score(_actual.y - 2, _actual.x + 1) + board[_actual.y - 2][_actual.x + 1]->get_value()));
	}
	if (_actual.y - 2 >= 0 && _actual.x - 1 >=0 && board[_actual.y - 2][_actual.x - 1]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 2, _actual.x - 1, position_score(_actual.y - 2, _actual.x - 1) + board[_actual.y - 2][_actual.x - 1]->get_value()));
	}
	if (_actual.y - 1 >= 0 && _actual.x - 2 >= 0 && board[_actual.y - 1][_actual.x - 2]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x - 2, position_score(_actual.y - 1, _actual.x - 2) + board[_actual.y - 1][_actual.x - 2]->get_value()));
	}
	if (_actual.y + 1 < 8 && _actual.x - 2 >= 0 && board[_actual.y + 1][_actual.x - 2]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x - 2, position_score(_actual.y + 1, _actual.x - 2) + board[_actual.y + 1][_actual.x - 2]->get_value()));
	}
	if (_actual.y + 2 < 8 && _actual.x - 1 >= 0 && board[_actual.y + 2][_actual.x - 1]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 2, _actual.x - 1, position_score(_actual.y + 2, _actual.x - 1) + board[_actual.y + 2][_actual.x - 1]->get_value()));
	}
	return _array_of_moves_with_value;
}

// QUEEN IMPLEMENTATION

Queen::Queen(Colour colour, char y, char x): Piece(colour,y,x){}
int Queen::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double Queen::position_score(char y, char x) {
	if (Queen::_colour == Colour::White) {
		return Queen::_scoreBoard[7 - y][x];
	}
	else {
		return Queen::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords Queen::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	int i;
	// search for moves of left side x
	for (i = _actual.x - 1; i >= 0 && board[_actual.y][i]->getPieceType() == PieceType::None; i--) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i)));
	}
	if (i <= 0 && board[_actual.y][i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i) + board[_actual.y][i]->get_value()));
	}
	// search for moves of right side x
	for (i = _actual.x + 1; i < 8 && board[_actual.y][i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i)));
	}
	if (i < 8 && board[_actual.y][i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, i, position_score(_actual.y, i) + board[_actual.y][i]->get_value()));
	}
	// look for forward moves from y
	for (i = _actual.y + 1; i < 8 && board[i][_actual.x]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x)));
	}
	if (i < 8 && board[i][_actual.x]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x) + board[i][_actual.x]->get_value()));
	}
	// look for backward moves from y
	for (i = _actual.y - 1; i >= 0 && board[i][_actual.x]->getPieceType() == PieceType::None; i--) {
		_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x)));
	}
	if (i >= 0 && board[i][_actual.x]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(i, _actual.x, position_score(i, _actual.x) + board[i][_actual.x]->get_value()));
	}



	// search for moves above piece in right diagonal
	for (i = 1; _actual.x + i < 8 && _actual.y + i < 8 && board[_actual.y + i][_actual.x + i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x + i, position_score(_actual.y + i, _actual.x + i)));
	}
	if (_actual.x + i < 8 && _actual.y + i < 8 && board[_actual.y + i][_actual.x + i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x + i, position_score(_actual.y + i, _actual.x + i) + board[_actual.y + i][_actual.x + i]->get_value()));
	}
	// search for moves below piece in right diagonal
	for (i = 1; _actual.x - i >= 0 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x - i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x - i, position_score(_actual.y - i, _actual.x - i)));
	}
	if (_actual.x - i >= 0 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x - i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x - i, position_score(_actual.y - i, _actual.x - i) + board[_actual.y - i][_actual.x - i]->get_value()));
	}

	// search for moves above piece in left diagonal
	for (i = 1; _actual.x - i >= 0 && _actual.y + i < 8 && board[_actual.y + i][_actual.x - i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x - i, position_score(_actual.y + i, _actual.x - i)));
	}
	if (_actual.x - i >= 0 && _actual.y + i < 8 && board[_actual.y + i][_actual.x - i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + i, _actual.x - i, position_score(_actual.y + i, _actual.x - i) + board[_actual.y + i][_actual.x - i]->get_value()));
	}
	// search for moves below piece in left diagonal
	for (i = 1; _actual.x + i < 8 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x + i]->getPieceType() == PieceType::None; i++) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x + i, position_score(_actual.y - i, _actual.x + i)));
	}
	if (_actual.x + i < 8 && _actual.y - i >= 0 && board[_actual.y - i][_actual.x + i]->_colour != _colour) {
		_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - i, _actual.x + i, position_score(_actual.y - i, _actual.x + i) + board[_actual.y - i][_actual.x + i]->get_value()));
	}

	return _array_of_moves_with_value;
}

// KING IMPLEMENTATION

King::King( Colour colour,char y, char x):Piece(colour,y,x){}
bool King::is_there_a_enemy_king(Piece* board[8][8],char y,char x) {
	if (y - 1 >= 0 && board[y - 1][x]->getPieceType() == PieceType::King && _colour != board[y - 1][x]->_colour) return 1;
	if (y - 1 >= 0 && x-1 >=0 && board[y - 1][x-1]->getPieceType() == PieceType::King && _colour != board[y - 1][x-1]->_colour) return 1;
	if (x- 1 >= 0 && board[y][x-1]->getPieceType() == PieceType::King && _colour != board[y][x-1]->_colour) return 1;
	if (y + 1 < 8 && x - 1 >= 0 && board[y + 1][x - 1]->getPieceType() == PieceType::King && _colour != board[y + 1][x - 1]->_colour) return 1;
	if (y + 1 <8 && board[y + 1][x]->getPieceType() == PieceType::King && _colour != board[y + 1][x]->_colour) return 1;
	if (y +1 <8 && x + 1 < 8 && board[y + 1][x + 1]->getPieceType() == PieceType::King && _colour != board[y + 1][x + 1]->_colour) return 1;
	if (x + 1 < 8 && board[y][x + 1]->getPieceType() == PieceType::King && _colour != board[y][x + 1]->_colour) return 1;
	if (x + 1 < 8 && y-1>=0 && board[y-1][x + 1]->getPieceType() == PieceType::King && _colour != board[y-1][x + 1]->_colour) return 1;
	
	return 0;
}
int King::get_value() {
	if (_colour == Colour::White) {
		return _value;
	}
	else {
		return -_value;
	}
}
double King::position_score(char y, char x) {
	if (King::_colour == Colour::White) {
		return King::_scoreBoard[7 - y][x];
	}
	else {
		return King::_scoreBoard[y][x];
	}
}
value_of_moves_with_cords King::all_posible_moves_with_value(Piece* board[8][8]) {
	_array_of_moves_with_value.clear();
	if (_actual.y - 1 >= 0 && _colour != board[_actual.y-1][_actual.x]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y - 1, _actual.x)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y-1, _actual.x, position_score(_actual.y-1,_actual.x) + board[_actual.y-1][_actual.x]->get_value()));
		}
	}
	if (_actual.y - 1 >= 0 && _actual.x-1 >=0 && _colour != board[_actual.y - 1][_actual.x-1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y - 1, _actual.x-1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x-1, position_score(_actual.y - 1, _actual.x-1) + board[_actual.y - 1][_actual.x-1]->get_value()));
		}
	}
	if (_actual.x- 1 >= 0 && _colour != board[_actual.y ][_actual.x-1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y , _actual.x-1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, _actual.x-1, position_score(_actual.y , _actual.x-1) + board[_actual.y ][_actual.x-1]->get_value()));
		}
	}
	if (_actual.y + 1 <8 && _actual.x-1>=0 && _colour != board[_actual.y + 1][_actual.x-1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y + 1, _actual.x-1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x -1, position_score(_actual.y + 1, _actual.x -1 ) + board[_actual.y + 1][_actual.x -1]->get_value()));
		}
	}
	if (_actual.y + 1 < 8 &&  _colour != board[_actual.y + 1][_actual.x]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y + 1, _actual.x )) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x , position_score(_actual.y + 1, _actual.x ) + board[_actual.y + 1][_actual.x ]->get_value()));
		}
	}
	if (_actual.y + 1 < 8 && _actual.x +1 <8 && _colour != board[_actual.y + 1][_actual.x + 1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y + 1, _actual.x + 1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y + 1, _actual.x + 1, position_score(_actual.y + 1, _actual.x + 1) + board[_actual.y + 1][_actual.x + 1]->get_value()));
		}
	}
	if (_actual.x +1 <8 && _colour != board[_actual.y][_actual.x + 1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y, _actual.x + 1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y, _actual.x + 1, position_score(_actual.y, _actual.x + 1) + board[_actual.y][_actual.x + 1]->get_value()));
		}
	}
	if (_actual.y - 1 >= 0 && _actual.x + 1 < 8 && _colour != board[_actual.y - 1][_actual.x + 1]->_colour) {
		if (!is_there_a_enemy_king(board, _actual.y - 1, _actual.x + 1)) {
			_array_of_moves_with_value.push_back(std::make_tuple(_actual.y - 1, _actual.x + 1, position_score(_actual.y - 1, _actual.x + 1) + board[_actual.y - 1][_actual.x + 1]->get_value()));
		}
	}
	return _array_of_moves_with_value;
}
