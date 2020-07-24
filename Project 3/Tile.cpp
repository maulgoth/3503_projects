#include "Tile.h"

Tile::Tile(sf::Vector2f _position, const char* texture, SecretState sec_state) {
	sprite = sf::Sprite(TextureManager::GetTexture(texture));
	sprite.setPosition(_position.x, _position.y);
	position = _position;
	state = State::HIDDEN;
	secret_state = sec_state;
	clickable = true;
	right_clickable = true;
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

void Tile::SetSecretState(SecretState secret_state_change) {
	secret_state = secret_state_change;
}

sf::Sprite& Tile::GetSprite() {
	return sprite;
}

void Tile::SetSprite(const char* texture) {
	sprite.setTexture(TextureManager::GetTexture(texture));
	sprite.setPosition(position);
}

bool Tile::Reveal() {
	// If clickable and mine, returns true
	
	if (clickable) {
		if (state == State::HIDDEN) {
			state = State::REVEALED;
			if (secret_state == SecretState::MINE) {
				SetSprite("mine");
				return true;
			}
			else if (secret_state == SecretState::ONE) {
				SetSprite("number_1");
				return false;
			}
			else if (secret_state == SecretState::TWO) {
				SetSprite("number_2");
				return false;
			}
			else if (secret_state == SecretState::THREE) {
				SetSprite("number_3");
				return false;
			}
			else if (secret_state == SecretState::FOUR) {
				SetSprite("number_4");
				return false;
			}
			else if (secret_state == SecretState::FIVE) {
				SetSprite("number_5");
				return false;
			}
			else if (secret_state == SecretState::SIX) {
				SetSprite("number_6");
				return false;
			}
			else if (secret_state == SecretState::SEVEN) {
				SetSprite("number_7");
				return false;
			}
			else if (secret_state == SecretState::EIGHT) {
				SetSprite("number_8");
				return false;
			}
			else {
				SetSprite("tile_revealed");
				for (unsigned int i = 0; i < GetNeighborCount(); i++)
					GetNeighbor(i)->Reveal();
				return false;
			}
		}
	}
	/*std::cout << "Not clickable!" << std::endl;*/
	return false;
}

void Tile::SetClickable(bool t_or_f) {
	if (t_or_f == true)
		clickable = true;
	else if (t_or_f == false)
		clickable = false;
}

void Tile::SetRightClickable(bool t_or_f) {
	if (t_or_f == true)
		right_clickable = true;
	else if (t_or_f == false)
		right_clickable = false;
}

void Tile::ToggleFlag() {
	if (right_clickable) {
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

unsigned int Tile::GetNeighborCount() {
	return neighbors.size();
}


void Tile::AddNeighbor(Tile* _neighbor) {
	neighbors.push_back(_neighbor);
}

Tile* Tile::GetNeighbor(int _neighbor) {
	return neighbors.at(_neighbor);
}