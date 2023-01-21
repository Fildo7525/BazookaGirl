#include "Hero.hpp"
#include <SFML/Graphics/Texture.hpp>

Hero::Hero(const std::string &textureName, sf::Vector2f position, float mass)
	: m_jumpCout(0)
	, m_position(position)
	, m_mass(mass)
	, m_grounded(false)
	, m_velocity(0)
	, m_texture()
{
	init(textureName, position);
}

void Hero::init(const std::string &textureName, sf::Vector2f position)
{
	m_texture.loadFromFile(textureName);

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
	m_sprite.setOrigin(m_texture.getSize().x/2., m_texture.getSize().y/2.);
}

void Hero::update(float dt)
{
	m_velocity -= m_mass * gravity * dt;
	m_position.y -= m_velocity * dt;
	m_sprite.setPosition(m_position);

	if (m_position.y >= 768 * 0.75f) {
		m_position.y = 768 * 0.75f;
		m_velocity = 0;
		m_grounded = true;
		m_jumpCout = 0;
	}
}

void Hero::jump(float velocity)
{
	if (m_jumpCout < 2) {
		m_jumpCout++;
		m_velocity = velocity;
		m_grounded = false;
	}
}

sf::Sprite Hero::getSprite()
{
	return m_sprite;
}

