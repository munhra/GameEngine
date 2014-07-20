/*
 * Enemy.cpp
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/enemies/Enemy.h"

Enemy::Enemy() {
	// TODO Auto-generated constructor stub

}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}


Enemy* Enemy::createWithStartPosition(CCPoint position, double actionTime,
		GamePlayScene *scnDelegate, EnemyParams *params, EnemyPositions defPositions, CCPoint ShootEndPosition)
{
	Enemy *enemy = new Enemy();
	if (enemy && enemy->init()) {
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}


Enemy* Enemy::create()
{
	Enemy *enemy = new Enemy();
	if (enemy && enemy->init()) {
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}

void Enemy::startMovement()
{

}

int Enemy::receiveHeroShoot(float damange, bool killNow, CCRect rect)
{
	return 0;
}

void Enemy::performDeath()
{

}

void Enemy::fireWeapon()
{

}

float Enemy::autoDestruction()
{
	return 0.0;
}
