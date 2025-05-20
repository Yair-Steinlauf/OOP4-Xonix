#include "Engine.h"
#include "Types.h"
#include <iostream>

Engine::Engine()
{
	m_resourceManager = ResourceManager("levels.txt");
	int pixelX = m_resourceManager.getWidth() / NUM_OF_COLUMS_X;	
	int pixelY = m_resourceManager.getHeight() / NUM_OF_ROWS_Y;

	m_board = Board(pixelX, pixelY, m_resourceManager.enemyNum(0), m_resourceManager.getAreaToOccupy(0));
	m_player = m_board.getPlayer();
}

void Engine::run()
{	
	m_window.create(sf::VideoMode(m_resourceManager.getWidth(), m_resourceManager.getHeight()), "Xonix");// = sf::RenderWindow(sf::VideoMode(m_resourceManager.getWidth(), m_resourceManager.getHeight()), "Xonix");
	m_window.setFramerateLimit(60u);
	
	sf::Time elapsed = sf::Time::Zero;
	while (m_window.isOpen())
	{
		processEvents();
		elapsed += m_clock.restart();
		if (elapsed >= sf::microseconds(20000)) {
			setPlayerDirection();
			handleCollision();
			update();
			elapsed = sf::microseconds(0);
		}				
		render();
	}
	/*std::cout << m_resourceManager.getWidth() << " " << m_resourceManager.getWidth() << " " << m_resourceManager.getLife() << '\n';
	for (int i = 0; i < m_resourceManager.getLevelCount(); i++)
	{
		std::cout << m_resourceManager.getAreaToOccupy(i) << " " << m_resourceManager.enemyNum(i) << '\n';
	}*/
}

void Engine::processEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
		if (m_event.type == sf::Event::KeyPressed)
		{
			//switch (m_event.key.code)
			//{
			//case sf::Keyboard::Up:
			//	m_player->setDirection(sf::Vector2i(0, -1));
			//	break;
			//case sf::Keyboard::Down:
			//	m_player->setDirection(sf::Vector2i(0, 1));
			//	break;
			//case sf::Keyboard::Left:
			//	m_player->setDirection(sf::Vector2i(-1, 0));
			//	break;
			//case sf::Keyboard::Right:
			//	m_player->setDirection(sf::Vector2i(1, 0));
			//	break;
			//default:
			//	break; // לא עושים כלום אם נלחץ מקש אחר
			//}
		}

	}

}

void Engine::setPlayerDirection()
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

void Engine::update()
{
	m_board.update(m_clock.getElapsedTime());
}

void Engine::render()
{
	m_window.clear();
	m_board.draw(m_window);
	m_window.display();
}

void Engine::handleCollision()
{
	m_board.handelCollison();
}
