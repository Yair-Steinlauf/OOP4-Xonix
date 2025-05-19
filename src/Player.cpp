#include "Player.h"

Player::Player(sf::Vector2i startPos, int pixelSizeX, int pixelSizeY) : 
	MovingObject(startPos, PLAYER_SPEED,pixelSizeX, pixelSizeY), m_startPos(startPos)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::White);

	
}


bool Player::isOccupying() const
{
	return m_isOccupying;
}

void Player::startOccuping()
{
	m_isOccupying = true;
}

void Player::stopOccuping()
{
	m_isOccupying = false;
}

void Player::update(sf::Time time)
{
	MovingObject::update(time);
	m_direction = sf::Vector2i(0, 0);
	if (m_has_been_hit) {
		m_life--;
		m_has_been_hit = false;
	}
}

void Player::decreaseLife()
{
	m_has_been_hit = true;
}

bool Player::isFailed() const
{
	return m_life > 0;
}
