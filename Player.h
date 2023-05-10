#pragma once

#include "Camera.h"

using namespace sf;
using namespace std;

class Player {    
public:

	Vector2f pos;
	Camera view;
	Texture texture;
	Sprite player;
	string path = "./img/player.png";
	Vector2f speed;
	float drag = 0.1;
	float accel = 0.2;
	float maxSpeed = 3;
	float up = 0;
	float down = 180;
	float left = -90;
	float right = 90;

	Player() {
		if (texture.loadFromFile(path))
		{
			player.setTexture(texture);

			player.setOrigin(
				Vector2f(
					texture.getSize().x / 2,
					texture.getSize().y / 2
				));
		}
	};

	
	void move() {
		float normSpeed = sqrt((speed.x * speed.x) + (speed.y * speed.y));
		if (Keyboard::isKeyPressed(Keyboard::W)){
			if (abs(speed.y) < maxSpeed)
			{
				speed.y -= accel;
				cout << "shold move up" << endl;
			}			
			
			player.setRotation(up);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)){			
			if (abs(speed.y) < maxSpeed)
			{
				speed.y += accel;
				cout << "shold move down" << endl;
			}			

			player.setRotation(down);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)){
			if (abs(speed.x) < maxSpeed)
			{
				speed.x -= accel;
				cout << "shold move left" << endl;
			}

			player.setRotation(left);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)){
			if (abs(speed.x) < maxSpeed)
			{
				speed.x += accel;
				cout << "shold move right" << endl;
			}
			player.setRotation(right);
		}
		if (speed.x > 0)
		{
			speed.x -= drag;
		}
		if (speed.x < 0)
		{
			speed.x += drag;
		}
		if (speed.y > 0)
		{
			speed.y -= drag;
		}
		if (speed.y < 0)
		{
			speed.y += drag;
		}

		view.setCenter(player.getPosition());
		pos += speed;
		player.setPosition(pos);
	}

	Vector2f getPosition() {
		return player.getPosition();
	}

	void setPosition(Vector2f pos) {
		player.setPosition(pos);
	}

	void setScale(float x, float y) {
		player.setScale(x, y);
	}

	void render(RenderWindow& window) {
		window.draw(player);
	}
};

