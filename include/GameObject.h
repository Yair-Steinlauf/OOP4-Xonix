#pragma once
#include <SFML/Graphics.hpp>
class BoundPixel;
class OccupiedPixel;
class TrailPixel;
class UnoccupiedPixel;
class Enemy;
class Player;
class MovingObject;
class StaticObject;


class GameObject {
public:
	GameObject(sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);
	void draw(sf::RenderWindow* window);
	bool contains(const sf::Vector2f& otherPos);
	bool intersect(GameObject& other);
	sf::Vector2f getPos() const;
	virtual void update(sf::Time time) {};
	virtual void collide(GameObject& other) {};
	virtual void collide(BoundPixel& other) {};
	virtual void collide(OccupiedPixel& other) {};
	virtual void collide(TrailPixel& other) {};
	virtual void collide(UnoccupiedPixel& other){};
	virtual void collide(Enemy& other){};
	virtual void collide(Player& other){};
	virtual void collide(MovingObject& other){};
	virtual void collide(StaticObject& other){};



protected:
	sf::RectangleShape m_rect;



};