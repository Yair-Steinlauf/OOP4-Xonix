#include "GameStateManager.h"

void GameStateManager::pushState(std::unique_ptr<GameState> state)
{
	m_states.push(std::move(state));
}

void GameStateManager::popState()
{
	if (!m_states.empty())
		m_states.pop();
}

void GameStateManager::changeState(std::unique_ptr<GameState> state)
{
		popState();
		pushState(std::move(state));
}

GameState* GameStateManager::getCurrentState()
{
	return m_states.empty() ? nullptr : m_states.top().get();
}

bool GameStateManager::hasState() const
{
	return !m_states.empty();
}
