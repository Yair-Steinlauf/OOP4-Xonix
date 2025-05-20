#include "Player.h"
#include "iostream"
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
	std::cout << "Player life: " << m_life << std::endl;
	m_has_been_hit = true;
}

bool Player::isWon() const
{
	return m_occupiedAreaPercent >= 80;
}

bool Player::isFailed() const
{
	//std::cout << "Player life: " << m_life << std::endl;
	return m_life <= 0;
}

int Player::getLife() const
{
	return m_life;
}

int Player::getScore() const
{
	return m_score;
}

int Player::getOccupiedAreaPercent() const
{
	return m_occupiedAreaPercent;
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
