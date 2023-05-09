#include <SFML/Graphics.hpp>
#include <iostream>

#include "Background.h"
#include "Player.h"


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

	Player player;
	player.setScale(0.1, 0.1);
	player.setPosition(Vector2f(width / 2, height / 2));

	cout <<
		"x: " << player.player.getTexture()->getSize().x <<
		", y: " << player.player.getTexture()->getSize().y << endl;

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

		

		window.display();
		player.move();
	}
	return 0;
}