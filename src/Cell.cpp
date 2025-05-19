#include "Cell.h"

Cell::Cell(Type type, sf::Vector2i pos, int pixelSizeX, int pixelSizeY)
	: m_type(type) {
		m_pixelRect.setPosition(sf::Vector2f(pos.x * pixelSizeX, pos.y * pixelSizeY));
		m_pixelRect.setSize(sf::Vector2f(pixelSizeX, pixelSizeY));
		setType(type);		
	}

void Cell::setType(Type type)
{
	switch (type) {
	case Trail:
		m_pixelRect.setFillColor(sf::Color::Red);
		break;
	case Occupied:
		m_pixelRect.setFillColor(sf::Color::Blue);
		break;
	case Unoccupied:
		m_pixelRect.setFillColor(sf::Color::Black);
		break;
	}
	m_type = type;
}

Type Cell::getType() const
{
	return m_type;
}

void Cell::draw(sf::RenderWindow* window)
{
	window->draw(m_pixelRect);
}
