#include "Enemy.h"


Enemy::Enemy(sf::Vector2i startPos) 
	:MovingObject(startPos, enemySpeed) 
{

}

void Enemy::changeDirection()
{
	//TODO: change direction algo
}
