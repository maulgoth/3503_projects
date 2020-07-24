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
	unsigned int width;
	unsigned int height;
	bool debug = false;
	bool gameOver = false;
public:
	// Constructor
	Board(int _width, int _height);

	// Initial Methods
	void Initialize(int board);
	void InitializeRandom();

	// Getters
	Tile& GetTile(int tile);
	int GetWidth();
	int GetHeight();
	unsigned int GetSize();
	bool GetGameOver();

	// Setters
	void SetAllNeighbors();
	void SetNeighborNumbers();
	
	// Modes
	void ToggleDebug();
	void SetGameOver();

};
