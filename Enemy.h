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
	Vector2f playerpos;
	RectangleShape enemy;
	float enemyspawntimer;
	float enemyspawntimermax;
	int enemyspawnmax;
	int enemyspawnnumber;

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
	void getPlayerPosition(Player player)
	{
		this->playerpos = player.getPosition();
	}
	void setPosition(Vector2f pos)
	{
		enemy.setPosition(pos);
	}
	void enemymove()
	{

	}
};

