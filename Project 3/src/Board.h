// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

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
	int flagCount = 0;
	vector<Tile> board;
	unsigned int width;
	unsigned int height;
	bool debug = false;
	bool gameOver = false;
	bool victory = false;
public:
	// Constructor
	Board(unsigned int _width, unsigned int _height);

	// Initial Methods
	void Initialize(int board);
	void InitializeRandom();

	// Getters
	Tile& GetTile(unsigned int tile);
	unsigned int GetWidth();
	unsigned int GetHeight();
	unsigned int GetSize();
	bool GetGameOver();
	bool GetVictory();
	int GetFlagCount();
	int GetMineCount();

	// Setters
	void SetAllNeighbors();
	void SetNeighborNumbers();
	
	// Modes
	void ToggleDebug();
	void SetGameOver();
	void RevealTile(Tile* tile);
	void ToggleFlag(Tile* tile);
};
