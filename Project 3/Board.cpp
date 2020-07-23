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

int Board::GetSize() {
    return width * height;
}

void Board::ToggleDebug() {
    if (debug)
        debug = false;
    else
        debug = true;
    for (int i = 0; i < GetSize(); i++) {
        if (debug && board.at(i).GetState() == Tile::State::FLAGGED)
            board.at(i).SetSprite("flag");
        else if (debug && board.at(i).GetSecretState() == Tile::SecretState::MINE)
            board.at(i).SetSprite("mine");
        else if (!debug && board.at(i).GetSecretState() == Tile::SecretState::MINE)
            board.at(i).SetSprite("tile_hidden");
    }
}

void Board::Initialize(int load_board) {
    // Read board file with mine info
    vector<char> bombs = Helpers::readFile(load_board);
    std::cout << "File loaded: " << bombs.size() << " tiles scanned." << std::endl;

    // Clear Board vector
    gameOver = false;
    board.clear();
    mineCount = 0;

    // Create board vector of tiles. Each tile 32x32
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sf::Vector2f position = sf::Vector2f((float)(j) * 32, (float)(i) * 32);
            Tile::SecretState sec_state;
            int x = (width * i) + j;
            if (bombs.at(x) == '1') {
                sec_state = Tile::SecretState::MINE;
                mineCount++;
            }
            else
                sec_state = Tile::SecretState::EMPTY;
            Tile temp = Tile(position, "tile_hidden", sec_state);
            board.push_back(temp);
        }
    }
    std::cout << "Mine count: " << mineCount << std::endl;
}

bool Board::GetGameOver() {
    return gameOver;
}

void Board::SetGameOver() {
    gameOver = true;
        
    // Set all tiles to unclickable once game over
    for (unsigned int i = 0; i < board.size(); i++) {
        board.at(i).SetClickable(false);
        board.at(i).SetGameOver();
    }
}