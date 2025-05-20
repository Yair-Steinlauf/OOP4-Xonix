#include "Board.h"
#include "set"

Board::Board(int PixelxSize, int PixelySize, int numOfEnemies, int requierdPercentWin)
{
    m_pixelSize.x = PixelxSize;
    m_pixelSize.y = PixelySize;
	initBoard();
    fillEnemysVector(numOfEnemies);
    m_player = std::make_shared<Player>(sf::Vector2i(0,0), m_pixelSize.x, m_pixelSize.y);
}



sf::Vector2f Board::gridToSfml(int row, int col) {
    return sf::Vector2f(row * m_pixelSize.x, col * m_pixelSize.y);
}
sf::Vector2i Board::sfmlToGrid(sf::Vector2f pos) {
	return sf::Vector2i(pos.x / m_pixelSize.x, pos.y / m_pixelSize.y);    
}


void Board::draw(sf::RenderWindow& window)
{       
    for (int row = 0; row < NUM_OF_ROWS; row++)
    {
        for (int col = 0; col < NUM_OF_COLUMS; col++)
        {
			m_matrix[row][col].draw(&window);
        }
    }

    //draw enemys
    for (const auto& enemy : m_enemys) {
        enemy->draw(&window);
    }
    //draw Player
    m_player->draw(&window);
}

void Board::update(sf::Time time)
{
    //update enemys
    for (const auto& enemy : m_enemys) {
        enemy->update(time);
    }
    //update Player
    m_player->update(time);
}

void Board::handelCollison()
{
    handleEnemyCollision();
    
    handlePlayerColliosion();

}


void Board::handlePlayerColliosion()
{
    if (!isInBoardGrid(m_player->getNextPosGrid()))
        m_player->setDirection(sf::Vector2i(0, 0));

    handlePlayerOnGrid(m_player->getNextPosGrid().x, m_player->getNextPosGrid().y);
}

void Board::handlePlayerOnGrid(int nextRowIndex, int nextColIndex)
{
    switch (m_matrix[nextRowIndex][nextColIndex].getType()) {
    case Unoccupied:
        //occupy new area
        m_matrix[nextRowIndex][nextColIndex].setType(Type::Trail);
        m_player->startOccuping();
        break;
    case Trail:
        //if player moved
        if (m_player->getNextPosGrid() != m_player->getPosGrid())
            m_player->decreaseLife();
        break;
    case Occupied:
        if (m_player->isOccupying()) {
            m_player->stopOccuping();
            fillOccupied();
        }
        break;
    }
}

bool Board::isInBoardGrid(sf::Vector2i point)
{

    if ((point.x < NUM_OF_ROWS && point.x >= 0) &&
        (point.y < NUM_OF_COLUMS && point.y >= 0))
        return true;
     return false;
}

void Board::handleEnemyCollision()
{
    for (const auto& enemy : m_enemys) {
        int nextRowIndex = enemy->getNextPosGrid().x;
        int nextColIndex = enemy->getNextPosGrid().y;
        if (isInBoardGrid({ nextRowIndex, nextColIndex })) {
            switch (m_matrix[nextRowIndex][nextColIndex].getType()) {
            case Trail:
                m_player->decreaseLife();
                break;
            case Occupied:
                changeEnemyDirection(enemy, nextColIndex, nextRowIndex);
                break;
            }
        }
        else changeEnemyDirection(enemy, nextColIndex, nextRowIndex);
    }
}

void Board::changeEnemyDirection(const std::unique_ptr<Enemy>& enemy, int col, int row)
{
    CollisionType collision;
    if (!isInBoardGrid({ enemy->getPosGrid().x , col}) || m_matrix[enemy->getPosGrid().x][col].getType() == Occupied) {
        collision = CollisionType::Horizontal; 
    }
    else if (!isInBoardGrid({row, enemy->getPosGrid().y }) || m_matrix[row][enemy->getPosGrid().y].getType() == Occupied)
        collision = CollisionType::Vertical; 
    else
        throw std::runtime_error("No position change detected – invalid collision");
    enemy.get()->changeDirection(collision);
}

std::shared_ptr<Player> Board::getPlayer()
{
    return m_player;
}

void Board::fillEnemysVector(int numOfEnemies)
{
	std::set<std::pair<int, int>> usedPositions;
	int row = 0;
	int col = 0;
    for (int i = 0; i < numOfEnemies; i++) {

		//make diffrent random pos for every enemy
        do {
            col = rand() % (NUM_OF_COLUMS - 2) + 1;
            row = rand() % (NUM_OF_ROWS - 2) + 1;
		} while (usedPositions.find(std::make_pair(row, col)) != usedPositions.end());
        usedPositions.insert(std::make_pair(row, col));

        //add enemy
        sf::Vector2i pos(row * m_pixelSize.x, col * m_pixelSize.y);
        m_enemys.push_back(std::make_unique<Enemy>(pos, m_pixelSize.x, m_pixelSize.y));
    }
}

void Board::initBoard()
{
    for (int row = 0; row < NUM_OF_ROWS; row++) {
        std::vector<Cell> rowCells;
        rowCells.reserve(NUM_OF_COLUMS);
        for (int col = 0; col < NUM_OF_COLUMS; col++) {
            if (row <= 1 || row >= NUM_OF_ROWS - 2 || col <= 1 || col >= NUM_OF_COLUMS - 2) {
                rowCells.emplace_back(Type::Occupied, sf::Vector2i(row, col), m_pixelSize.x, m_pixelSize.y);
            }
            else {
                rowCells.emplace_back(Type::Unoccupied, sf::Vector2i(row, col), m_pixelSize.x, m_pixelSize.y);
            }
        }
        m_matrix.push_back(std::move(rowCells));
    }

}

void Board::fillOccupied()
{
	// TODO: fill occupied
}
