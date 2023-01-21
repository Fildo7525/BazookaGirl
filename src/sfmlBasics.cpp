#include "sfmlBasics.h"
#include "Hero.hpp"

#include <memory>

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello world", sf::Style::Default);

sf::Texture skyTexture;
sf::Texture bgTexture;
sf::Sprite skySprite;
sf::Sprite bgSprite;

std::shared_ptr<Hero> hero;

void init()
{
	skyTexture.loadFromFile("../Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("../Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);

	hero = std::make_shared<Hero>("../Assets/graphics/hero.png", sf::Vector2f(viewSize.x* 0.25, viewSize.y *0.5), 200);
}

void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(hero->getSprite());
}

void updateInput()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				hero->jump(750);
			}
		}
		if (event.type == sf::Event::Closed
			|| event.key.code == sf::Keyboard::Escape
			|| event.key.code == sf::Keyboard::Q) {
			window.close();
		}
	}
}

void update(float dt)
{
	hero->update(dt);
}

