#pragma once

using namespace sf;
using namespace std;

class Background
{
public:
	Texture texture;
	Sprite background;
	string path = "./img/map.png";

	Background() {
		if (texture.loadFromFile(path))
		{
			background.setTexture(texture);

			background.setOrigin(
				Vector2f(
					texture.getSize().x / 2,
					texture.getSize().y / 2
				));
		}
	};

	void setPosition(Vector2f pos) {
		background.setPosition(pos);
	}

	void setScale(float factor) {
		background.setScale(Vector2f(factor, factor));
	}

	void render(RenderWindow& window) {
		window.draw(background);
	}

	
};

