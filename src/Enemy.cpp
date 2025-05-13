#include "Enemy.h"


Enemy::Enemy(sf::Vector2i startPos) 
	:MovingObject(startPos, enemySpeed) 
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::Green);
	m_rect.setOutlineColor(sf::Color::White);
	m_rect.setOutlineThickness(OutlineThickness);
}

void Enemy::changeDirection()
{
	//TODO: change direction algo
}
