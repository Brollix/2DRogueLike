#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Tile
{
public:
	bool walkable;
	Vector2f pos;
	Vector2f texture;
	Sprite sprite;

	Tile( );
};

