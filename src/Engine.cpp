#include "Engine.h"
#include "Types.h"
#include <iostream>


Engine::Engine()
{
	m_stateManager.pushState(std::make_unique<GamePlayState>(m_window, m_stateManager, m_resourceManager));
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

		if (m_stateManager.hasState())
			m_stateManager.getCurrentState()->handleEvent(m_event);
	}

}



void Engine::update()
{
	if (m_stateManager.hasState())
		m_stateManager.getCurrentState()->update(m_clock.getElapsedTime());

}

void Engine::render()
{
	if (m_stateManager.hasState())
		m_stateManager.getCurrentState()->render(m_window);
}
