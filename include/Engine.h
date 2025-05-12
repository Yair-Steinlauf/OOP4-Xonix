#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class Engine{
public:
	Engine();
	void run();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;
	Board m_board;
	Player m_player;
	std::vector<Enemy> m_enemys;
	bool isGameOver	= false;
	void processEvents();
	void update();
	void render();
	void handleCollision();
	void resetGame();
	void drawGameOverScreen();
};