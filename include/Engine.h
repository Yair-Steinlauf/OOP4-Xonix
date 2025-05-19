#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include "ResourceManager.h"
#include <vector>
#include <memory>
#include "GamePlay.h"
#include "GameStateManager.h"
#include "GameState.h"

class Engine{
public:
	Engine();
	void run();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	Board m_board;
	sf::Clock m_clock;
	std::shared_ptr<Player> m_player;
	//std::vector<Enemy> m_enemys;
	void resetGame();
	void drawGameOverScreen();
	void drawGame();
	FilesManager* m_resourceManager;
	GameStateManager m_stateManager;
	bool isGameOver	= false;
	void processEvents();
	void update();
	void render();
	void handleCollision();
	//void resetGame();
	//void drawGameOverScreen();
};