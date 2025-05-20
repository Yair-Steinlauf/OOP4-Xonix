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
		m_has_been_hit = false;
	}
}

void Player::decreaseLife()
{
	std::cout << "Player life: " << m_life << std::endl;
	m_has_been_hit = true;
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

float Player::getOccupiedAreaPercent() const
{
	return m_occupiedAreaPercent;
}

void Player::addOccupiedAreaPercent(float cellsOccupied)
{
	m_occupiedAreaPercent += (cellsOccupied * 100) / NUM_OF_CELLS_UNOCCUPIED;
	// TODO: change score if larger smaller
}

void Player::resetOccupiedAreaPercent()
{
	m_occupiedAreaPercent = 0;
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
