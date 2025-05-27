#pragma once

#include <SFML/Graphics.hpp>

class FontManager {
public:
	static FontManager& getInstance();
	const sf::Font& getFont() const;
	FontManager& operator=(const FontManager&) = delete;
	FontManager(const FontManager&) = delete;
private:
	sf::Font m_arial;
	FontManager();
	~FontManager() = default;
};