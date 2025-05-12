#include "Player.h"

Player::Player(sf::Vector2i startPos) : MovingObject(startPos, PLAYER_SPEED), m_startPos(startPos)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::White);
	m_rect.setOutlineColor(sf::Color::Red);
	m_rect.setOutlineThickness(0.01);
}
