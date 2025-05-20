#include "ResourceManager.h"

FilesManager::FilesManager(std::string path) {
	readLevels(path);
}

int FilesManager::getWidth() const
{
	return getInstance().m_width;
}

int FilesManager::getHeight() const
{
	return getInstance().m_height;
}

int FilesManager::getLife() const
{
	return getInstance().m_life;
}

int FilesManager::getAreaToOccupy(int level)const
{
	return getInstance().m_levels[level].areaToOccupy;
}

int FilesManager::enemyNum(int level)const
{
	return getInstance().m_levels[level].enemyNum;
}

int FilesManager::getLevelCount()const
{
	return getInstance().m_levels.size();
}

FilesManager& FilesManager::getInstance()
{
	static FilesManager instance;
	return instance;
}

void FilesManager::readLevels(std::string& path)
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
