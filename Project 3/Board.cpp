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

void Board::Initialize(vector<char>& bombs) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sf::Vector2f position = sf::Vector2f((float)j*32, (float)i*32);
            Tile::SecretState sec_state;
            if (bombs.at(25 * i + j) == '1') {
                sec_state = Tile::SecretState::MINE;
            }
            else
                sec_state = Tile::SecretState::EMPTY;

            Tile temp = Tile(position, "tile_hidden", sec_state);
            board.push_back(temp);
        }
    }
}

int Board::GetSize() {
    return width * height;
}