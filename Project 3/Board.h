#pragma once
#include "Tile.h"
#include "TextureManager.h"
//#include "SFML/Graphics.hpp"
#include <vector>
using std::vector;

class Board
{
private:
	vector<Tile> board;
	int width;
	int height;
public:
	Tile& GetTile(int tile);
	Board(int _width, int _height);
	int GetWidth();
	int GetHeight();
	int GetSize();
	void Initialize();
};

