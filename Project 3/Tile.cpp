#include "Tile.h"

Tile::Tile(sf::Vector2f _position, const char* texture, SecretState sec_state) {
	sprite = sf::Sprite(TextureManager::GetTexture(texture));
	sprite.setPosition(_position.x, _position.y);
	position = _position;
	state = State::HIDDEN;
	secret_state = sec_state;
	gameOver = false;
	clickable = true;
}

Tile::State Tile::GetState() {
	return state;
}

Tile::SecretState Tile::GetSecretState() {
	return secret_state;
}

void Tile::SetState(State state_change) {
	state = state_change;
}

sf::Sprite& Tile::GetSprite() {
	return sprite;
}

void Tile::SetSprite(const char* texture) {
	sprite.setTexture(TextureManager::GetTexture(texture));
	sprite.setPosition(position);
}

bool Tile::Reveal() {
	if (clickable) {
		if (state == State::HIDDEN) {
			state = State::REVEALED;
			if (secret_state == SecretState::MINE) {
				SetSprite("mine");
				return true;
			}
			else {
				// EVENTUALLY THIS WILL TRACK THE STATE OF NUMBERS
				SetSprite("tile_revealed");
				return false;
			}
		}
	}
	std::cout << "Not clickable!" << std::endl;
	return false;
}

void Tile::SetClickable(bool t_or_f) {
	if (t_or_f == true)
		clickable = true;
	else if (t_or_f == false)
		clickable = false;
}

void Tile::ToggleFlag() {
	if (!gameOver) {
		if (state == State::HIDDEN) {
			clickable = false;
			state = State::FLAGGED;
			SetSprite("flag");
		}
		else if (state == State::FLAGGED) {
			clickable = true;
			state = State::HIDDEN;
			SetSprite("tile_hidden");
		}
		else if (state == State::REVEALED)
			std::cout << "Can't flag." << std::endl;
	}
	else
		std::cout << "Can't flag, game over" << std::endl;
}

void Tile::SetGameOver() {
	gameOver = true;
}
