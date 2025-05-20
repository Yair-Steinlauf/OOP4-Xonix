#include "GamePlay.h"
#include "GameOverState.h"


GamePlayState::GamePlayState(sf::RenderWindow* window, GameStateManager* manager)
	:GameState(window, manager),
	m_level(0),
	m_resourceManager(FilesManager()),
	m_pixelX(m_resourceManager.getWidth() / NUM_OF_COLUMS_X),
	m_pixelY(m_resourceManager.getHeight() / NUM_OF_ROWS_Y),
	m_player(std::make_unique<Player>(sf::Vector2i(1, 1), m_pixelX, m_pixelY, m_resourceManager.getLife())),
	m_scoreBoard(ScoreBoard(sf::Vector2f(m_resourceManager.getWidth(), 200), sf::Vector2f(0, m_resourceManager.getHeight()))),
	m_board(Board(m_player.get(), m_pixelX, m_pixelY, m_resourceManager.enemyNum(m_level), m_resourceManager.getAreaPercentToOccupy(m_level), m_resourceManager.getLife()))
{
}

void GamePlayState::handleEvent(sf::Event& event)
{

	setPlayerDirection();
}

void GamePlayState::nextLevel()
{
	m_level++;
	m_board = Board(m_player.get(), m_pixelX, m_pixelY,
		m_resourceManager.enemyNum(m_level), m_resourceManager.getAreaPercentToOccupy(m_level));
	m_player->resetOccupiedAreaPercent();
}

void GamePlayState::setPlayerDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_player->setDirection(sf::Vector2i(0, -1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_player->setDirection(sf::Vector2i(0, 1));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_player->setDirection(sf::Vector2i(-1, 0));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_player->setDirection(sf::Vector2i(1, 0));
}

void GamePlayState::update(sf::Time dt)
{
	m_board.handelCollison();
	m_board.update(dt);
	m_scoreBoard.update(m_player.get(), m_level);
	if (m_player->isFailed()) {
		m_manager->changeState(std::make_unique<GameOverState>(m_window, m_manager));
	}
	if (m_player->getOccupiedAreaPercent() >= m_resourceManager.getAreaPercentToOccupy(m_level)) {
		nextLevel();
	}
	//else if (m_player->isWon()) {
	//	m_manager.changeState(std::make_unique<WinState>(m_window, m_manager, m_resourceManager));
	//}
}

void GamePlayState::render(sf::RenderWindow& window)
{
	m_window->clear();
	m_board.draw(*m_window);
	m_scoreBoard.draw(*m_window);
	m_window->display();
}
