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
	int getAreaToOccupy(int level)const;
	int enemyNum(int level) const;
	int getLevelCount() const;
	static FilesManager& getInstance();
private:
	FilesManager(const FilesManager&) = delete;
	FilesManager(std::string path = "levels.txt");
	FilesManager& operator=(const FilesManager&) = delete;
	void readLevels(std::string& path);
	int m_width, m_height, m_life;
	std::vector<Level> m_levels;

	
};