#include "Player.h"
#include "iostream"
Player::Player(sf::Vector2i startPos, int pixelSizeX, int pixelSizeY, int life) :
	MovingObject(startPos, PLAYER_SPEED,pixelSizeX, pixelSizeY), m_startPos(startPos),  m_life(life)
{
	m_rect.setPosition(sf::Vector2f(startPos.x, startPos.y));
	m_rect.setFillColor(sf::Color::White);
	m_life = life;

	
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
		moveToStartPos();
		m_score -= 10;
		m_has_been_hit = false;
	}
}

void Player::decreaseLife()
{	
	m_has_been_hit = true;
}

bool Player::isFailed() const
{	
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

float Player::getOccupiedAreaPercent() const
{
	return m_occupiedAreaPercent;
}

void Player::addOccupiedAreaPercent(float cellsOccupied)
{
	int percent = (cellsOccupied * 100) / NUM_OF_CELLS_UNOCCUPIED;

	m_occupiedAreaPercent += percent;
	if (percent <= 1)
		m_score += 1;
	else if (percent <= 3)
		m_score += percent;
	else if(percent <= 6)
		m_score += percent * 2;
	else if (percent <= 10)
		m_score += percent * 3;
	else if (percent <= 15)
		m_score += percent * 4;
	else if (percent <= 25)
		m_score += percent * 5;
	else if (percent <= 35)
		m_score += percent * 6;
	else if (percent <= 50)
		m_score += percent * 7;
	else
		m_score += percent * 8;
}

void Player::resetOccupiedAreaPercent()
{
	m_occupiedAreaPercent = 0;
}

void Player::moveToStartPos()
{
	m_rect.setPosition(m_startPos.x, m_startPos.y);
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
	if(m_trailPoints.empty())
		return;
	m_trailPoints.clear();
}
