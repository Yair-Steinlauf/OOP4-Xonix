#pragma once
#include "MovingObject.h"

const int PLAYER_SPEED = 3;


class Player : public MovingObject {
public:
	Player(sf::Vector2i startPos, int pixelSizeX = 16, int pixelSizeY = 16);
	void fail();
	bool isOccupying() const;
	void startOccuping();
	void stopOccuping();
	void update(sf::Time time) override;
	void addPointTrail(int x, int y);
	std::vector<sf::Vector2i> getPointsTrail();
	void clearPointsTrail();

private:
	int m_life = 3;
	int m_score = 0;
	sf::Vector2i m_startPos;
	std::vector<sf::Vector2i> m_trailPoints;
	int m_occupiedAreaPercent = 0;
	bool m_isOccupying = false;


};