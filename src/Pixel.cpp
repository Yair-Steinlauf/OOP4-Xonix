#include "Pixel.h"


Pixel::Pixel(sf::Vector2i pos, int pixelSizeX, int pixelSizeY) : GameObject(pos, pixelSizeX,pixelSizeY)
{

}

Type Pixel::getType() const
{
	return m_condition;
}
