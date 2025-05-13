#pragma once
#include <string>
#include <vector>
#include "fstream"

struct Level {
	int areaToOccupy;
	int enemyNum;
};

class ResourceManager {
public:
	ResourceManager(std::string path = "levels.txt");
	int getWidth() const;
	int getHeight() const;
	int getLife() const;
	int getAreaToOccupy(int level);
	int enemyNum(int level);
	int getLevelCount();

private:
	void readLevels(std::string& path);
	int m_width, m_height, m_life;
	std::vector<Level> m_levels;

	
};