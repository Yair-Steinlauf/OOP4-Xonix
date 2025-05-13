#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject(sf::Vector2i pos, int speed, int pixelSizeX, int pixelSizeY, sf::Vector2i direction) : GameObject(pos, pixelSizeX, pixelSizeY), m_speed(speed), m_direction(direction)

{
}

void MovingObject::setDirection(const sf::Vector2i& direction)
{
	m_direction = direction;
}

void MovingObject::update(sf::Time time)
{
	// TODO: move faster and slower
	if (m_moveTimer < sf::Time(sf::microseconds(100))) {
		m_moveTimer += time;
	}
	else {
		m_rect.move(m_direction.x * m_rect.getSize().x , m_direction.y * m_rect.getSize().y);
		m_moveTimer = sf::microseconds(0);
	}
	

	//std::cout << time.asMilliseconds() << "\n";
	//m_rect.move(m_direction.x * m_rect.getSize().x * time.asMilliseconds(), m_direction.y * m_rect.getSize().y * time.asMilliseconds());

}

sf::Vector2i MovingObject::getNextPosGrid() const
{
	return sf::Vector2i(getPosGrid().x + m_direction.x, getPosGrid().y + m_direction.y);
}

sf::Vector2i MovingObject::getPosGrid() const
{
	return sf::Vector2i(m_rect.getPosition().x / m_rect.getSize().x, m_rect.getPosition().y / m_rect.getSize().y);
}


