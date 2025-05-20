#include "GamePlay.h"
#include "GameOverState.h"


GamePlayState::GamePlayState(sf::RenderWindow& window, GameStateManager& manager)
	: m_window(window),
	m_manager(manager),
	m_resourceManager(&FilesManager::getInstance()),
	m_scoreBoard(ScoreBoard(sf::Vector2f(m_resourceManager->getWidth(), 200), sf::Vector2f(0, m_resourceManager->getHeight())))
{
	
	
	int pixelX = m_resourceManager->getWidth() / NUM_OF_ROWS;
	int pixelY = m_resourceManager->getHeight() / NUM_OF_COLUMS;

	m_board = Board(pixelX, pixelY, m_resourceManager->enemyNum(0), m_resourceManager->getAreaToOccupy(0));
	m_player = m_board.getPlayer();
}

void GamePlayState::handleEvent(sf::Event& event)
{

	setPlayerDirection();
}

void GamePlayState::setPlayerDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_player.get()->setDirection(sf::Vector2i(0, -1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_player.get()->setDirection(sf::Vector2i(0, 1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_player.get()->setDirection(sf::Vector2i(-1, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_player.get()->setDirection(sf::Vector2i(1, 0));
}

void GamePlayState::update(sf::Time dt)
{
	m_board.handelCollison();
	m_board.update(dt);
	m_scoreBoard.update(m_player.get());
	if (m_player->isFailed()) {
		m_manager.changeState(std::make_unique<GameOverState>(m_window, m_manager));
	}
	//else if (m_player->isWon()) {
	//	m_manager.changeState(std::make_unique<WinState>(m_window, m_manager, m_resourceManager));
	//}
}

void GamePlayState::render(sf::RenderWindow& window)
{
	m_window.clear();
	m_board.draw(m_window);
	m_scoreBoard.draw(m_window);
	m_window.display();
}
