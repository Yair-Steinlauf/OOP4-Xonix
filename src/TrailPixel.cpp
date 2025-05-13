#include "TrailPixel.h"

TrailPixel::TrailPixel(sf::Vector2i pos, int pixelSizeX, int pixelSizeY) : Pixel(pos, pixelSizeX, pixelSizeY)
{
	m_condition = Type::Trail;
	m_rect.setPosition(sf::Vector2f(pos.x, pos.y));
	m_rect.setFillColor(sf::Color::Red);
}
