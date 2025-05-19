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

private:
	int m_life = 3;
	int m_score = 0;
	sf::Vector2i m_startPos;
	int m_occupiedAreaPercent = 0;
	bool m_isOccupying = false;


};