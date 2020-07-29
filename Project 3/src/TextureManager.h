// ****************************************************//
// Jeremy DePoyster - COP3503 Summer 2020 - UF Online //
// This code comes from Professor Joshua Fox         //
// *************************************************//

#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
using std::unordered_map;
using std::string;


class TextureManager
{
	static unordered_map<string, sf::Texture> textures;
	static void LoadTexture(const char* fileName);
public:
	static sf::Texture& GetTexture(const char* textureKey);
	static void Clear(); 
};