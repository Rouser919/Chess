#pragma once
#include <vector>
#include <tuple>
enum class Colour {None, White, Black };
enum class PieceType {None ,Pawn, Rook, Bishop, Knight, Queen, King };
typedef std::vector<std::tuple<char, char, double>> value_of_moves_with_cords;
struct cords {
	char x;
	char y;
};
class Piece
{
private:
	static const PieceType _piecetype = PieceType::None;
	static const char _represent_figure = ' ';
	static const int _value = 0;
	int move_count = 0;
public:
	Colour _colour;
	cords _actual;
	value_of_moves_with_cords _array_of_moves_with_value;
	Piece(Colour colour,char y, char x);
	virtual void increase_move_count() { move_count++; }
	virtual int get_move_count() { return move_count; }
	void update_cords_piece(char y ,char x);
	virtual int get_value() { return Piece::_value; }
	virtual double position_score(char y,char x) { return 0; }
	virtual char getSymbol() { return Piece::_represent_figure; }
	virtual PieceType getPieceType() { return Piece::_piecetype; }
	virtual value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]);
};
class Pawn:public Piece 
{
	static const PieceType _piecetype = PieceType::Pawn;
	static const char _represent_figure = 'P' ;
	static const int _value = 10;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ 0,  0,  0,  0,  0,  0,  0,  0},
	{5, 5, 5, 5, 5, 5, 5, 5},
	{1, 1, 2, 3, 3, 2, 1, 1},
	{0.5,  0.5, 1, 2.5, 2.5, 1,  0.5, 0.5},
	{0,  0,  0, 2, 2,  0,  0,  0},
	{0.5, -0.5,-1,  0,  0,-1, -0.5,  0.5},
	{0.5, 1, 1,-2,-2, 1, 1, 0.5},
	{0,  0,  0,  0,  0,  0,  0,  0}
	};
public:
	Pawn(Colour _colour,char y, char x );
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return Pawn::_represent_figure; }
	int get_value()override;
	double position_score(char y,char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override ;
	PieceType getPieceType() override { return Pawn::_piecetype; }
};
class Rook :public Piece 
{
	static const PieceType _piecetype = PieceType::Rook;
	static const char _represent_figure = 'R';
	static const int _value = 50;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ 0,  0,  0,  0,  0,  0,  0,  0},
	{0.5, 1, 1, 1, 1, 1, 1, 0.5},
	{-0.5, 0, 0, 0, 0, 0, 0,-0.5},
	{-0.5, 0, 0, 0, 0, 0, 0,-0.5},
	{-0.5, 0, 0, 0, 0, 0, 0,-0.5},
	{-0.5, 0, 0, 0, 0, 0, 0,-0.5},
	{-0.5, 0, 0, 0, 0, 0, 0,-0.5},
	{0, 0, 0, 0.5, 0.5, 0, 0, 0}
		};
public:
	Rook(Colour colour, char y,char x);
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return Rook::_represent_figure; }
	int get_value()override;
	double position_score(char y, char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override;
	PieceType getPieceType() override { return Rook::_piecetype; }
};
class Bishop :public Piece
{
	static const PieceType _piecetype = PieceType::Bishop;
	static const char _represent_figure = 'B';
	static const int _value = 30;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ -2, -1, -1, -1,  -1, -1, -1, -2},
	{ -1, -0, 0, 0, 0, 0, 0, -1},
	{ -1, 0, 0.5, 1, 1, 0.5, 0, -1},
	{ -1, 0.5, 0.5, 1, 1, 0.5, 0.5,-1},
	{ -1, 0, 1, 1, 1, 1, 0,-1},
	{ -1, 1, 1, 1, 1, 1, 1, -1},
	{ -1, 0.5, 0, 0, 0, 0, 0.5, -1},
	{ -2, -1, -1, -1,  -1, -1, -1, -2}
		};
public:
	Bishop(Colour colour, char y,char x);
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return Bishop::_represent_figure; }
	int get_value()override;
	double position_score(char y, char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override;
	PieceType getPieceType() override { return Bishop::_piecetype; }
};
class Knight :public Piece
{
	static const PieceType _piecetype = PieceType::Knight;
	static const char _represent_figure = 'K';
	static const int _value = 30;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ -5, -4, -3, -3,  -3, -3, -4, -5},
	{-4, -2, 0, 0, 0, 0, -2, -4},
	{-3, 0, 1, 1.5, 1.5, 1.0, 0, -3},
	{-0.5, 0.5, 1.5, 2, 2, 1.5, 0.5,-3},
	{-0.5, 0, 1.5, 2, 2, 1.5, 0,-3},
	{-3, 0.5, 1, 1.5, 1.5, 1.0, 0.5, -3},
	{ -4, -2, 0, 0.5, 0.5, 0, -2, -4},
	{ -5, -4, -3, -3, -3, -3, -4, -5}
	};
public:
	Knight(Colour colour, char y,char x);
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return Knight::_represent_figure; }
	int get_value()override;
	double position_score(char y, char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override;
	PieceType getPieceType() override { return Knight::_piecetype; }
};
class Queen :public Piece
{
	static const PieceType _piecetype = PieceType::Queen;
	static const char _represent_figure = 'Q';
	static const int _value = 90;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ -2, -1, -1, -0.5, -0.5, -1, -1, -2},
	{-1, -0, 0, 0, 0, 0, 0, -1},
	{-1, 0, 0.5, 1.5, 1.0, 0, -3},
	{-0.5, 0.5, 1.5, 2, 2, 1.5, 0.5,-3},
	{-0.5, 0, 1.5, 2, 2, 1.5, 0,-3},
	{-3, 0.5, 1, 1.5, 1.5, 1.0, 0.5, -3},
	{-1, -0, 0.5, 0, 0, 0, 0, -1},
	{ -2, -1, -1, -0.5, -0.5, -1, -1, -2}
	};
public:
	Queen(Colour colour, char y,char x);
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return Queen::_represent_figure; }
	int get_value()override;
	double position_score(char y, char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override;
	PieceType getPieceType() override { return Queen::_piecetype; }
};
class King :public Piece
{
	static const PieceType _piecetype = PieceType::King;
	static const char _represent_figure = 'K';
	static const int _value = 10000;
	int move_count = 0;
	double _scoreBoard[8][8] = {
	{ -3, -4, -4, -5, -5, -4, -4, -3},
	{ -3, -4, -4, -5, -5, -4, -4, -3},
	{ -3, -4, -4, -5, -5, -4, -4, -3},
	{ -3, -4, -4, -5, -5, -4, -4, -3},
	{-2, -3, -3, -4, -4, -3, 3,-2},
	{-1, -2, -2, -2, -2, -2, -2, -1},
	{2, 2, 0, 0, 0, 0, 2, 2},
	{ 2, 3, 1, 0, 0, 1, 3, 2}
	};
	bool is_there_a_enemy_king(Piece* board[8][8],char y,char x);
public:
	King(Colour colour, char y,char x);
	void increase_move_count() override { move_count++; }
	int get_move_count()override { return move_count; }
	char getSymbol()override { return King::_represent_figure; }
	int get_value()override;
	double position_score(char y, char x) override;
	value_of_moves_with_cords all_posible_moves_with_value(Piece* board[8][8]) override;
	PieceType getPieceType() override { return King::_piecetype; }
};