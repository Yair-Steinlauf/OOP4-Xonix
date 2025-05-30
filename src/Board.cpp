﻿#include "Board.h"
#include <queue>
#include "set"
Board::Board(Player* player, int PixelxSize, int PixelySize, int numOfEnemies, int requierdPercentWin, int life)
	:m_player(player)
{
    m_pixelSize.x = PixelxSize;
    m_pixelSize.y = PixelySize;
	initBoard();
    fillEnemysVector(numOfEnemies);
}



sf::Vector2f Board::gridToSfml(int row, int col) {
    return sf::Vector2f(row * m_pixelSize.x, col * m_pixelSize.y);
}
sf::Vector2i Board::sfmlToGrid(sf::Vector2f pos) {
	return sf::Vector2i(pos.x / m_pixelSize.x, pos.y / m_pixelSize.y);    
}


void Board::draw(sf::RenderWindow& window)
{       
    for (int x = 0; x < NUM_OF_COLUMS_X; x++)
    {
        for (int y = 0; y < NUM_OF_ROWS_Y; y++)
        {
			m_matrix[x][y].draw(&window);
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
    handlePlayerColliosion();
    handleEnemysCollision();
    

}


void Board::handlePlayerColliosion()
{
    if (!isInBoardGrid(m_player->getNextPosGrid()))
        m_player->setDirection(sf::Vector2i(0, 0));

    int nextXIndex = m_player->getNextPosGrid().x;
    int nextYIndex = m_player->getNextPosGrid().y;   
    sf::Vector2i curPos(m_player->getPos().x, m_player->getPos().y);
    switch (m_matrix[nextXIndex][nextYIndex].getType()) {
    case Unoccupied:
        m_matrix[nextXIndex][nextYIndex].setType(Type::Trail);
        m_player->startOccuping();
        m_player->addPointTrail(nextXIndex, nextYIndex);
        break;
    case Trail:
        //if player moved
        if (m_player->getNextPosGrid() != m_player->getPosGrid())
        {
            playerFailure();
        }
        break;
    case Occupied:
        if (m_player->isOccupying()) {
            m_player->stopOccuping();            
            int curX = m_player->getPosGrid().x;
            int curY = m_player->getPosGrid().y;
            for (const auto& cell : m_player->getPointsTrail()) {
                m_matrix[cell.x][cell.y].setType(Type::Occupied);
            }     
            if (m_player->getPointsTrail().size() > 0) {
                m_player->addOccupiedAreaPercent(m_player->getPointsTrail().size());
                floodFill(curX, curY);
                m_player->clearPointsTrail();
            }
        }
        break;
    }
}

void Board::playerFailure()
{
    m_player->decreaseLife();
	std::vector<sf::Vector2i> trailPoints = m_player->getPointsTrail();
    for (const auto& cell : trailPoints) {
        m_matrix[cell.x][cell.y].setType(Type::Unoccupied);
    }	
	m_player->setDirection(sf::Vector2i(0, 0));
    m_player->clearPointsTrail();
}

bool Board::isInBoardGrid(sf::Vector2i point)
{

    if ((point.x < NUM_OF_COLUMS_X&& point.x >= 0) &&
        (point.y < NUM_OF_ROWS_Y && point.y >= 0))
        return true;
     return false;
}

void Board::handleEnemysCollision()
{
    for (const auto& enemy : m_enemys) {
        int nextXIndex = enemy.get()->getNextPosGrid().x;
        int nextYIndex = enemy.get()->getNextPosGrid().y;

       
        switch (m_matrix[nextXIndex][nextYIndex].getType()) {
        case Trail:
            playerFailure();
            break;
        case Occupied:
            changeEnemyDirection(enemy, nextXIndex, nextYIndex);
            break;
        }
    }
}



void Board::changeEnemyDirection(const std::unique_ptr<Enemy>& enemy, int x, int y)
{
    if (m_matrix[enemy->getPosGrid().x][enemy->getNextPosGrid().y].getType() == Occupied) {
        enemy.get()->changeDirection(CollisionType::Horizontal);
    }
    if (m_matrix[enemy->getNextPosGrid().x][enemy->getPosGrid().y].getType() == Occupied)
        enemy.get()->changeDirection(CollisionType::Vertical);
}

Player* Board::getPlayer()
{
    return m_player;
}

void Board::fillEnemysVector(int numOfEnemies)
{
	std::set<std::pair<int, int>> usedPositions;
	int x = 0;
	int y = 0;
    for (int i = 0; i < numOfEnemies; i++) {
		//make diffrent random pos for every enemy
        do {
            x = rand() % (NUM_OF_COLUMS_X - 2) + 1;
            y = rand() % (NUM_OF_ROWS_Y - 2) + 1;
		} while (usedPositions.find(std::make_pair(x, y)) != usedPositions.end());
        usedPositions.insert(std::make_pair(x, y));

        //add enemy
        sf::Vector2i pos(x * m_pixelSize.x, y * m_pixelSize.y);
        m_enemys.push_back(std::make_unique<Enemy>(pos, m_pixelSize.x, m_pixelSize.y));
    }
}

void Board::initBoard()
{
    
    for (int x = 0; x < NUM_OF_COLUMS_X; x++)
    {
        std::vector<Cell> cellOnY;
        for (int y = 0; y < NUM_OF_ROWS_Y; y++) {
            if (y <= 1 || y >= NUM_OF_ROWS_Y - 2 || x <= 1 || x >= NUM_OF_COLUMS_X - 2) {
                cellOnY.emplace_back(Type::Occupied, sf::Vector2i(x, y), m_pixelSize.x, m_pixelSize.y);
            }
            else {
                cellOnY.emplace_back(Type::Unoccupied, sf::Vector2i(x, y), m_pixelSize.x, m_pixelSize.y);
            }
        }
        m_matrix.push_back(std::move(cellOnY));
    }
}




void Board::floodFill(int x, int y)
{
    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };
    bool isFilled = false;
    int indexTrail = m_player->getPointsTrail().size();
    std::list<std::pair<int, int>> cellsToDraw;
    while(!isFilled && indexTrail > 0){
        for (int i = 0; i < 4 && !isFilled; i++)
        {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (floodFill(adjx, adjy, cellsToDraw)) {
                occupyList(cellsToDraw);
                m_player->addOccupiedAreaPercent(cellsToDraw.size());
                isFilled = true;
            }
        }
        if(!isFilled) {
            indexTrail--;
            x = m_player->getPointsTrail()[indexTrail].x;
            y = m_player->getPointsTrail()[indexTrail].y;
        }
    }


    

    
}

void Board::occupyList(std::list<std::pair<int, int>>& cellsToDraw)
{
    for (const auto& cell : cellsToDraw) {
        m_matrix[cell.first][cell.second].setType(Type::Occupied);
    }
}

bool Board::floodFill(int x, int y, std::list<std::pair<int, int>>& cellsToDraw)
{
    if (!canBeFilled(x, y)) {
        return false;
    }
    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };

    std::queue<std::pair<int, int> > q;
    std::vector<std::vector<bool>> matVis = getMatVis();

    q.push({ x,y });
    cellsToDraw.push_back({ x,y });
    matVis[x][y] = true;

    while (!q.empty()) {
        std::pair<int, int> cell = q.front();
        x = cell.first;
        y = cell.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {   
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (canBeFilled(adjx, adjy) && !matVis[adjx][adjy]) {
                q.push({ adjx, adjy });
                matVis[adjx][adjy] = true;
                cellsToDraw.push_back({ adjx,adjy });
            }
            if (isEnemy(adjx, adjy)) {
                cellsToDraw.clear();
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<bool>> Board::getMatVis()
{
    std::vector<std::vector<bool>> matVis;
    matVis.resize(NUM_OF_COLUMS_X);
    for (int x = 0; x < NUM_OF_COLUMS_X; x++)
    {
        matVis[x].resize(NUM_OF_ROWS_Y);
        for (int y = 0; y < NUM_OF_ROWS_Y; y++)
        {
            matVis[x][y] = false;
        }
    }
    return matVis;
}



bool Board::canBeFilled(int x, int y)
{
    if (!isInBoardGrid(sf::Vector2i(x,y)))
        return false;


    Type type = m_matrix[x][y].getType();
    if (type == Type::Occupied || type == Type::Trail)
        return false;
    
    return true;
}

bool Board::isEnemy(int x, int y)
{
    for (const auto& enemy : m_enemys) {
        if (enemy.get()->getPosGrid() == sf::Vector2i(x, y)) {            
            return true;
        }
    }
    return false;
}






