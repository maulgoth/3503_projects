#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "TextureManager.h"
using std::string;
using std::vector;


class Tile
{
private:
	sf::Vector2f position;
	vector<Tile*> adjacentTiles;
	sf::Sprite sprite;
	bool revealed = false;
	enum class SecretState { EMPTY, MINE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT };
	SecretState secretState;
	enum class State { HIDDEN, REVEALED };
	State state;
public:
	State GetState();
	Tile(sf::Vector2f _position, const char* texture);
	sf::Sprite& GetSprite();
	void SetState(State state_change);
	void SetSprite(const char* texture);
	void Reveal();
};

