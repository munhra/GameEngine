/*
 * Enemy.h
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "cocos2d.h"
#include "sprites/HeroShoot.h"
#include "enemies/EnemyParams.h"
#include "scenes/GamePlayScene.h"

using namespace cocos2d;

typedef enum {
		POS1,
		POS2,
		POS3,
		POS4,
		POS5,
		POS6,
		POS7,
		POS8
	} EnemyPositions;

class Enemy : public CCSprite{
public:

	Enemy();
	virtual ~Enemy();



	//-(id)initwithStartPosition:(CGPoint)position actionTime:(double)time delegate:(id)scnDelegate enemyParams:(EnemyParams *)params
	//		enemyPosition:(EnemyPositions)defPosition shootEndPos:(CGPoint)shootEnd;


	static Enemy* createWithStartPosition(CCPoint position, double actionTime,
			GamePlayScene *scnDelegate, EnemyParams *params, EnemyPositions defPositions, CCPoint ShootEndPosition);

	static Enemy* create();

	void startMovement();
	int receiveHeroShoot(float damange, bool killNow, CCRect rect);
	void performDeath();
	void fireWeapon();
	float autoDestruction();

	// how many points left from the armor.
	float armor;

	// delay to enter in action in seconds defined by the level json file.
	float delayToAction;
	// weapon damage of the robot
	float weaponDamage;
	// time to reach hero seconds
	double timeToReach;
	// type of power up
	//PowerUp powerupType;



	CCPoint initialPosition;
	//position to make the action of shoot cross the screen
	CCPoint shootPosition;

	CCSprite *enemySprite;
	CCSprite *shootSprite;
	CCAction *enemyAction;
	CCAction *enemyAttack;
	CCSpriteBatchNode *enemysprtSheet;

	CCParticleSystem *enemyParticle;

	// Controls the shoot lifecycle
	//NSMutableArray *activeEnemies;

	Vector<Enemy*> activeEnemies;


	bool removeObject;

	//NSTimer *enemyTimer;

	int scorePoints;

	GamePlayScene *delegate;

	CCString *name;

	int frames;

	EnemyPositions definedPosition;
	AttackType attackType;
    PowerUp typeOfPowerUp;


	/*
	-(id)initwithStartPosition:(CGPoint)position actionTime:(double)time delegate:(id)scnDelegate enemyParams:(EnemyParams *)params enemyPosition:(EnemyPositions)defPosition shootEndPos:(CGPoint)shootEnd;
	-(void)startMovement;
	-(int)receiveHeroShoot:(float)damage killNow:(BOOL)value shootRect:(CGRect)rect;
	-(void)performDeath;
	-(void)fireWeapon;
	-(float)autoDestruction;
	 */




};

#endif /* ENEMY_H_ */
