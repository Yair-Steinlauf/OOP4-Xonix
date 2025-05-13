
#pragma once

#include "SFML/Graphics.hpp"
#include "Pixel.h"
#include "BoundPixel.h"
#include "OccupiedPixel.h"
#include "UnOccupiedPixel.h"
#include "TrailPixel.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include "Types.h"
#include "vector"
#include <memory>


using MatrixPixel = std::vector<std::vector<std::unique_ptr<Pixel>>> ;



class Board {
public:
	Board(int PixelxSize = 0, int PixelySize = 0, int numOfEnemies = 1 ,int requierdPercentWin = 80);
	void draw(sf::RenderWindow& window);
	void update(sf::Time time);
	void handelCollison();
	std::shared_ptr<Player> getPlayer();
private:
	void handleEnemyCollision();
	void changeEnemyDirection(const std::unique_ptr<Enemy>& enemy, int col, int row);
	bool isInBoardGrid(sf::Vector2i point);
	void handlePlayerColliosion();
	void fillEnemysVector(int numOfEnemies);
	void initBoard();
	void fillOccupied();
	MatrixPixel m_matrix;
	std::vector<std::unique_ptr<Enemy>> m_enemys;
	std::shared_ptr<Player> m_player;
	sf::Vector2i m_pixelSize;

};
