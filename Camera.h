#pragma once
using namespace sf;
class Camera
{
public:

	View camera; 
	Camera() {};
	Camera(float windowWidth, float windowHeight){
		camera.setSize(Vector2f(windowWidth, windowHeight));
		camera.setCenter(Vector2f(windowWidth / 2, windowHeight / 2));
	}

	void zoom(float zoom) {
		camera.zoom(zoom);
	}
	void move(float x, float y) {
		camera.move(x, y);
	}
	void setCenter(Vector2f pos) {
		camera.setCenter(pos);
	}
};

