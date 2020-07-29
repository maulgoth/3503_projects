// ***************************************************** //
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online   //
// All code completely original,					   //
// Inspired by Professor Joshua Fox's lectures,       //
// Or from previous COP3503 Projects and Labs        //
// *************************************************//

#pragma once
#include <iostream>
#include <vector>
#include "TextureManager.h"
using std::string;
using std::vector;


class Tile
{
private:
	sf::Vector2f position;
	vector<Tile*> neighbors;
	sf::Sprite sprite;
	bool clickable;
	bool right_clickable;
public:
	// State
	enum class State { HIDDEN, REVEALED, FLAGGED };
	State state;
	State GetState();
	void SetState(State state_change);
	enum class SecretState { EMPTY, MINE, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, FLAG };
	SecretState secret_state;
	SecretState GetSecretState();
	void SetSecretState(SecretState secret_state_change);

	// Constructor
	Tile(sf::Vector2f _position, const char* texture, SecretState sec_state);

	// Getters
	sf::Sprite& GetSprite();
	Tile* GetNeighbor(unsigned int _neighbor);

	// Setters
	void SetClickable(bool t_or_f);
	void SetRightClickable(bool t_or_f);
	void SetSprite(const char* texture);

	// Methods
	bool Reveal();
	void ToggleFlag();
	unsigned int GetNeighborCount();
	void AddNeighbor(Tile* _neighbor);
};

