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
