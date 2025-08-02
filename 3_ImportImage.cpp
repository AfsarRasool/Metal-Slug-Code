#include<sfml/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "First Project");

	Event event;
/*.......................................MAP......................................*/
	Texture texture;
	texture.loadFromFile("resources/level1.png");

        // Calculation to adjust Background within the boundries
	float MapX = static_cast<float>(window.getSize().x) / (texture.getSize().x);
	float MapY = static_cast<float>(window.getSize().y) / (texture.getSize().y);

	Sprite sprite(texture);
	sprite.setScale(MapX, MapY);
/*........................................MAP......................................*/


	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}

		window.draw(sprite);
		window.display();

	}
}