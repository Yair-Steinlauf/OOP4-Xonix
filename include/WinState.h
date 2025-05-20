#pragma once

#include "GameState.h"
#include "FontManager.h"
#include "GameStateManager.h"
#include "memory"
#include "GamePlay.h";


class WinState : public GameState {
public:
	WinState(int score, sf::RenderWindow* window, GameStateManager* manager);
	void handleEvent(sf::Event& event) override;
	void update(sf::Time dt) override {}
	void render(sf::RenderWindow& window) override;
private:

	sf::Text m_title;
	sf::Text m_subTitle;
};
