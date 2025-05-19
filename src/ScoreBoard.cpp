#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(sf::Vector2f size, sf::Vector2f pos)
{
	m_scoreBoard.setSize(size);
	setCharacterSize(20);
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
}

void ScoreBoard::update(Player* player)
{
	m_scoreText.setString("Score: " + std::to_string(player->getScore()));
	m_lifeText.setString("Life: " + std::to_string(player->getLife()));
	m_areaText.setString("Area: " + std::to_string(player->getOccupiedAreaPercent()) + "%");
}

void ScoreBoard::setPos(sf::Vector2f& pos)
{
	m_scoreBoard.setPosition(pos);
	m_scoreText.setPosition(pos.x + 10, pos.y + 10);
	m_lifeText.setPosition(pos.x + 10, pos.y + 40);
	m_areaText.setPosition(pos.x + 10, pos.y + 70);
}

void ScoreBoard::defineFont()
{
	m_scoreText.setFont(FontManager::getInstance().getFont());
	m_lifeText.setFont(FontManager::getInstance().getFont());
	m_areaText.setFont(FontManager::getInstance().getFont());
}

void ScoreBoard::fillColor()
{
	m_scoreBoard.setFillColor(sf::Color::White);
	m_scoreText.setFillColor(sf::Color::Black);
	m_lifeText.setFillColor(sf::Color::Black);
	m_areaText.setFillColor(sf::Color::Black);
}

void ScoreBoard::setCharacterSize(unsigned int size)
{

	m_scoreText.setCharacterSize(size);
	m_lifeText.setCharacterSize(size);
	m_areaText.setCharacterSize(size);
}
