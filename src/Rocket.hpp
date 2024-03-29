#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Rocket
{
public:
	Rocket(const std::string &textureName, sf::Vector2f position, float velocity);

	void init(const std::string &textureName, sf::Vector2f position);
	void update(float dt);
	sf::Sprite getSprite();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	float m_velocity;
};

