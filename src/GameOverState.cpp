#include "GameOverState.h"
#include "GamePlay.h"
#include "iostream"
GameOverState::GameOverState(sf::RenderWindow& window, GameStateManager& manager)
	: m_window(window), m_manager(manager), m_font(FontManager::getInstance().getFont())
{
    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("Game Over!\nPress any key to restart game");
    m_gameOverText.setCharacterSize(40);
    m_gameOverText.setFillColor(sf::Color::Red);
    m_gameOverText.setPosition(100, 200);
}

void GameOverState::handleEvent(sf::Event& event)
{
    if (event.key.code == sf::Keyboard::Enter) {
        m_manager.changeState(std::make_unique<GamePlayState>(m_window,m_manager)); //start new game
    }
}

void GameOverState::render(sf::RenderWindow& window)
{
	m_window.clear();
	m_window.draw(m_gameOverText);
	m_window.display();
}

