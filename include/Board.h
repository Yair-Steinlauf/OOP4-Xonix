//#pragma once
//
//#include "SFML/Graphics.hpp"
//#include "Pixel.h"
//#include "BoundPixel.h"
//#include "OccupiedPixel.h"
//#include "TrailPixel.h"
//#include "vector"
//#include <memory>
//
//
//using MatrixPixel = std::vector<std::vector<std::unique_ptr<Pixel>>> ;
//
//
//class Board {
//public:
//	Board(int xSize = 0, int ySize = 0, int numOfEnemies = 1 ,int requierdPercentWin = 80);
//private:
//	void initBoard(int xSize, int ySize);
//	MatrixPixel m_matrix;
//	std::vector<std::unique_ptr<Enemy>> m_enemys;
//	std::shared_ptr<Player> m_player;
//};