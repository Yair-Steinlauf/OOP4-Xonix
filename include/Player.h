#pragma once
#include "MovingObject.h"
#include "Types.h"

const int PLAYER_SPEED = 3;


class Player : public MovingObject {
public:
	Player(sf::Vector2i startPos, int pixelSizeX = 16, int pixelSizeY = 16, int life = 3);
	bool isOccupying() const;
	void startOccuping();
	void stopOccuping();
	void update(sf::Time time) override;
	void addPointTrail(int x, int y);
	std::vector<sf::Vector2i> getPointsTrail();
	void clearPointsTrail();
	void decreaseLife();
	bool isFailed() const;
	int getLife() const;
	int getScore() const;
	float getOccupiedAreaPercent() const;
	void addOccupiedAreaPercent(float cellsOccupied);
	void resetOccupiedAreaPercent();
private:
	int m_life = 3;
	int m_score = 0;
	bool m_has_been_hit = false;
	sf::Vector2i m_startPos;
	std::vector<sf::Vector2i> m_trailPoints;
	float m_occupiedAreaPercent = 0;
	bool m_isOccupying = false;


};