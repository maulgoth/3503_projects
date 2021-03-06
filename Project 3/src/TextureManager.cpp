// ****************************************************//
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online //
// This code comes from Professor Joshua Fox         //
// *************************************************//

#include "TextureManager.h"

unordered_map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(const char* fileName) 
{
	string filePath = "images/";
	filePath += fileName;
	filePath += ".png";

	textures[fileName].loadFromFile(filePath);
}

sf::Texture& TextureManager::GetTexture(const char* textureKey)
{
	if (textures.find(textureKey) == textures.end()) { // If key doesn't exist:
		LoadTexture(textureKey); // Then load it
	}

	return textures[textureKey]; // Otherwise, return it
}

void TextureManager::Clear()
{
	textures.clear();
}