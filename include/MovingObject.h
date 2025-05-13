#pragma once
#include "GameObject.h"

const int OutlineThickness = 3;
const sf::Vector2f MovingObjectDimension(25, 25);

class MovingObject : public GameObject {
public:
	MovingObject(sf::Vector2i position, int speed = 0);
	//void collide(BoundPixel& other) override;
	void setDirection(const sf::Vector2i& direction);
	void update(sf::Time time) override;

protected:
	sf::Vector2i m_direction;
	int m_speed = 0;
};