#pragma once
#include "GameObject.h"

const int OutlineThickness = 3;

class MovingObject : public GameObject {
public:
	MovingObject(sf::Vector2i position, int speed = 0, int pixelSizeX = 16, int pixelSizeY = 16, sf::Vector2i direction = sf::Vector2i(1,1));
	void setDirection(const sf::Vector2i& direction);
	virtual void update(sf::Time time) override;
	sf::Vector2i getNextPosGrid() const;
	sf::Vector2i getPosGrid() const;

protected:
	sf::Vector2i m_direction;
	int m_speed = 0;	// TODO: maybe delete
	sf::Time m_moveTimer = sf::microseconds(0);
};