#pragma once

#include "Camera.h"

using namespace sf;
using namespace std;

class Player {    
public:
	
	Camera view;
	Texture texture;
	Sprite player;
	string path = "./img/player.png";

	Vector2f pos;
	Vector2f dir;
	Vector2f normDir;
	
	float drag = 0.1;
	float accel = 0.1;
	float maxSpeed = 2;

	float up = 0;
	float down = 180;
	float left = -90;
	float right = 90;
	int width = texture.getSize().x / 2;
	int height = texture.getSize().y / 2;

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

		view.setCenter(player.getPosition());

		if (Keyboard::isKeyPressed(Keyboard::W)){
			if (abs(dir.y) < maxSpeed)
			{
				dir.y -= accel;
			}			
			
			player.setRotation(up);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)){			
			if (abs(dir.y) < maxSpeed)
			{
				dir.y += accel;
			}			

			player.setRotation(down);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)){
			if (abs(dir.x) < maxSpeed)
			{
				dir.x -= accel;
			}

			player.setRotation(left);
		}
		if (Keyboard::isKeyPressed(Keyboard::D)){
			if (abs(dir.x) < maxSpeed)
			{
				dir.x += accel;
			}
			player.setRotation(right);
		}

		if (dir.x > 0)
		{
			dir.x -= drag;
		}
		if (dir.x < 0)
		{
			dir.x += drag;
		}
		if (dir.y > 0)
		{
			dir.y -= drag;
		}
		if (dir.y < 0)
		{
			dir.y += drag;
		}
		
		double hyp = sqrt(dir.x * dir.x + dir.y * dir.y);

		//cout << "x: " << dir.x / hyp << ", y: " << dir.y / hyp << endl;
		
		//normDir.x = dir.x / hyp;
		//normDir.y = dir.y / hyp;

		//pos += normDir;

		pos += dir;

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

	template <class T>
	void shoot(vector <T> enemies) {
		Vector2f enemyPos;
		Vector2f distanceVector;

		float distance;
		for (int i = 0; i < enemies.size(); i++)
		{
			enemyPos = enemies[i].getPos();
			distanceVector = enemyPos - this->pos;
			distance = sqrt(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

			if (distance < 25)
			{
				//shoot
			}
		}
	}

};

