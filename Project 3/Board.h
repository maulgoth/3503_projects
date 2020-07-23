#pragma once
#include "TextureManager.h"
#include "Tile.h"
#include "Helpers.h"
#include <vector>
using std::vector;

class Board
{
private:
	int mineCount;
	vector<Tile> board;
	int width;
	int height;
	bool debug = false;
	bool gameOver = false;
public:
	Tile& GetTile(int tile);
	Board(int _width, int _height);
	int GetWidth();
	int GetHeight();
	int GetSize();
	//void Initialize(vector<char>& bombs);
	void Initialize(int board);
	void ToggleDebug();
	bool GetGameOver();
	void SetGameOver();
};
