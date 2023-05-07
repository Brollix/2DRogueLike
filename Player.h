#pragma once

#include <SFML/Graphics.hpp>
#include "Camera.h"
using namespace sf;

class Player
{    
public:
	
	RectangleShape player;
	float speed = 3;

	Player() {		
		player.setSize(Vector2f(20, 20));
	};

	void render(RenderWindow& window) {
		window.draw(player);
	}

	void move(float x, float y) {
		player.setPosition(x, y);
	}
	void move(Vector2f move) {
		player.setPosition(move);
	}

	Vector2f getPosition() {
		return player.getPosition();
	}
};

