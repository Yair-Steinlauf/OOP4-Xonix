#include "Player.h"

Player::Player(sf::Vector2i startPos, int pixelSizeX, int pixelSizeY) : 
	MovingObject(startPos, PLAYER_SPEED,pixelSizeX, pixelSizeY), m_startPos(startPos)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::White);

	
}

void Player::fail()
{
	//TODO: fail stuff
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
}

void Player::addPointTrail(int x, int y)
{
	m_trailPoints.push_back(sf::Vector2i(x, y));
}

std::vector<sf::Vector2i> Player::getPointsTrail()
{
	return m_trailPoints;
}

void Player::clearPointsTrail()
{
	m_trailPoints.clear();
}
