#include "Enemy.h"


Enemy::Enemy(sf::Vector2i startPos, int pixelSizeX, int pixelSizeY, sf::Vector2i direction)
	:MovingObject(startPos, enemySpeed, pixelSizeX, pixelSizeY, direction)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::Green);
	m_diagonalDirection = DiagonalDirection::DownRight;
}

void Enemy::collide(OccupiedPixel& other)
{
	//changeDirection();
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
	//{
	/*witch (m_diagonalDirection)
	case DiagonalDirection::DownRight:
		m_diagonalDirection = DiagonalDirection::DownLeft;
		m_direction = sf::Vector2i(-1, 1);
		break;
	case DiagonalDirection::DownLeft:
		m_diagonalDirection = DiagonalDirection::UpLeft;
		m_direction = sf::Vector2i(-1, -1);
		break;
	case DiagonalDirection::UpLeft:
		m_diagonalDirection = DiagonalDirection::UpRight;
		m_direction = sf::Vector2i(1, -1);
		break;
	case DiagonalDirection::UpRight:
		m_diagonalDirection = DiagonalDirection::DownRight;
		m_direction = sf::Vector2i(1, 1);
		break;
	default:
		throw std::exception("direction not correct");
		break;
	}*/
}
