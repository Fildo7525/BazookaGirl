#include "sfmlBasics.h"

#include <cstdlib>
#include <ctime>

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello world", sf::Style::Default);

sf::Texture skyTexture;
sf::Texture bgTexture;
sf::Sprite skySprite;
sf::Sprite bgSprite;

std::shared_ptr<Hero> hero;
std::vector<std::shared_ptr<Enemy>> enemies;

float currentTime{};
float prevTime = 0.0f;

void init()
{
	skyTexture.loadFromFile("../Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("../Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);

	hero = std::make_shared<Hero>("../Assets/graphics/hero.png", sf::Vector2f(viewSize.x* 0.25, viewSize.y *0.5), 200);

	std::srand((int)time(NULL));
	spawnEnemy();
}

void draw()
{
	window.draw(skySprite);
	window.draw(bgSprite);
	window.draw(hero->getSprite());
	for(auto enemy : enemies) {
		window.draw(enemy->getSprite());
	}
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
	currentTime += dt;
	if (currentTime - prevTime >= 1.125) {
		spawnEnemy();
		prevTime = currentTime;
	}

	for(int i = 0; i != enemies.size(); i++) {
		auto enemy = enemies[i];
		enemy->update(dt);
		if (enemy->getSprite().getPosition().x < 0) {
			enemies.erase(enemies.begin() + i);
		}
	}
}

void spawnEnemy()
{
	int randomLocation = rand() % 3;
	sf::Vector2f enemyPos;
	float speed;

	switch (randomLocation) {
		case 0:
			enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.75);
			speed = -400;
			break;
		case 1:
			enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.60);
			speed = -550;
			break;
		case 2:
			enemyPos = sf::Vector2f(viewSize.x, viewSize.y * 0.40);
			speed = -600;
			break;
	}
	enemies.push_back(std::make_shared<Enemy>("../Assets/graphics/enemy.png", enemyPos, speed));
}

