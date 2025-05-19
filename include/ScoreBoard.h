#pragma once
#include <SFML/Graphics.hpp>
#include "FontManager.h"
#include "Player.h"

class ScoreBoard {
public:
	ScoreBoard(Player* player);
	void draw(sf::RenderWindow& window);
	void update(int score, int life);
	void reset();

};