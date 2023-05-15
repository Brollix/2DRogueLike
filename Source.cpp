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

int random(int a, int b)
{
	srand(time(NULL));
	return rand() % b + a;
}

int main() { 

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

	float radius = (width / 2) + 100;
	vector<CircleShape> balls;
	
	for (int i = 0; i < (2 * pi)*10; i++)
	{
		CircleShape ball;
		int x = radius * cos(i);
		int y = radius * sin(i);

		ball.setPosition(x + width / 2, y + height / 2);
		ball.setRadius(2);
		balls.push_back(ball);
	}

	while (window.isOpen()){

		cout << (int)sqrt( pow(player.dir.x, 2) + pow(player.dir.y, 2)) << endl;

		Event event;
		while (window.pollEvent(event)){			
			switch (event.type){
				case Event::Closed:
					window.close();
					break;
			}
		}		
		
		window.setView(player.view.camera);
		
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
			enemy.setPos(Vector2f (rand()% (int)width/2, rand() % (int)height/2));
			enemies.push_back(enemy);
			spawnClock.restart();
		}
		
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].render(window);
			enemies[i].moveToPlayer(player.getPosition());
		}
		
		for (int i = 0; i < balls.size(); i++)
		{
			window.draw(balls[i]);
		}
		

		window.display();
		player.move();
	}
	return 0;
}

