#include "Board.h"


Board::Board(int xSize, int ySize, int numOfEnemies, int requierdPercentWin, int playerLife)
{
	initBoard(xSize, ySize);

}

void Board::initBoard(int xSize, int ySize)
{
	m_player = std::make_shared<Player>(sf::Vector2i(1, 1));
	for (int x = 0; x < xSize; x++) {
		for (int y = 0; y < ySize; y++) {
			if (x == 0 || x == xSize - 1 || y == 0 || y == ySize - 1) {
				m_matrix[x].push_back(std::make_unique<BoundPixel>(sf::Vector2i(x, y)));
			}
			else {
				m_matrix[x].push_back(std::make_unique<UnoccupiedPixel>(sf::Vector2i(x, y)));
			}
		}
	}
}

