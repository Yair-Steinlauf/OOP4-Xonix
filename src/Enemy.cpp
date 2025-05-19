#include "Enemy.h"


Enemy::Enemy(sf::Vector2i startPos, int pixelSizeX, int pixelSizeY, sf::Vector2i direction)
	:MovingObject(startPos, enemySpeed, pixelSizeX, pixelSizeY, direction)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::Green);
	m_diagonalDirection = DiagonalDirection::DownRight;
}


void Enemy::changeDirection(CollisionType collision)
{
	switch (collision) {
	case CollisionType::Vertical:
		m_direction.x *= -1;
		break;
	case CollisionType::Horizontal:
		m_direction.y *= -1;
		break;
	default:
		throw std::exception("Invalid collision type");
	}
}
