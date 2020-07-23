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
	bool clickable;
	bool gameOver;
public:
	enum class State { HIDDEN, REVEALED, FLAGGED };
	State state;
	State GetState();
	enum class SecretState { EMPTY, MINE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, FLAG };
	SecretState secret_state;
	SecretState GetSecretState();
	Tile(sf::Vector2f _position, const char* texture, SecretState sec_state);
	sf::Sprite& GetSprite();
	void SetState(State state_change);
	void SetSprite(const char* texture);
	bool Reveal();
	void SetClickable(bool t_or_f);
	void ToggleFlag();
	void SetGameOver();
};

