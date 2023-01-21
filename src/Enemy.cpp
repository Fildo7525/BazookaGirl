#include "Enemy.hpp"
#include <SFML/Graphics/Texture.hpp>

Enemy::Enemy(const std::string &textureName, sf::Vector2f position, float velocity)
	: m_position(position)
	, m_velocity(velocity)
{
	init(textureName, position);
}

void Enemy::init(const std::string &textureName, sf::Vector2f position)
{
	m_texture.loadFromFile(textureName);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x/2., m_texture.getSize().y/2.);
	m_sprite.setPosition(m_position);
}

void Enemy::update(float dt)
{
	m_sprite.move(m_velocity * dt, 0);
}

sf::Sprite Enemy::getSprite()
{
	return m_sprite;
}

