#pragma once
#include <SFML/Graphics.hpp>
#include "FontManager.h"
#include "Player.h"

class ScoreBoard {
public:
	ScoreBoard(sf::Vector2f size, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	void update(Player* player);
private:
	void setPos(sf::Vector2f& pos);
	void defineFont();
	void fillColor();
	void setCharacterSize(unsigned int siz);
	Player* m_player;
	sf::RectangleShape m_scoreBoard;
	sf::Text m_scoreText;
	sf::Text m_lifeText;
	sf::Text m_areaText;


};