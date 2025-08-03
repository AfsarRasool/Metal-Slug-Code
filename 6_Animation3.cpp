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

	float MapX = static_cast<float>(window.getSize().x) / (texture.getSize().x);
	float MapY = static_cast<float>(window.getSize().y) / (texture.getSize().y);

	Sprite sprite(texture);
	sprite.setScale(MapX, MapY);
/*........................................MAP......................................*/

	// Whole Sprite sheet 
	Texture Character_Texture;
	Character_Texture.loadFromFile("resources/mainC.png");

/*..................................Inhaltion......................................*/
	Sprite Inhale[8];
		for (size_t i = 0; i < 4; i++)
		{
			Inhale[i].setTexture(Character_Texture);
			Inhale[i].setTextureRect(IntRect(308 + (i * 40), 20, 40, 40));
		}

		for (int i = 0; i < 4; i++) {
			Inhale[i + 4] = Inhale[4 - i - 1];
		}
		int i = 0;
		Clock inahleCLK;
/*....................................Inhaltion......................................*/


/*...............................Forward Movement.....................................*/
		//Forward walking 
	Sprite Walking[6];
	for (int i = 0; i < 6; i++)
	{
		Walking[i].setTexture(Character_Texture);
		Walking[i].setTextureRect(IntRect(308+(40*i), 1160, 40, 40));
	}
	//Backward walking 
	Sprite Backward_Walking[6];

	for (int i = 0; i < 6; i++)
	{
		Backward_Walking[i].setTexture(Character_Texture);
		Backward_Walking[i].setTextureRect(IntRect(308 -((i+1)*40), 1160, 40, 40));
	}

	int LeftIdx = 0;  // Backward walking Index
	int walkingIdx = 0;// Forward walking Index
	Clock walkingCLK;

/*...............................Forward Movement.....................................*/


	Sprite Animation;
	Animation.setPosition(20, 450);
	Vector2f position=Animation.getPosition();
	
	bool direction=true;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type==Event::KeyPressed && event.key.code==Keyboard::Right)
			{
				direction = true;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
			{
				direction = false;
			}
		}


		// Walking Animatio
		if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (walkingCLK.getElapsedTime().asMilliseconds()>90)
			{


				(direction) ? Animation = Walking[walkingIdx]:Animation=Backward_Walking[LeftIdx];

				(direction)?walkingIdx = (walkingIdx + 1) % 6:LeftIdx=(LeftIdx+1)%6;

				(direction) ? position.x = position.x + 10: position.x = position.x - 10;
				walkingCLK.restart();
			}
			
		}
		else  // Default Inhaltion
		{
			if (inahleCLK.getElapsedTime().asMilliseconds() > 90) {

				Animation = Inhale[i];
				i = (i + 1) % 8;
				inahleCLK.restart();

			}
		}
		

		Animation.setPosition(position);
		Animation.setScale(3, 3);


		window.draw(sprite);
		window.draw(Animation);
		window.display();

	}
}
