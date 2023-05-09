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

	Player player;

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
			view.move(0, -player.speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			moving = true;
			view.move(0, player.speed);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			moving = true;
			view.move(-player.speed, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
			moving = true;
			view.move(player.speed, 0);
		}
		
		window.setView(view.camera);
		
		window.clear();

		player.render(window);

		window.display();
	}
	return 0;
}