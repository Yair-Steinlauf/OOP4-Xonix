#include "FilesManager.h"
#include <regex>
#include <sstream>
#include <string>

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
		throw std::runtime_error("Failed to open file: " + path + "\n");
	}

	std::istringstream input;
	std::string line;
	if(!std::getline(file, line))
		throw std::runtime_error("File: " + path + " is empty\n");

	std::regex firstLineRegex(R"(^\d+\s+\d+\s+\d+$)");
	if (std::regex_match(line, firstLineRegex) == false)
		throw std::runtime_error("File: " + path + " is not valid\n");
	input.str(line);
	input >> m_width >> m_height >> m_life;
	
	if (m_width <= 0 || m_height <= 0 || m_life <= 0)
		throw std::runtime_error("File parameters: " + path + " is not valid\n");
	
	
	std::regex levelRegex(R"(^\d+\s+\d+$)");
	int area, enemies;
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		if (std::regex_match(line, levelRegex) == false)
			throw std::runtime_error("File: " + path + " is not valid\n");
		input.clear();
		input.str(line);
		input >> area >> enemies;
		m_levels.push_back(Level{ area, enemies });
	}
}
