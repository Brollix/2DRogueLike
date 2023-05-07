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
	unsigned long maxHealth;
	unsigned long currentHealth;
	unsigned long damage;
};

