#include "WinState.h"

WinState::WinState(int score, sf::RenderWindow* window, GameStateManager* manager)
	:GameState(window, manager)
{
	
	m_title.setFont(FontManager::getInstance().getFont());
	m_title.setString("You Win!\nPress Enter to restart game");
	m_title.setCharacterSize(40);
	m_title.setFillColor(sf::Color::Red);
	m_title.setPosition(100, 200);
	m_subTitle.setFont(FontManager::getInstance().getFont());
	m_subTitle.setFillColor(sf::Color::Red);
	m_subTitle.setCharacterSize(40);
	m_subTitle.setPosition(100, 300);
	m_subTitle.setString("Your score is: " + std::to_string(score));
}

void WinState::handleEvent(sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Enter) {
		m_manager->changeState(std::make_unique<GamePlayState>(m_window, m_manager));
	}
}

void WinState::render(sf::RenderWindow& window)
{
	m_window->clear();
	m_window->draw(m_title);
	m_window->draw(m_subTitle);
	m_window->display();
}
