#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"


using namespace std;
using namespace sf;

int main()
{
	short width = 1280;
	short height = 720;
	RenderWindow window(VideoMode(width, height), "SFML works!");
	window.setVerticalSyncEnabled(true);

	Sprite sprite;
	Texture texture;

	texture.loadFromFile("img/map.png");

	sprite.setTexture(texture);

	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setPosition(width / 2, height / 2);
	sprite.scale(3, 3);

	Player player;

	int speed = 3;

	Camera view(width, height);

	while (window.isOpen()){
		Event event;
		while (window.pollEvent(event)){			
			switch (event.type){
				case Event::Closed:
					window.close();
					break;

				case Event::MouseWheelMoved:					
					if (event.mouseWheel.delta > 0) {
						view.zoom(0.9);
					}
					if (event.mouseWheel.delta < 0) {
						view.zoom(1.1);
					}	
			}
		}

		bool moving = false;

		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
			moving = true;
			view.move(player.getPosition().x, player.getPosition().y);
			cout << "x: " << player.getPosition().x << ", y:" << player.getPosition().y << endl;
		}/*
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			moving = true;
			view.move(0, speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			moving = true;
			view.move(-speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
			moving = true;
			view.move(speed, 0);
		}
		*/
		window.setView(view.camera);
		
		window.clear();

		window.draw(sprite);
		player.render(window);

		window.display();
	}
	return 0;
}