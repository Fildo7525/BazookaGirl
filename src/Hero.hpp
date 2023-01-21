#pragma once

#include <SFML/Graphics.hpp>
#include <string>

constexpr float gravity = 9.81f;

class Hero
{
public:
	Hero(const std::string &textureName, sf::Vector2f position, float mass);

	void init(const std::string &textureName, sf::Vector2f position);
	void update(float dt);
	void jump(float velocity);
	sf::Sprite getSprite();
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	int m_jumpCout;
	float m_mass;
	float m_velocity;
	bool m_grounded;
};

