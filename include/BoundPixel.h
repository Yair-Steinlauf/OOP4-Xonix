#pragma once
#include "Pixel.h"

class BoundPixel : public Pixel {
public:
	BoundPixel(sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);

};