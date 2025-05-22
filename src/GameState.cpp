#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, GameStateManager* manager)
	: m_window(window), m_manager(manager)
{
}

void GameState::centerText(sf::Text& text, float y)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.width / 2, bounds.height / 2);
	text.setPosition(m_window->getSize().x / 2.0f, y);
}
