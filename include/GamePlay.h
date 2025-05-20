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
    int m_level = 0;
    FilesManager m_resourceManager;
    int m_pixelY;
    int m_pixelX;
	ScoreBoard m_scoreBoard;
	std::unique_ptr<Player> m_player;
    Board m_board;
};
