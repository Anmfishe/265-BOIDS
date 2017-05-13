#include "Vehicle.h"
float Vehicle::get_length(Vector2f v)
{
	return sqrtf(v.x*v.x + v.y*v.y);
}
Vector2f Vehicle::normalize(Vector2f v)
{
	float length = get_length(v);
	if (length != 0)
	{
		v.x /= length;
		v.y /= length;
	}
	return v;
}
float Vehicle::get_random_range(float min, float max)
{
	float temp2 = (float)(rand() % 100) / 100;
	return min + (temp2 * (max - min));
}

Vehicle::Vehicle(float x, float y)
{
	tex.loadFromFile("triangle.png");
	
	shape.setSize(Vector2f(radius, radius*2));
	shape.setOrigin(radius / 2, radius);
	shape.setPosition(x, y);
	shape.setTexture(&tex);
	velocity.x = get_random_range(-1, 1);
	velocity.y = get_random_range(-1, 1);
	velocity = normalize(velocity);
	velocity.x *= clamp;
	velocity.y *= clamp;
	//accel = velocity;
}


Vehicle::~Vehicle()
{
}

void Vehicle::update(float dt)
{
	Vector2f pos = shape.getPosition();
	
	Vector2f tv = normalize(velocity);
	tv.x *= clamp;
	tv.y *= clamp;
	velocity = tv;
	
	velocity.x += accel.x * dt;
	velocity.y += accel.y * dt;
	pos.x += velocity.x * dt;
	pos.y += velocity.y * dt;
	if (pos.x > 800)
	{
		pos.x = 0;
	}
	if (pos.y > 600)
	{
		pos.y = 0;
	}
	if (pos.x < 0)
	{
		pos.x = 800;
	}
	if (pos.y < 0)
	{
		pos.y = 600;
	}
	shape.setPosition(pos);

	float angle = atan2f(velocity.y, velocity.x);
	shape.setRotation(angle * 180 / 3.14 + 90.0);
	accel = Vector2f(0, 0);
}
