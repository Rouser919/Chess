#pragma once
#include <vector>
enum class Colour { None, White, Black };
enum class PieceType { None, Pawn, Rook, Bishop, Knight, Queen, King };
typedef std::pair<char, char> cords;
class Piece
{
	static const PieceType pieceType = PieceType::None;
	static const char represent_figure = ' ';
public:
	cords _actual;
	Colour colour;
	int move_count = 0;
	Piece(Colour colour);
	virtual bool posible_move(Piece * board[8][8], cords& next_space);
	virtual std::vector<cords> all_posible_moves(Piece* board[8][8]);
	virtual char getSymbol();
	virtual PieceType getPieceType();
};

class Pawn:public Piece 
{
	static const PieceType pieceType = PieceType::Pawn;
	static const char represent_figure = 'P' ;
public:
	Pawn(Colour colour);
	char getSymbol();
	bool posible_move(Piece* board[8][8], cords& next_space) override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
 	PieceType getPieceType();
};

class Rook :public Piece 
{
	static const PieceType piecetype = PieceType::Rook;
	static const char represent_figure = 'R';
public:
	Rook(Colour colour);
	char getSymbol();
	bool posible_move(Piece* board[8][8], cords& next_space)override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
	PieceType getPieceType();
};
class Bishop :public Piece
{
	static const PieceType piecetype = PieceType::Bishop;
	static const char represent_figure = 'B';
public:
	Bishop(Colour colour);
	char getSymbol();
	bool posible_move(Piece * board[8][8], cords& next_space)override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
	PieceType getPieceType();
};
class Knight :public Piece
{
	static const PieceType piecetype = PieceType::Knight;
	static const char represent_figure = 'K';
public:
	Knight(Colour colour);
	char getSymbol();
	bool posible_move(Piece * board[8][8], cords& next_space)override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
	PieceType getPieceType();
};
class Queen :public Piece
{
	static const PieceType piecetype = PieceType::Queen;
	static const char represent_figure = 'Q';
public:
	Queen(Colour colour);
	char getSymbol();
	bool posible_move(Piece * board[8][8], cords& next_space)override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
	PieceType getPieceType();
};
class King :public Piece
{
	static const PieceType piecetype = PieceType::King;
	static const char represent_figure = 'K';
public:
	King(Colour colour);
	char getSymbol();
	bool posible_move(Piece * board[8][8], cords& next_space)override;
	std::vector<cords> all_posible_moves(Piece* board[8][8]) override;
	PieceType getPieceType();
};



