#include "sfmlBasics.h"

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello world", sf::Style::Default);

sf::Texture skyTexture;
sf::Sprite skySprite;

void init()
{
	skyTexture.loadFromFile("../Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
}

void draw()
{
	window.draw(skySprite);
}

