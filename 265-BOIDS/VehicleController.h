#pragma once
#include "Vehicle.h"
class VehicleController
{
public:
	VehicleController(int s);
	~VehicleController();
	void update(float dt, int mode);
	void render(RenderWindow &w);
	void add(float x, float y);
	void remove();
	void alignment(float weight);
	void separation(float weight);
	void cohesion(float weight);
private:
	vector<Vehicle*> vehicles;
};

