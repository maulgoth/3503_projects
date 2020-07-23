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
	bool scanned = false;
public:
	enum class State { HIDDEN, REVEALED };
	State state;
	State GetState();
	enum class SecretState { EMPTY, MINE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT };
	SecretState secret_state;
	SecretState GetSecretState();
	Tile(sf::Vector2f _position, const char* texture, SecretState sec_state);
	sf::Sprite& GetSprite();
	void SetState(State state_change);
	void SetSprite(const char* texture);
	void Reveal();
};

