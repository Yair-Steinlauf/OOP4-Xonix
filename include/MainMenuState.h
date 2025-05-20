#pragma once

#include "GameState.h"
#include "GameStateManager.h"	
#include "SFML/Graphics.hpp"
#include "FontManager.h"
class FilesManager;
class GamePlayState;


class MainMenuState : public GameState
{
public:
	MainMenuState(sf::RenderWindow* window, GameStateManager* manager, FilesManager* fileManager);
	void handleEvent(sf::Event& event) override;
	void update(sf::Time dt) override {}
	void render(sf::RenderWindow& window) override;
private:
	sf::Text m_titleText;
	sf::Text m_subTitleText;
};