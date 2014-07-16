/*
 * EnemyParams.h
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#ifndef ENEMYPARAMS_H_
#define ENEMYPARAMS_H_

#include "cocos2d.h"
#include "sprites/HeroShoot.h"

using namespace cocos2d;

typedef enum {
		MEELEE,
		AUTODESTRUCTION,
		WALK_SHOOT
	} AttackType;


	typedef enum {
		GUNPOWER_1,
		GUNPOWER_2,
		HEALTHPOWER,
		RADIOPOWER,
		COIN,
		NOPOWERUP
	} PowerUp;

class EnemyParams : public CCSprite{
public:

	EnemyParams();
	virtual ~EnemyParams();

	CCString *enemyName;
	float armor;
	float weaponDamage;
	float scorePoints;
	int numberOfFrames;
	double timeToReach;
	PowerUp typeOfPowerUp;
	AttackType atackType;

};

#endif /* ENEMYPARAMS_H_ */
