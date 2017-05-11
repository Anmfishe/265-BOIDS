#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Vehicle.h"
#include "GameObject.h"
using namespace std;
using namespace sf;
void update_state(float dt)
{

}
void render_frame(RenderWindow &w)
{

}
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	Clock clock;
	Vehicle v;
	while (window.isOpen())
	{
		
		Event  event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			
		}

		float dt = clock.restart().asSeconds();
		update_state(dt);
		render_frame(window);
		window.display();
	}

	return 0;
}


