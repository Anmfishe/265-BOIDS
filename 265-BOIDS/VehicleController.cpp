#include "VehicleController.h"

float distance(Vector2f a, Vector2f b)
{
	float distX = b.x - a.x;
	float distY = b.y - a.y;
	distX *= distX;
	distY *= distY;
	return sqrtf(distX + distY);
}
float get_length(Vector2f v)
{
	return sqrtf(v.x*v.x + v.y*v.y);
}
Vector2f normalize(Vector2f v)
{
	float length = get_length(v);
	if (length != 0)
	{
		v.x /= length;
		v.y /= length;
	}
	return v;
}
float dotproduct(Vector2f a, Vector2f b)
{
	return (a.x * b.x) + (a.y * b.y);
}
void VehicleController::alignment(float weight)
{
	for (auto &i : vehicles)
	{
		Vector2f v(0, 0);
		int neighborCount = 0;
		for (auto &j : vehicles)
		{
			if (&i != &j)
			{
				float d = distance(i->getPos(), j->getPos());
				if (d < 40 && d > 0)
				{
					v += j->velocity;
					neighborCount++;
				}
			}
		}
		if (neighborCount == 0) {

			i->accel += v;
		}
		else {
			v.x /= neighborCount;
			v.y /= neighborCount;
			v = normalize(v);
			v.x *= weight;
			v.y *= weight;
			i->accel += v;
		}
	}
}

void VehicleController::separation(float weight)
{
	for (auto &i : vehicles)
	{
		Vector2f v(0, 0);
		int neighborCount = 0;
		for (auto &j : vehicles)
		{
			if (&i != &j)
			{
				float d = distance(i->getPos(), j->getPos());
				if (d < 25 && d > 0)
				{
					Vector2f pt = normalize(j->getPos() - i->getPos());
					pt.x /= d;
					pt.y /= d;
					v += pt;
					neighborCount++;
				}
			}
		}
		if (neighborCount == 0) {

			i->accel = v;
		}
		else {
			v.x /= neighborCount;
			v.y /= neighborCount;		
			v.x *= weight;
			v.y *= weight;
			i->accel = v;
		}
	}
}

void VehicleController::cohesion(float weight)
{
	for (auto &i : vehicles)
	{
		Vector2f v(0, 0);
		int neighborCount = 0;
		for (auto &j : vehicles)
		{
			if (&i != &j)
			{
				float d = distance(i->getPos(), j->getPos());
				if (d < 40 && d > 0)
				{
					Vector2f pt = normalize(j->getPos() - i->getPos());
					pt.x /= d;
					pt.y /= d;
					v += pt;
					neighborCount++;
				}
			}
		}
		if (neighborCount == 0) {

			i->accel += v;
		}
		else {
			v.x /= neighborCount;
			v.y /= neighborCount;
			v.x *= weight;
			v.y *= weight;
			i->accel += v;
		}
	}
}

VehicleController::VehicleController(int s)
{
	for (int i = 0; i < s; i++)
	{
		vehicles.push_back(new Vehicle(400, 300));
	}
}


VehicleController::~VehicleController()
{
}

void VehicleController::update(float dt, int mode)
{
	/*separation(dt);
	alignment(dt);
	cohesion(dt);*/
	for (auto &i : vehicles)
	{
		i->update(dt);
	}
}

void VehicleController::render(RenderWindow & w)
{
	for (auto &i : vehicles)
	{
		i->render(w);
	}
}

void VehicleController::add(float x, float y)
{
	vehicles.push_back(new Vehicle(x, y));
}

void VehicleController::remove()
{
	if (vehicles.size() > 0)
	{
		vehicles.pop_back();
	}
}

