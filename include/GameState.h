#pragma once
#include <SFML/Graphics.hpp>
//#include "GameStateManager.h"
class GameStateManager;

class GameState {
public:
    GameState(sf::RenderWindow* window = nullptr, GameStateManager* manager = nullptr);

    virtual ~GameState() = default;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
protected:
    sf::RenderWindow* m_window;
    GameStateManager* m_manager;
};