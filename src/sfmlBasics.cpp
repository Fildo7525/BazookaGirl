#include "sfmlBasics.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>

sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello world", sf::Style::Default);
int score = 0;
bool gameover = true;

sf::Font headingFont;
sf::Text heading;

sf::Texture skyTexture;
sf::Texture bgTexture;
sf::Sprite skySprite;
sf::Sprite bgSprite;

std::shared_ptr<Hero> hero;
std::vector<std::shared_ptr<Enemy>> enemies;
std::vector<std::shared_ptr<Rocket>> rockets;

float currentTime{};
float prevTime = 0.0f;

void init()
{
	skyTexture.loadFromFile("../Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("../Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);

	headingFont.loadFromFile("../Assets/fonts/Bitstream Vera Sans Mono Nerd Font Complete.ttf");
	heading.setFont(headingFont);
	heading.setString("BazookaGirl");
	heading.setCharacterSize(84);
	heading.setFillColor(sf::Color::Red);
	sf::FloatRect headingBounds = heading.getLocalBounds();
	heading.setOrigin(headingBounds.width/2, headingBounds.height/2);
	heading.setPosition({viewSize.x/2.f, viewSize.y*0.1f});

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
	if (!gameover) {
		heading.setString("Score: " + std::to_string(score));
	} else {
		heading.setString("BazookaGirl");
	}
	window.draw(heading);

	if (rockets.size() > 0) {
		for(auto rocket : rockets) {
			// std::cout << "Drawing rocket at position [" << rocket->getSprite().getPosition().x << ", " << rocket->getSprite().getPosition().y << "]\n";
			window.draw(rocket->getSprite());
		}
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
			if (event.key.code == sf::Keyboard::Space) {
				if (gameover) {
					gameover = false;
					reset();
				}
				else {
					shoot();
				}
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

	for(int i = 0; i < enemies.size(); i++) {
		auto enemy = enemies[i];
		enemy->update(dt);
		if (enemy->getSprite().getPosition().x < 0) {
			enemies.erase(enemies.begin() + i);
			gameover = true;
		}
	}

	for(int i = 0; i < rockets.size(); i++) {
		auto rocket = rockets[i];
		rocket->update(dt);

		if (rocket->getSprite().getPosition().x >= viewSize.x) {
			rockets.erase(rockets.begin() + i);
		}
	}

	for (size_t i = 0; i < rockets.size(); i++) {
		for (size_t j = 0; j < enemies.size(); j++) {
			auto rocket = rockets[i];
			auto enemy = enemies[j];
			if (checkColision(rocket->getSprite(), enemy->getSprite())) {
				rockets.erase(rockets.begin() + i);
				enemies.erase(enemies.begin() + j);
				score += 1;
			}
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

void shoot()
{
	rockets.push_back(std::make_shared<Rocket>("../Assets/graphics/rocket.png", hero->getSprite().getPosition(), 400));
}

bool checkColision(const sf::Sprite lhs, const sf::Sprite &rhs)
{
	auto l = lhs.getGlobalBounds();
	auto r = rhs.getGlobalBounds();
	return l.intersects(r);
}

void reset()
{
	score = 0;
	currentTime = 0;
	prevTime = 0;
	enemies.clear();
	rockets.clear();
}

