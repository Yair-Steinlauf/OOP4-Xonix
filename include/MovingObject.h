#include "GameObject.h"


static const sf::Vector2f MovingObjectDimension(25, 25);

class MovingObject : public GameObject {
public:
	MovingObject(sf::Vector2i position, int speed = 0);
	void collide(BoundPixel& other);
	void setDirection(sf::Vector2i direction);
	

protected:
	sf::Vector2i m_direction;
	int m_speed = 0;
};