#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "FilesManager.h"
#include "Board.h"
#include "Player.h"
#include "ScoreBoard.h"


class GamePlayState : public GameState {
public:
    GamePlayState(sf::RenderWindow* window, GameStateManager* manager, FilesManager* fileManager);

    void handleEvent(sf::Event& event) override;

    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

private:
    void setPlayerDirection();
    FilesManager* m_resourceManager;
	ScoreBoard m_scoreBoard;
    Board m_board;
	std::shared_ptr<Player> m_player;
};
