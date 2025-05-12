#include "Pixel.h"


Pixel::Pixel(sf::Vector2i pos) : GameObject(pos)
{
	m_rect.setSize(pixelSize);
}
