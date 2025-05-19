#pragma once
#include <memory>
#include <stack>
#include "GameState.h"

class GameStateManager
{
private:
    std::stack<std::unique_ptr<GameState>> m_states;

public:
    void pushState(std::unique_ptr<GameState> state);

    void popState();

    void changeState(std::unique_ptr<GameState> state);

    GameState* getCurrentState();

    bool hasState() const;
};
