#include "Board.h"
#include <queue>
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
    handleEnemysCollision();
    
    handlePlayerColliosion();

}


void Board::handlePlayerColliosion()
{
    if (!isInBoardGrid(m_player.get()->getNextPosGrid()))
        m_player.get()->setDirection(sf::Vector2i(0, 0));

    int nextXIndex = m_player.get()->getNextPosGrid().x;
    int nextYIndex = m_player.get()->getNextPosGrid().y;   
    sf::Vector2i curPos(m_player.get()->getPos().x, m_player.get()->getPos().y);
    switch (m_matrix[nextXIndex][nextYIndex].getType()) {
    case Unoccupied:
        m_matrix[nextXIndex][nextYIndex].setType(Type::Trail);
        m_player.get()->startOccuping();
        m_player.get()->addPointTrail(nextXIndex, nextYIndex);
        break;
    case Trail:
        //if player moved
        if (m_player->getNextPosGrid() != m_player->getPosGrid())
            m_player->decreaseLife();
//             TODO: Fail?
        break;
    case Occupied:
        if (m_player.get()->isOccupying()) {
            m_player.get()->stopOccuping();            
            int curX = m_player.get()->getPosGrid().x;
            int curY = m_player.get()->getPosGrid().y;
            for (const auto& cell : m_player.get()->getPointsTrail()) {
                m_matrix[cell.x][cell.y].setType(Type::Occupied);
            }
            m_player.get()->clearPointsTrail();
            floodFill(curX, curY);
        }
        break;
    }
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

        if (nextYIndex < 1 || nextYIndex > NUM_OF_ROWS_Y - 2 || nextXIndex < 1 || nextXIndex > NUM_OF_COLUMS_X - 2) {
            std::cout << "here: " << nextXIndex << ", " << nextYIndex << "\n";
        }
        switch (m_matrix[nextXIndex][nextYIndex].getType()) {
        case Trail:
            m_player.get()->fail();
            break;
        case Occupied:
            changeEnemyDirection(enemy, nextXIndex, nextYIndex);
            break;
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
    std::vector<std::pair<int, int>> listToDraw;
    if (floodFill(x + 1, y, listToDraw)) {
        for (const auto& cell : listToDraw) {
            m_matrix[cell.first][cell.second].setType(Type::Occupied);
        }
    }
    else if (floodFill(x, y + 1, listToDraw)) {
        for (const auto& cell : listToDraw) {
            m_matrix[cell.first][cell.second].setType(Type::Occupied);
        }
    }
    else if (floodFill(x - 1, y, listToDraw)) {
        for (const auto& cell : listToDraw) {
            int xx = cell.first;
            int yy = cell.second;
            std::cout << xx << ", " << yy << "\n";
            m_matrix[xx][yy].setType(Type::Occupied);
        }
    }
    else if (floodFill(x, y - 1, listToDraw)) {
        for (const auto& cell : listToDraw) {
            m_matrix[cell.first][cell.second].setType(Type::Occupied);
        }
    }


    

    
}

bool Board::floodFill(int x, int y, std::vector<std::pair<int, int>>& listToDraw)
{
    if (!isValid(x, y)) {
        return false;
    }
    int dRow[] = { -1, 0, 1, 0 };
    int dCol[] = { 0, 1, 0, -1 };

    std::queue<std::pair<int, int> > q;
    std::vector<std::vector<bool>> matVis = getMatVis();

    q.push({ x,y });
    listToDraw.push_back({ x,y });
    matVis[x][y] = true;

    while (!q.empty()) {
        std::pair<int, int> cell = q.front();
        x = cell.first;
        y = cell.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {    // If cell is already visited

            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (isValid(adjx, adjy) && !matVis[adjx][adjy]) {
                q.push({ adjx, adjy });
                matVis[adjx][adjy] = true;
                listToDraw.push_back({ adjx,adjy });
            }
            if (isEnemy(adjx, adjy)) {
                listToDraw.clear();
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



bool Board::isValid(int x, int y)
{

    // If cell lies out of bounds
    if (y <= 1 || y >= NUM_OF_ROWS_Y - 2 || x <= 1 || x >= NUM_OF_COLUMS_X - 2)
        return false;



    // if cell is Occupied or trail
    Type type = m_matrix[x][y].getType();
    if (type == Type::Occupied || type == Type::Trail)
        return false;
    

    // Otherwise
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






