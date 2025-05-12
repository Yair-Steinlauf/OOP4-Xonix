#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	m_resourceManager = ResourceManager("levels.txt");
	

}

void Engine::run()
{
	sf::RenderWindow window(sf::VideoMode(m_resourceManager.getWidth(), m_resourceManager.getHeight()), "Xonix");
	window.setFramerateLimit(60u);

	/*std::cout << m_resourceManager.getWidth() << " " << m_resourceManager.getWidth() << " " << m_resourceManager.getLife() << '\n';
	for (int i = 0; i < m_resourceManager.getLevelCount(); i++)
	{
		std::cout << m_resourceManager.getAreaToOccupy(i) << " " << m_resourceManager.enemyNum(i) << '\n';
	}*/
}
