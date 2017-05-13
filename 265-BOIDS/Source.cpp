
#include "VehicleController.h"
using namespace std;
using namespace sf;
VehicleController controller(0);
bool align = true;
bool separate = true;
bool cohese = true;
void update_state(float dt)
{

	if (separate)
		controller.separation(-12000);
	if (align)
		controller.alignment(2000);
	if (cohese)
		controller.cohesion(2500);
	
	controller.update(dt, 0);
}
void render_frame(RenderWindow &w)
{
	w.clear();
	controller.render(w);
}
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "ErMaGerd, Flerking!");
	Clock clock;
	
	while (window.isOpen())
	{
		
		Event  event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed 
				&& Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i localPosition = Mouse::getPosition(window);
				controller.add(localPosition.x, localPosition.y);
			}
			else if (event.type == Event::MouseButtonPressed
				&& Mouse::isButtonPressed(Mouse::Right))
			{
				controller.remove();
			}
			else if (event.type == Event::KeyPressed)
			{
				if (Keyboard::isKeyPressed(Keyboard::C))
				{
					cohese = !cohese;
				}
				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					separate = !separate;
				}
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					align = !align;
				}
			}

		}

		float dt = clock.restart().asSeconds();
		update_state(dt);
		render_frame(window);
		window.display();
	}

	return 0;
}


