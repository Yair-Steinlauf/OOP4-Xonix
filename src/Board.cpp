#include "Board.h"


Board::Board(int xSize, int ySize, int numOfEnemies, int requierdPercentWin)
{
	initBoard(xSize, ySize);
    fillEnemysVector(numOfEnemies, xSize, ySize);
    m_player = std::make_shared<Player>(sf::Vector2i(1, 1));
}

void Board::draw(sf::RenderWindow& window)
{
    //draw matrix
    for (const auto& row : m_matrix) {
        for (const auto& pixel : row) {
			pixel.get()->draw(&window);
        }
    }
    //draw enemys
    for (const auto& enemy : m_enemys) {
        enemy.get()->draw(&window);
    }
    //draw Player
    m_player.get()->draw(&window);
}

void Board::update(sf::Time time)
{
    //draw enemys
    for (const auto& enemy : m_enemys) {
        enemy.get()->update(time);
    }
    //draw Player
    m_player.get()->update(time);
}

void Board::handelCollison()
{
    for (size_t row = 0; row < m_matrix.size(); row++) {
        for (size_t col = 0; col < m_matrix[row].size(); col++) {
            auto pixelPos = sf::Vector2f(row, col);
            handelPlayerCollision(pixelPos, row, col);
            handleEnemyCollison(pixelPos, row, col);
        }
    }
    for (const auto& enemy : m_enemys) {
        //if (enemy.get()->intersect(m_player.get())); TODO: enemy vs player collision
    }
}

void Board::handleEnemyCollison(sf::Vector2f& pixelPos, size_t row, size_t col)
{
    for (const auto& enemy : m_enemys) {
        if (enemy.get()->contains(pixelPos) )
            switch (m_matrix[row][col].get()->getType()) {

                case Trail:
                    m_player.get()->fail();
                    break;
                case Occupied:
                    enemy.get()->changeDirection();
            }

    }
}

void Board::handelPlayerCollision(sf::Vector2f& pixelPos, size_t row, size_t col)
{
    if (m_player.get()->contains(pixelPos)) {
        switch (m_matrix[row][col].get()->getType()) {
        case Unoccupied:
            m_matrix[row][col] = std::make_unique<TrailPixel>(sf::Vector2i(row, col));
            m_player.get()->startOccuping();
            break;
        case Trail:
            m_player.get()->fail();
            break;
        case Bound:
            m_player.get()->setDirection(sf::Vector2i(0, 0));
            break;
        case Occupied:
            if (m_player.get()->isOccupying()) {
                m_player.get()->stopOccuping();
                fillOccupied();
            }
            break;
        }

    }
}

void Board::fillEnemysVector(int numOfEnemies, int xSize, int ySize)
{
    for (int i = 0; i < numOfEnemies; i++) {
        int x = rand() % (xSize - 2) + 1;
        int y = rand() % (ySize - 2) + 1;
        m_enemys.push_back(std::make_unique<Enemy>(sf::Vector2i(x, y)));
    }
}

void Board::initBoard(int xSize, int ySize)
{
    m_matrix.resize(xSize);
    for (int x = 0; x < xSize; x++) {
        m_matrix[x].resize(ySize);
        for (int y = 0; y < ySize; y++) {
            if (x == 0 || x == xSize - 1 || y == 0 || y == ySize - 1) {
                m_matrix[x][y] = std::make_unique<BoundPixel>(sf::Vector2i(x, y));
            }
            else {
                m_matrix[x][y] = std::make_unique<UnoccupiedPixel>(sf::Vector2i(x, y));
            }
        }
    }
}

