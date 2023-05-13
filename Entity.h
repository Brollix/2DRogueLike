#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Entity
{
public:
	//Sprite sprite;
	//Texture texture;
	//string path;
	Vector2f pos;
	unsigned long maxHealth = 100;
	unsigned long currentHealth = 100;
	unsigned long damage = 1;

};