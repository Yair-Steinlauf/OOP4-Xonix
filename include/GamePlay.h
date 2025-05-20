#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "FilesManager.h"
#include "Board.h"
#include "Player.h"
#include "ScoreBoard.h"


class GamePlayState : public GameState {
public:
    GamePlayState(sf::RenderWindow* window, GameStateManager* manager);

    void handleEvent(sf::Event& event) override;

    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

private:
    void nextLevel();
    void setPlayerDirection();
    FilesManager m_resourceManager;
	ScoreBoard m_scoreBoard;
    Board m_board;
    int m_level = 0;
	std::unique_ptr<Player> m_player;
    int m_pixelY;
    int m_pixelX;
};
