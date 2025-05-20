#include "ScoreBoard.h"
#include "FilesManager.h"


ScoreBoard::ScoreBoard(sf::Vector2f size, sf::Vector2f pos)
{
	m_scoreBoard.setSize(size);
	setCharacterSize(100);
	fillColor();
	defineFont();
	setPos(pos); 
}


void ScoreBoard::draw(sf::RenderWindow& window)
{
	window.draw(m_scoreBoard);
	window.draw(m_scoreText);
	window.draw(m_lifeText);
	window.draw(m_areaText);
	window.draw(m_levelText);
}

void ScoreBoard::update(Player* player, int level)
{
	m_scoreText.setString("Score: " + std::to_string(player->getScore()));
	m_lifeText.setString("Life: " + std::to_string(player->getLife()));
	m_areaText.setString("Area: " + std::to_string(player->getOccupiedAreaPercent()).substr(0, 3) + "%");
	m_levelText.setString("Level: " + std::to_string(level +1));//TODO: add level number
}

void ScoreBoard::setPos(sf::Vector2f& pos)
{
	m_scoreBoard.setPosition(pos);
	auto newPos = sf::Vector2f(pos.x + 10, pos.y + 10);
	m_scoreText.setPosition(newPos.x, newPos.y);
	m_lifeText.setPosition(newPos.x + 400, newPos.y);
	m_areaText.setPosition(newPos.x + 650, newPos.y);
	m_levelText.setPosition(newPos.x + 1000, newPos.y);
}

void ScoreBoard::defineFont()
{
	m_scoreText.setFont(FontManager::getInstance().getFont());
	m_lifeText.setFont(FontManager::getInstance().getFont());
	m_areaText.setFont(FontManager::getInstance().getFont());
	m_levelText.setFont(FontManager::getInstance().getFont());
}

void ScoreBoard::fillColor()
{
	m_scoreBoard.setFillColor(sf::Color::White);
	m_scoreText.setFillColor(sf::Color::Black);
	m_lifeText.setFillColor(sf::Color::Black);
	m_areaText.setFillColor(sf::Color::Black);
	m_levelText.setFillColor(sf::Color::Black);
}

void ScoreBoard::setCharacterSize(unsigned int size)
{

	m_scoreText.setCharacterSize(size);
	m_lifeText.setCharacterSize(size);
	m_areaText.setCharacterSize(size);
	m_levelText.setCharacterSize(size);
}
