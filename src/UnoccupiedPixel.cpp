#include "UnoccupiedPixel.h"

UnoccupiedPixel::UnoccupiedPixel(sf::Vector2i pos) : Pixel(pos)
{
	m_condition = Type::Unoccupied;
	m_rect.setPosition(sf::Vector2f(pos.x, pos.y));
	m_rect.setFillColor(sf::Color::Black);		
}
