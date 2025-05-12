#include "GameObject.h"
static const sf::Vector2f pixelSize(1, 1);

class Pixel : public GameObject {
public:
	Pixel(sf::Vector2i pos);
};