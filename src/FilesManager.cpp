#include "FilesManager.h"

FilesManager::FilesManager(std::string path) {
	readLevels(path);
}

int FilesManager::getWidth() const
{
	return m_width;
}

int FilesManager::getHeight() const
{
	return m_height;
}

int FilesManager::getLife() const
{
	return m_life;
}

int FilesManager::getAreaPercentToOccupy(int level)const
{
	islevelValid(level);
	return m_levels[level].areaToOccupy;
}

int FilesManager::enemyNum(int level)const
{
	islevelValid(level);
	return m_levels[level].enemyNum;
}

int FilesManager::getLevelCount()const
{
	return m_levels.size();
}



bool FilesManager::islevelValid(int level) const
{
	if (level >= 0 && level < m_levels.size()) {
		return true;
	}
	throw std::out_of_range("Level out of range: " + std::to_string(level));
	return false;
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
