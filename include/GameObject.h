#pragma once
#include <SFML/Graphics.hpp>
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

	virtual ~GameObject() = default;

protected:
	sf::RectangleShape m_rect;



};