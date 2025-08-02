#include<sfml/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "First Project");

	Event event;

	Texture texture;
	texture.loadFromFile("resources/level1.png");

	float MapX = static_cast<float>(window.getSize().x) / (texture.getSize().x);
	float MapY = static_cast<float>(window.getSize().y) / (texture.getSize().y);
    // Map Sprite
      	Sprite sprite(texture);
	sprite.setScale(MapX, MapY);

	Texture Character_Texture;
	Character_Texture.loadFromFile("resources/mainC.png");

      // Inhalation Animation
	Sprite Inhale[8];
		for (size_t i = 0; i < 4; i++)
		{
			Inhale[i].setTexture(Character_Texture);
			Inhale[i].setTextureRect(IntRect(308 + (i * 40), 20, 40, 40));
		}

		for (int i = 0; i < 4; i++) {
			Inhale[i + 4] = Inhale[4 - i - 1];
		}
	
		
	
        int inhale_idx = 0;
	Clock inahleCLK;



        Sprite Animation;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

		}
		if (inahleCLK.getElapsedTime().asMilliseconds()>90) {

		Animation = Inhale[inhale_idx];
		inhale_idx=inhale_idx (inhale_idx + 1) % 8;
		inahleCLK.restart();

		}

		Animation.setPosition(20, 450);
		Animation.setScale(3, 3);


		window.draw(sprite);
		window.draw(Animation);
		window.display();

	}
}
