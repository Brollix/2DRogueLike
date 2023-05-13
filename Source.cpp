#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

using namespace std;
using namespace sf;

int main()
{
	float width = 1280;
	float height = 720;

	RenderWindow window(VideoMode(width, height), "SFML works!");
	window.setVerticalSyncEnabled(true);

	Background background;
	background.setScale(2.5);
	background.setPosition(Vector2f(width / 2, height / 2));

	Enemy enemy; 

	Player player;
	player.setScale(0.1, 0.1);
	player.setPosition(Vector2f(width / 2, height / 2));

	//cout <<
	//	"x: " << player.player.getTexture()->getSize().x <<
	//	", y: " << player.player.getTexture()->getSize().y << endl;

	vector <Enemy>enemies;
	enemies.push_back(enemy);
	cout << enemies.size()<<endl;

	Clock clock;
	Clock fpsClock;
	Clock shootingClock;
	Clock spawnClock;
	float spawnTime = 0;
	float spawnCooldown = 1;

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
			enemy.setPosition(Vector2f (rand()% (int)width, rand() % (int)height));
			enemies.push_back(enemy);
			spawnClock.restart();
			cout << "enemy spawn" << endl;

		}
		for (size_t i = 0; i < enemies.size(); i++)
		{
			enemies[i].render(window);
			enemies[i].moveToPlayer(player.getPosition());
		}

		window.display();
		player.move();
	}
	return 0;
}

