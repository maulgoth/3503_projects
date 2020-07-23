#include "Tile.h"

Tile::Tile(sf::Vector2f _position, const char* texture, SecretState sec_state) {
	sprite = sf::Sprite(TextureManager::GetTexture(texture));
	sprite.setPosition(_position.x, _position.y);
	position = _position;
	state = State::HIDDEN;
	secret_state = sec_state;
}

Tile::State Tile::GetState() {
	if (state == State::HIDDEN) {
		std::cout << "HIDDEN. ";
	}
	else if (state == State::REVEALED && !revealed) {
		std::cout << "REVEALED!" << std::endl;
		revealed = true;
	}
	else if (!revealed)
		std::cout << "Error getting state! ";
	return state;
}

Tile::SecretState Tile::GetSecretState() {
	if (secret_state == SecretState::EMPTY && !scanned) {
		std::cout << "No Mine. ";
		scanned = true;
	}
	else if (secret_state == SecretState::MINE && !scanned) {
		std::cout << "MINE MINE MINE! ";
		scanned = true;
	}
	else if (!scanned)
		std::cout << "Error scanning for mine! ";
	return secret_state;
}

void Tile::SetState(State state_change) {
	state = state_change;
};

sf::Sprite& Tile::GetSprite() {
	return sprite;
}

void Tile::SetSprite(const char* texture) {
	sprite = sf::Sprite(TextureManager::GetTexture(texture));
	sprite.setPosition(position);
};

void Tile::Reveal() {
	if (state == State::HIDDEN) {
		state = State::REVEALED;
		if (secret_state == SecretState::MINE) {
			SetSprite("mine");
		}
		else {
			// EVENTUALLY THIS WILL TRACK THE STATE OF NUMBERS
			SetSprite("tile_revealed");
		}
	}
		
}