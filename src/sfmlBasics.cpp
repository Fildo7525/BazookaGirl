#include "sfmlBasics.h"

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello world", sf::Style::Default);

sf::Texture skyTexture;
sf::Texture bgTexture;
sf::Texture heroTexture;
sf::Sprite skySprite;
sf::Sprite bgSprite;
sf::Sprite heroSprite;

void init()
{
	skyTexture.loadFromFile("../Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("../Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);

	heroTexture.loadFromFile("../Assets/graphics/hero.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setPosition(viewSize.x/2, viewSize.y/2);
	heroSprite.setOrigin(heroTexture.getSize().x/2., heroTexture.getSize().y/2.);
}

void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(heroSprite);
}

