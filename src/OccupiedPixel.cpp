#include "OccupiedPixel.h"

OccupiedPixel::OccupiedPixel(sf::Vector2i pos) 
	: Pixel(pos)
{
	m_condition = Type::Occupied;
	m_rect.setPosition(sf::Vector2f(pos.x, pos.y));
	m_rect.setFillColor(sf::Color::Blue);
}
