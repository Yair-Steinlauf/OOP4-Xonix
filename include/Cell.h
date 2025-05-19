#pragma once
#include "SFML/Graphics.hpp"

enum Type {
	Trail, 
	Occupied, 
	Unoccupied
};

class Cell {
public:
	Cell(Type type, sf::Vector2i pos, int pixelSizeX = 16, int pixelSizeY = 16);
	void setType(Type type);
	Type getType() const;
	void draw(sf::RenderWindow* window);	
private:
	sf::RectangleShape m_pixelRect;
	Type m_type;

};