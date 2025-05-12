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
#include "vector"
#include <memory>


using MatrixPixel = std::vector<std::vector<std::unique_ptr<Pixel>>> ;


class Board {
public:
	Board(int xSize = 0, int ySize = 0, int numOfEnemies = 1 ,int requierdPercentWin = 80);
	void draw(sf::RenderWindow& window);
	void update(sf::Time time);
	void handelCollison();
	void handleEnemyCollison(sf::Vector2f& pixelPos, size_t row, size_t col);
	void handelPlayerCollision(sf::Vector2f& pixelPos, size_t row, size_t col);
private:
	void fillEnemysVector(int numOfEnemies, int xSize, int ySize);
	void initBoard(int xSize, int ySize);
	void fillOccupied();
	MatrixPixel m_matrix;
	std::vector<std::unique_ptr<Enemy>> m_enemys;
	std::shared_ptr<Player> m_player;
};