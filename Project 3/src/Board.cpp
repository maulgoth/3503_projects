#include "Board.h"

Board::Board(unsigned int _width, unsigned int _height) {
    width = _width;
    height = _height;
}

Tile& Board::GetTile(unsigned int tile) {
	return board.at(tile);
}

unsigned int Board::GetWidth() {
    return width;
}

unsigned int Board::GetHeight() {
    return height;
}

unsigned int Board::GetSize() {
    return width * height;
}

void Board::ToggleDebug() {
    if (debug)
        debug = false;
    else
        debug = true;
    if (!gameOver && !victory) {
        for (unsigned int i = 0; i < GetSize(); i++) {
            if (debug && board.at(i).GetSecretState() == Tile::SecretState::MINE)
                board.at(i).SetSprite("mine");
            else if (!debug && board.at(i).GetState() == Tile::State::FLAGGED)
                board.at(i).SetSprite("flag");
            else if (!debug && board.at(i).GetSecretState() == Tile::SecretState::MINE)
                board.at(i).SetSprite("tile_hidden");
        }
    }
}

void Board::Initialize(int load_board) {
    // Read board file with mine info
    vector<char> bombs = Helpers::readFile(load_board);
    std::cout << "File loaded: " << bombs.size() << " tiles scanned." << std::endl;

    // Clear Board vector
    gameOver = false;
    victory = false;
    board.clear();
    mineCount = 0;
    flagCount = 0;

    // Create board vector of tiles. Each tile 32x32
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            sf::Vector2f position = sf::Vector2f((float)(j) * 32, (float)(i) * 32);
            Tile::SecretState sec_state;
            unsigned int x = (width * i) + j;
            if (bombs.at(x) == '1') {
                sec_state = Tile::SecretState::MINE;
                mineCount++;
            }
            else
                sec_state = Tile::SecretState::EMPTY;

            // Keep mines revealed if debug
            if (debug && sec_state == Tile::SecretState::MINE) {
                Tile temp = Tile(position, "mine", sec_state);
                board.push_back(temp);
            }
            else {
                Tile temp = Tile(position, "tile_hidden", sec_state);
                board.push_back(temp);
            }
        }
    }

    // Utilize Neighbor and Number Methods
    SetAllNeighbors();
    SetNeighborNumbers();
}

void Board::InitializeRandom() {

    // Generate random mine positions
    vector<int> randoMines;
    randoMines.push_back(Random::Int(0, 399));
    while (randoMines.size() < 50) {
        int x = Random::Int(0,399);
        bool dup = false;
        for (unsigned int i = 0; i < randoMines.size(); i++) {
            if (x == randoMines.at(i)) {
                dup = true;
                break;
            }
        }
        if (dup == false)
            randoMines.push_back(x);
    }

    // Initialize Board
    gameOver = false;
    victory = false;
    board.clear();
    mineCount = 0;
    flagCount = 0;

    // Create board vector of tiles. Each tile 32x32
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            sf::Vector2f position = sf::Vector2f((float)(j) * 32, (float)(i) * 32);
            Tile::SecretState sec_state = Tile::SecretState::EMPTY;
            Tile temp = Tile(position, "tile_hidden", sec_state);
            board.push_back(temp);
        }
    }

    // Set Bombs from Random List
    for (unsigned int i = 0; i < randoMines.size(); i++) {
        board.at(randoMines.at(i)).SetSecretState(Tile::SecretState::MINE);
        mineCount++;
        if (debug)
            board.at(randoMines.at(i)).SetSprite("mine");
    }

    // Utilize Neighbor and Number Methods
    SetAllNeighbors();
    SetNeighborNumbers();
}

bool Board::GetGameOver() {
    return gameOver;
}

void Board::SetGameOver() {
    gameOver = true;
        
    // Set all tiles to unclickable once game over

    for (unsigned int i = 0; i < board.size(); i++) {
        board.at(i).SetClickable(false);
        board.at(i).SetRightClickable(false);
        if (board.at(i).GetSecretState() == Tile::SecretState::MINE) {
            board.at(i).SetSprite("mine");
        }
    }
}

void Board::SetAllNeighbors() {
    for (unsigned int i = 0; i < board.size(); i++) {
        // Corners - 3 Neighbors ----------------------//
        // Top Left
        if (i == 0) {
            board.at(i).AddNeighbor(&board.at(1));
            board.at(i).AddNeighbor(&board.at(width));
            board.at(i).AddNeighbor(&board.at(width + 1));
        }
        // Top Right
        else if (i == width - 1) {
            board.at(i).AddNeighbor(&board.at(i - 2));
            board.at(i).AddNeighbor(&board.at(i * 2));
            board.at(i).AddNeighbor(&board.at((i * 2) + 1));
        }
        // Bottom Left
        else if (i == (width * height) - width) {
            board.at(i).AddNeighbor(&board.at(i - width));
            board.at(i).AddNeighbor(&board.at(i - width + 1));
            board.at(i).AddNeighbor(&board.at(i + 1));
        }
        // Bottom Right
        else if (i == (width * height) - 1) {
            board.at(i).AddNeighbor(&board.at(i - width));
            board.at(i).AddNeighbor(&board.at(i - width - 1));
            board.at(i).AddNeighbor(&board.at(i - 1));
        }

        // Edges - 5 Neighbors ----------------------//
        // Top Edge
        else if (i > 0 && i < width - 1) {
            board.at(i).AddNeighbor(&board.at(i - 1));
            board.at(i).AddNeighbor(&board.at(i + 1));
            board.at(i).AddNeighbor(&board.at(i + width - 1));
            board.at(i).AddNeighbor(&board.at(i + width));
            board.at(i).AddNeighbor(&board.at(i + width + 1));
        }
        // Bottom Edge
        else if (i > (width * height) - width && i < (width * height) - 1) {
            board.at(i).AddNeighbor(&board.at(i - width - 1));
            board.at(i).AddNeighbor(&board.at(i - width));
            board.at(i).AddNeighbor(&board.at(i - width + 1));
            board.at(i).AddNeighbor(&board.at(i - 1));
            board.at(i).AddNeighbor(&board.at(i + 1));
        }
        // Left Edge
        else if (i % width == 0) {
            board.at(i).AddNeighbor(&board.at(i + 1));
            board.at(i).AddNeighbor(&board.at(i + 1 - width));
            board.at(i).AddNeighbor(&board.at(i + 1 + width));
            board.at(i).AddNeighbor(&board.at(i + width));
            board.at(i).AddNeighbor(&board.at(i - width));
        }
        // Right Edge
        else if ((i + 1) % width == 0) {
            board.at(i).AddNeighbor(&board.at(i - 1));
            board.at(i).AddNeighbor(&board.at(i - width));
            board.at(i).AddNeighbor(&board.at(i + width));
            board.at(i).AddNeighbor(&board.at(i - 1 - width));
            board.at(i).AddNeighbor(&board.at(i - 1 + width));
        }

        // All Others - 8 Neighbors ----------------------//
        else {
            board.at(i).AddNeighbor(&board.at(i - 1));
            board.at(i).AddNeighbor(&board.at(i - 1 + width));
            board.at(i).AddNeighbor(&board.at(i - 1 - width));
            board.at(i).AddNeighbor(&board.at(i + 1));
            board.at(i).AddNeighbor(&board.at(i + 1 + width));
            board.at(i).AddNeighbor(&board.at(i + 1 - width));
            board.at(i).AddNeighbor(&board.at(i + width));
            board.at(i).AddNeighbor(&board.at(i - width));
        }
    }
}

void Board::SetNeighborNumbers() {
    for (unsigned int i = 0; i < board.size(); i++) {

        // Check if not mine
        if (!(board.at(i).GetSecretState() == Tile::SecretState::MINE)) {
            int count = 0;

            // Check each neighbor for mines, incrementing count
            for (unsigned int j = 0; j < board.at(i).GetNeighborCount(); j++) {
                Tile* t = board.at(i).GetNeighbor(j);
                if (t->GetSecretState() == Tile::SecretState::MINE)
                    count++;
            }

            // Set numbers
            if (count == 1)
                board.at(i).SetSecretState(Tile::SecretState::ONE);
            else if (count == 2)
                board.at(i).SetSecretState(Tile::SecretState::TWO);
            else if (count == 3)
                board.at(i).SetSecretState(Tile::SecretState::THREE);
            else if (count == 4)
                board.at(i).SetSecretState(Tile::SecretState::FOUR);
            else if (count == 5)
                board.at(i).SetSecretState(Tile::SecretState::FIVE);
            else if (count == 6)
                board.at(i).SetSecretState(Tile::SecretState::SIX);
            else if (count == 7)
                board.at(i).SetSecretState(Tile::SecretState::SEVEN);
            else if (count == 8)
                board.at(i).SetSecretState(Tile::SecretState::EIGHT);

            // Else, set to empty
            else
                board.at(i).SetSecretState(Tile::SecretState::EMPTY);
        }
    }
}

void Board::RevealTile(Tile* tile) {
    bool end = tile->Reveal();
    if (end)
        SetGameOver();
}

bool Board::GetVictory() {
    int count = 0;
    for (unsigned int i = 0; i < GetSize(); i++) {
        if (board.at(i).GetState() == Tile::State::REVEALED)
            count++;
    }
    if (GetSize() - count - mineCount == 0) {
        for (unsigned int i = 0; i < board.size(); i++) {
            board.at(i).SetClickable(false);
            board.at(i).SetRightClickable(false);
            if (board.at(i).GetSecretState() == Tile::SecretState::MINE) {
                board.at(i).SetSprite("flag");
            }
        }
        victory = true;
        return true;
    }
    return false;
}

int Board::GetFlagCount() {
    flagCount = 0;
    for (unsigned int i = 0; i < GetSize(); i++) {
        if (board.at(i).GetState() == Tile::State::FLAGGED)
            flagCount++;
    }
    return flagCount;
}

int Board::GetMineCount() {
    return mineCount;
}