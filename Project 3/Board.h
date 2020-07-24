#pragma once
#include "TextureManager.h"
#include "Tile.h"
#include "Helpers.h"
#include "Random.h"
#include <vector>
using std::vector;

class Board
{
private:
	int mineCount = 0;
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
	void Initialize(int board);
	void InitializeRandom();
	void ToggleDebug();
	bool GetGameOver();
	void SetGameOver();
	void SetAllNeighbors();
	void SetNeighborNumbers();
};
