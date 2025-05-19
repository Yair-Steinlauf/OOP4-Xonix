#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "ResourceManager.h"
#include "Board.h"
#include "Player.h"

class GamePlayState : public GameState {
public:
    GamePlayState(sf::RenderWindow& window, GameStateManager& manager);

    void handleEvent(sf::Event& event) override;

    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

private:
    void setPlayerDirection();
    sf::RenderWindow& m_window;
    GameStateManager& m_manager;
    FilesManager* m_resourceManager;
    std::shared_ptr<Player> m_player;
    Board m_board;
};
