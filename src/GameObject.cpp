#include "GameObject.h"

GameObject::GameObject(sf::Vector2i pos) :
	m_rect()
{
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

sf::Vector2f GameObject::getPos() const
{
	return m_rect.getPosition();
}
