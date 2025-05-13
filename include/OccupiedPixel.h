#pragma once
#include "Pixel.h"

class OccupiedPixel : public Pixel {
public:
	OccupiedPixel(sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);

};