#pragma once
#include <string>
#include <vector>
#include "fstream"

struct Level {
	int areaToOccupy;
	int enemyNum;
};

class FilesManager {
public:
	int getWidth() const;
	int getHeight() const;
	int getLife() const;
	int getAreaPercentToOccupy(int level)const;
	int enemyNum(int level) const;
	int getLevelCount() const;
	FilesManager(std::string path = "levels.txt");
private:
	bool islevelValid(int level) const;
	void readLevels(std::string& path);
	int m_width, m_height, m_life;
	std::vector<Level> m_levels;

	
};