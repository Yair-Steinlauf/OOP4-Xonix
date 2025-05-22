#include "GameOverState.h"
#include "GamePlay.h"
#include "iostream"


GameOverState::GameOverState(sf::RenderWindow* window, GameStateManager* manager)
	: GameState(window, manager),m_font(FontManager::getInstance().getFont())
{

    const sf::Font& font = FontManager::getInstance().getFont();

    m_background.setSize(sf::Vector2f(window->getSize()));
    m_background.setFillColor(sf::Color(30, 144, 255, 80));  // כחול שקוף

    m_title.setFont(font);
    m_title.setString("Game Over");
    m_title.setCharacterSize(120);
    m_title.setFillColor(sf::Color::Red);
    centerText(m_title, 150);

    m_subTitle.setFont(font);
    m_subTitle.setString("Better luck next time!");
    m_subTitle.setCharacterSize(80);
    m_subTitle.setFillColor(sf::Color::White);
    centerText(m_subTitle, 350);

    m_instruction.setFont(font);
    m_instruction.setString("Press Enter to restart the game");
    m_instruction.setCharacterSize(60);
    m_instruction.setFillColor(sf::Color(200, 200, 200));
    centerText(m_instruction, 600);


    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("Game Over!\nPress Enter to restart game");
    m_gameOverText.setCharacterSize(40);
    m_gameOverText.setFillColor(sf::Color::Red);
    m_gameOverText.setPosition(100, 200);
}

void GameOverState::handleEvent(sf::Event& event)
{
    if (event.key.code == sf::Keyboard::Enter) {
        m_manager->changeState(std::make_unique<GamePlayState>(m_window,m_manager)); //start new game
    }
}

void GameOverState::render(sf::RenderWindow& window)
{
	m_window->clear();
    m_window->draw(m_background);
    m_window->draw(m_title);
    m_window->draw(m_subTitle);
    m_window->draw(m_instruction);
	m_window->display();
}

