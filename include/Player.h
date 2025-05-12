#include "MovingObject.h"

const int PLAYER_SPEED = 5;


class Player : public MovingObject {
public:
	Player(sf::Vector2i startPos);
	void collide(UnoccupiedPixel& other);
	void collide(Enemy& other);
	void collide(OccupiedPixel& other);
	void fail();
	bool isOccupying() const;
	void startOccuping();
	void stopOccuping();

private:
	int m_life = 3;
	int m_score = 0;
	sf::Vector2i m_startPos;
	int m_occupiedAreaPercent = 0;
	bool m_isOccupying = false;


};