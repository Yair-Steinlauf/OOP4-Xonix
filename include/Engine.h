#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <memory>
#include "GamePlay.h"

class FilesManager;
class GameStateManager;


class Engine{
public:
	Engine();
	void run();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Clock m_clock;
	std::unique_ptr<FilesManager >m_resourceManager;
	GameStateManager m_stateManager;
	void processEvents();
	void update();
	void render();
};