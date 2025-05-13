#include "GameObject.h"

GameObject::GameObject(sf::Vector2i pos, int pixelSizeX, int pixelSizeY ) :
	m_rect()
{
	m_rect.setSize(sf::Vector2f(pixelSizeX, pixelSizeY));
	m_rect.setPosition(pos.x, pos.y);
}

void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(m_rect);

}

bool GameObject::contains(const sf::Vector2f& otherPos)
{
	return m_rect.getGlobalBounds().contains(otherPos);
}

bool GameObject::intersect(GameObject& other)
{
	return m_rect.getGlobalBounds().intersects(other.m_rect.getGlobalBounds());
}

sf::Vector2f GameObject::getPos() const
{
	return m_rect.getPosition();
}
