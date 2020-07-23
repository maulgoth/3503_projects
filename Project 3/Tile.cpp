#include "Tile.h"

Tile::Tile(sf::Vector2f _position, const char* texture) {
	sprite = sf::Sprite(TextureManager::GetTexture(texture));
	sprite.setPosition(_position.x, _position.y);
	position = _position;
	state = State::HIDDEN;
	secretState = SecretState::EMPTY;
}

Tile::State Tile::GetState() {
	if (state == State::HIDDEN) {
		std::cout << "HIDDEN, okay?" << std::endl;
	}
	else if (state == State::REVEALED && !revealed) {
		std::cout << "REVEALED, truly!" << std::endl;
		revealed = true;
	}
	else if (!revealed)
		std::cout << "Not sure, something else!" << std::endl;
	return state;
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
	if (state == State::HIDDEN)
		state = State::REVEALED;
}