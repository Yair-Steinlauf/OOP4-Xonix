#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2i pos, int speed) : 
	GameObject(pos), m_speed(speed), m_direction(sf::Vector2i(0,0))
	
{
	m_rect.setSize(MovingObjectDimension);
}

void MovingObject::setDirection(const sf::Vector2i& direction)
{
	m_direction = direction;
}

void MovingObject::update(sf::Time time)
{
	m_rect.move(time.asSeconds() * m_speed, time.asSeconds() * m_speed);
}
