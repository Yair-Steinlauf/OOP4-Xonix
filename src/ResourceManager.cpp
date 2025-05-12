#include "ResourceManager.h"

ResourceManager::ResourceManager(std::string path) {
	readLevels(path);
}

int ResourceManager::getWidth() const
{
	return m_width;
}

int ResourceManager::getHeight() const
{
	return m_height;
}

int ResourceManager::getLife() const
{
	return m_life;
}

int ResourceManager::getAreaToOccupy(int level)
{
	return m_levels[level].areaToOccupy;
}

int ResourceManager::enemyNum(int level)
{
	return m_levels[level].enemyNum;
}

int ResourceManager::getLevelCount()
{
	return m_levels.size();
}

void ResourceManager::readLevels(std::string& path)
{
	std::ifstream file(path);
	if (!file) {
		throw std::runtime_error("Failed to open file: " + path);
	}

	file >> m_width >> m_height >> m_life;

	int area, enemies;
	while (file >> area >> enemies) {
		m_levels.push_back(Level{ area, enemies });
	}
}
