#pragma once
#include "GameObject.h"

enum Type {
	Trail, Occupied, Unoccupied, Bound
};



class Pixel : public GameObject {
public:
	Pixel(sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);
	Type getType()const;
protected:
	Type m_condition = Type::Unoccupied;
};