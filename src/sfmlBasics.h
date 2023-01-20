#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Window/WindowStyle.hpp>

extern sf::Vector2f viewSize;
extern sf::VideoMode vm;
extern sf::RenderWindow window;

extern sf::Texture skyTexture;
extern sf::Sprite skySprite;

void init();
void draw();

class sfmlBasics
{
public:
	sfmlBasics() = default;

};

