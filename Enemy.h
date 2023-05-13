#pragma once
#include <SFML/Graphics.hpp>
#include "ctime"		
#include "Entity.h"	
#include "Player.h"

using namespace std;
using namespace sf;

class Enemy
{
public:
	RectangleShape enemy;
	float enemyspawntimer;
	float enemyspawntimermax;
	int enemyspawnmax;
	int enemyspawnnumber;
	Vector2f pos;
	Vector2f dir;
	float speed = 2;
	float hyp;

	Enemy()
	{
		this->enemy.setSize(Vector2f(40.f, 50.f));
		this->enemy.setFillColor(Color::Red);
		this->enemy.setOutlineColor(Color::Red);
		this->enemy.setOutlineThickness(1.f);
	}
	int random()
	{

		srand(static_cast<unsigned>(time(NULL)));
	}
	void render(RenderWindow& window)
	{
		window.draw(enemy);
	}
	void setPosition(Vector2f pos)
	{
		enemy.setPosition(pos);
	}
	void moveToPlayer(Vector2f playerpos)
	{
		dir.x = playerpos.x - enemy.getPosition().x;
		dir.y = playerpos.y - enemy.getPosition().y;

		hyp = sqrt(dir.x * dir.x + dir.y * dir.y);
		dir.x /= hyp;
		dir.y /= hyp;
		pos = enemy.getPosition();
		pos.x += dir.x * speed;
		pos.y += dir.y * speed;

		enemy.setPosition(pos);
	}
};

