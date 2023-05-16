#include <iostream>

#include <stdlib.h>
#include <time.h> 

#include <SFML/Graphics.hpp>

#include "Background.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

const float pi = 3.14159265359;

int randInt(int a, int b)
{
	return rand() % b + a;
}

int main() { 
	srand(time(NULL));

	float width = 1280;
	float height = 720;

	RenderWindow window(VideoMode(width, height), "SFML works!");
	window.setVerticalSyncEnabled(true);

	Background background;
	background.setScale(2);
	background.setPosition(Vector2f(width / 2, height / 2));

	Enemy enemy; 

	Player player;
	player.setScale(0.1, 0.1);
	player.setPosition(Vector2f(width / 2, height / 2));

	vector <Enemy>enemies;
	enemies.push_back(enemy);

	Clock clock;
	Clock fpsClock;
	Clock shootingClock;
	Clock spawnClock;
	float spawnTime = 0;
	float spawnCooldown = 1;

	float top = background.background.getGlobalBounds().top;
	float down = background.background.getGlobalBounds().height;
	float left = background.background.getGlobalBounds().left;
	float right = background.background.getGlobalBounds().width;

	cout << 
		"x1: " << left <<
		", x2: " << right <<
		", y1: " << top << 
		", y1: " << down << 
		endl;

	while (window.isOpen()){

		Event event;
		while (window.pollEvent(event)){			
			switch (event.type){
				case Event::Closed:
					window.close();
					break;
			}
		}		
		
		window.setView(player.view.camera);
		
		player.move();
		window.clear();

		background.render(window);

		player.render(window);
		
		float time = clock.getElapsedTime().asSeconds();
		float random = 25 + (rand() % (int)width - 25);
		float currentTime = fpsClock.restart().asSeconds();
		float fps = 1 / currentTime;
		

		spawnTime = spawnClock.getElapsedTime().asSeconds();
		if (spawnTime >= spawnCooldown) {
			Enemy enemy;
			enemy.setPos(Vector2f (randInt(left, right), randInt(top, down)));
			enemies.push_back(enemy);
			spawnClock.restart();
		}
		
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].render(window);
			enemies[i].moveToPlayer(player.getPosition());
		}
		
		}		

		window.display();
	}
	return 0;
}

