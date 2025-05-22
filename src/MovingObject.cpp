#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject(sf::Vector2i pos, int speed, int pixelSizeX, int pixelSizeY, sf::Vector2i direction) : GameObject(pos, pixelSizeX, pixelSizeY), m_direction(direction)

{
}

void MovingObject::setDirection(const sf::Vector2i& direction)
{
	m_direction = direction;
}

void MovingObject::update(sf::Time time)
{
		m_rect.move(m_direction.x * m_rect.getSize().x , m_direction.y * m_rect.getSize().y);
}

sf::Vector2i MovingObject::getNextPosGrid() const
{
	return sf::Vector2i(getPosGrid().x + m_direction.x, getPosGrid().y + m_direction.y);
}

sf::Vector2i MovingObject::getPosGrid() const
{
	return sf::Vector2i(m_rect.getPosition().x / m_rect.getSize().x, m_rect.getPosition().y / m_rect.getSize().y);
}


