#pragma once

#include "Hero.hpp"
#include "Enemy.hpp"

#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/WindowStyle.hpp>

extern sf::Vector2f viewSize;
extern sf::VideoMode vm;
extern sf::RenderWindow window;

extern sf::Texture skyTexture;
extern sf::Sprite skySprite;

extern std::vector<std::shared_ptr<Enemy>> enemies;

void init();
void draw();
void updateInput();
void update(float dt);
void spawnEnemy();

