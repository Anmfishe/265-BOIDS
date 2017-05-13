#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace sf;
class Vehicle
{
public:
	float get_length(Vector2f v);
	Vector2f normalize(Vector2f v);
	float get_random_range(float min, float max);
	Vehicle(float x, float y);
	~Vehicle();
	
	void update(float dt);
	
	void render(RenderWindow &w)
	{
		w.draw(shape);
	};
	Vector2f getPos()
	{
		return shape.getPosition();
	};
	Vector2f velocity;
	Vector2f accel;
private:
	RectangleShape shape;
	Texture tex;
	float radius = 10;
	float speed = 4;
	float clamp = 100;

	
};

