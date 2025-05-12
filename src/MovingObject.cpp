#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2i pos, int speed) : 
	GameObject(pos), m_speed(speed), m_direction(sf::Vector2i(0,0))
	
{
	m_rect.setSize(MovingObjectDimension);
}
