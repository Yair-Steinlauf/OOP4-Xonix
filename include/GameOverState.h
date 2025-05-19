#pragma once
#include "FontManager.h"
#include "GameState.h"
#include "GameStateManager.h"

class GameOverState : public GameState {
public:
	GameOverState(sf::RenderWindow& window, GameStateManager& manager);

	void handleEvent(sf::Event& event) override;
	void update(sf::Time dt) override {}
	void render(sf::RenderWindow& window) override;
private:
	sf::RenderWindow& m_window;
	GameStateManager& m_manager;
	sf::Text m_gameOverText;
	sf::Font m_font;
};