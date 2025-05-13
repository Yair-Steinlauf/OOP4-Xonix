#pragma once
#include "MovingObject.h"

static const int enemySpeed = 20;

enum class DiagonalDirection {
	DownRight,
	DownLeft,
	UpLeft,
	UpRight
};

enum class CollisionType {
	Vertical,   // קיר שמאל/ימין
	Horizontal  // קיר למעלה/למטה
};
class Enemy : public MovingObject {
public:
	Enemy(sf::Vector2i startPos, int pixelSizeX = 16, int pixelSizeY = 16, sf::Vector2i direction = sf::Vector2i(1, 1));
	//void collide(Player& other) override;
	void collide(OccupiedPixel& other) override;
	void changeDirection(CollisionType collision);
	

private:
	DiagonalDirection m_diagonalDirection;
};