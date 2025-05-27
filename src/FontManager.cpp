#include "FontManager.h"

FontManager& FontManager::getInstance()
{
	static FontManager instance;
	return instance;
}

const sf::Font& FontManager::getFont() const
{
	return m_arial;	
}

FontManager::FontManager()
{
	if (!m_arial.loadFromFile("arial.ttf")) {
		throw std::runtime_error("Failed to load font");
	}
}
