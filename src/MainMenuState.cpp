#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window, GameStateManager* manager)
{
	m_window = window;
	m_manager = manager;
	m_titleText.setFont(FontManager::getInstance().getFont());
	m_subTitleText.setFont(FontManager::getInstance().getFont());
	m_titleText.setString("Xonix");
	m_subTitleText.setString("Press Enter to start");
	m_titleText.setCharacterSize(100);
	m_subTitleText.setCharacterSize(50);
	m_titleText.setFillColor(sf::Color::Red);
	m_subTitleText.setFillColor(sf::Color::Black);
	m_titleText.setPosition(100, 200);
	m_subTitleText.setPosition(100, 400);
}

void MainMenuState::handleEvent(sf::Event& event)
{

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
		//m_manager->pushState(std::make_unique<GamePlayState>(m_window, m_manager, );
	}
}
