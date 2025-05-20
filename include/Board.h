
#pragma once

#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include "Types.h"
#include "vector"
#include <memory>
#include <iostream>



using MatrixCell = std::vector<std::vector<Cell>> ;



class Board {
public:
	Board(Player* player, int PixelxSize = 0, int PixelySize = 0, int numOfEnemies = 1, int requierdPercentWin = 80, int life = 3);
	void draw(sf::RenderWindow& window);
	void update(sf::Time time);
	void handelCollison();
	Player* getPlayer();
private:
	sf::Vector2f gridToSfml(int row, int col);
	sf::Vector2i sfmlToGrid(sf::Vector2f pos);
	void handleEnemysCollision();
	void changeEnemyDirection(const std::unique_ptr<Enemy>& enemy, int col, int row);
	bool isInBoardGrid(sf::Vector2i point);
	void handlePlayerColliosion();
	void fillEnemysVector(int numOfEnemies);
	void initBoard();
	void floodFill(int x, int y);
	void occupyList(std::vector<std::pair<int, int>>& cellsToDraw);
	bool floodFill(int x, int y, std::vector<std::pair<int, int>>& cellsToDraw);
	std::vector<std::vector<bool>> getMatVis();
	bool isValid(int x, int y);
	bool isEnemy(int x, int y);
	MatrixCell m_matrix;
	std::vector<std::unique_ptr<Enemy>> m_enemys;
	Player* m_player;
	sf::Vector2i m_pixelSize;

};

