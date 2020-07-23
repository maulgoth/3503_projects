#include "Board.h"

Board::Board(int _width, int _height) {
    width = _width;
    height = _height;
}

Tile& Board::GetTile(int tile) {
	return board.at(tile);
}

int Board::GetWidth() {
    return width;
}

int Board::GetHeight() {
    return height;
}

void Board::Initialize() {
    for (float i = 0; i < height; i++) {
        for (float j = 0; j < width; j++) {
            sf::Vector2f position = sf::Vector2f(j*32, i*32);
            Tile temp = Tile(position, "tile_hidden");
            board.push_back(temp);
        }
    }
}

int Board::GetSize() {
    return width * height;
}