#pragma once
#include "Pixel.h"

class UnoccupiedPixel : public Pixel {
public:
	UnoccupiedPixel(sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);

};