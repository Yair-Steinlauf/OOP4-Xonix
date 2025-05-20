#include "Engine.h"
#include "Types.h"
#include <iostream>

const sf::Vector2f ScoreBoardPadding = sf::Vector2f(0, 200);

Engine::Engine()
	:m_resourceManager(std::make_unique<FilesManager>())
{
	m_stateManager.pushState(std::make_unique<GamePlayState>(&m_window, &m_stateManager));
}

void Engine::run()
{	
	m_window.create(sf::VideoMode(m_resourceManager->getWidth(), m_resourceManager->getHeight() + ScoreBoardPadding.y), "Xonix");
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
}

void Engine::processEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();

	}
		if (m_stateManager.hasState())
			m_stateManager.getCurrentState()->handleEvent(m_event);

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
