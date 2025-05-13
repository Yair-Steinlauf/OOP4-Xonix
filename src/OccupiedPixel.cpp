#include "OccupiedPixel.h"

OccupiedPixel::OccupiedPixel(sf::Vector2i pos, int pixelSizeX, int pixelSizeY) : Pixel(pos, pixelSizeX, pixelSizeY)
{
	m_condition = Type::Occupied;
	m_rect.setPosition(sf::Vector2f(pos.x, pos.y));
	m_rect.setFillColor(sf::Color::Blue);
}
