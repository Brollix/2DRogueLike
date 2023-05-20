#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"	
#include "Player.h"
#include "Enemy.h"

class Collision
{
public:
	

	void checkCollisions(Player player, Enemy enemy, Enemy texture) {
		Vector2f enemypos= enemy.getPos();
		Vector2f playerpos = player.getPosition();
		Vector2u enemysize = texture.getSize();
		int enemyheight = enemysize.y;
		int enemywidht = enemysize.x;
		int height = player.height.y;
		int width = player.width.x;
			

		if (playerpos.x < enemypos.x + enemywidht &&
			playerpos.x + width > enemypos.x &&
			playerpos.y < enemypos.y + enemyheight &&
			playerpos.y + height > enemypos.y) {

			cout << "crash" >> endl; }

	};
	
	
};

