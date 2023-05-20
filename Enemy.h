#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"	
#include "Player.h"

using namespace std;
using namespace sf;

class Enemy
{
public:
	Vector2f pos;
	Vector2f dir;

	FloatRect* bounds = new FloatRect;
	RectangleShape* bound = new RectangleShape;

	Texture* texture = new Texture;
	Sprite* enemy = new Sprite;
	
	string path = "./img/enemies/Enemy_1.png";

	float speed = 2;
	int Enemywidth = texture->getSize().x / 2;
	int Enemyheight = texture->getSize().y / 2;

	Enemy(){
		if (texture->loadFromFile(path)){			
			enemy->setTexture(*texture);

			enemy->setOrigin(
				Vector2f(
					texture->getSize().x / 2,
					texture->getSize().y / 2
				));

			enemy->setScale(0.1, 0.1);
		}
	}
	
	void render(RenderWindow& window)
	{
		window.draw(*enemy);
	}

	Vector2f getPos() {
		return enemy->getPosition();
	}

	void setPos(Vector2f pos)
	{
		enemy->setPosition(pos);
		bound->setPosition(pos);
	}

	FloatRect getBounds() {
		return enemy->getLocalBounds();
	}

	void moveToPlayer(Vector2f playerpos)
	{
		float hyp;

		dir.x = playerpos.x - enemy->getPosition().x;
		dir.y = playerpos.y - enemy->getPosition().y;

		hyp = sqrt( (dir.x * dir.x) + (dir.y * dir.y) );
		dir.x /= hyp;
		dir.y /= hyp;
		pos = enemy->getPosition();
		pos.x += dir.x * speed;
		pos.y += dir.y * speed;

		enemy->setPosition(pos);
	}
	Vector2u getSize() {
		return texture->getSize();
	}
};

