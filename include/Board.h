
#pragma once

#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include "Types.h"
#include "vector"
#include <memory>



using MatrixCell = std::vector<std::vector<Cell>> ;



class Board {
public:
	Board(int PixelxSize = 0, int PixelySize = 0, int numOfEnemies = 1 ,int requierdPercentWin = 80);
	void draw(sf::RenderWindow& window);
	void update(sf::Time time);
	void handelCollison();
	std::shared_ptr<Player> getPlayer();
private:
	sf::Vector2f gridToSfml(int row, int col);
	sf::Vector2i sfmlToGrid(sf::Vector2f pos);
	void handleEnemyCollision();
	void changeEnemyDirection(const std::unique_ptr<Enemy>& enemy, int col, int row);
	bool isInBoardGrid(sf::Vector2i point);
	void handlePlayerColliosion();
	void fillEnemysVector(int numOfEnemies);
	void initBoard();
	void fillOccupied();
	MatrixCell m_matrix;
	std::vector<std::unique_ptr<Enemy>> m_enemys;
	std::shared_ptr<Player> m_player;
	sf::Vector2i m_pixelSize;

};

