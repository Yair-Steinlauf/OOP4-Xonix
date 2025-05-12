#include "MovingObject.h"

static const int enemySpeed = 10;

class Enemy : public MovingObject {
public:
	Enemy(sf::Vector2i startPos);
	void collide(Player& other) override;
	void collide(OccupiedPixel& other) override;
	void changeDirection();
private:
	
};