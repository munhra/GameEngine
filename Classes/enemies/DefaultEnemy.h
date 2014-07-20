/*
 * DefaultEnemy.h
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#ifndef DEFAULTENEMY_H_
#define DEFAULTENEMY_H_

#include "cocos2d.h"
#include "enemies/Enemy.h"
#include "/Users/munhra/MunhraGames/MyGame/Classes/util/UniversalInfo.h"

using namespace cocos2d;

class DefaultEnemy : public Enemy{
public:
	DefaultEnemy();
	virtual ~DefaultEnemy();

	DefaultEnemy* createWithStartPosition(CCPoint position, double actionTime,
			GamePlayScene *scnDelegate, EnemyParams *params, EnemyPositions defPositions, CCPoint ShootEndPosition);

	void divideAnimations(CCSpriteFrame *frame, Vector<SpriteFrame*> animFrames,
			Vector<SpriteFrame*> attackFrames, int frameidx);

	void startMovement(float dt);
	void performDeath();
	void doEndGenHitAnim(CCNode *node);
	void doEndAttackAnim(CCNode *node);
	void fireWeapon(float dt);
	void doEndRobotFire(CCNode* node);
	void doEndDeathAnimation(CCNode *node);
	int receiveHeroShoot(float damage, bool killNow, CCRect shootRect);
	float autoDestruction();

private:

	UniversalInfo *uninfo;
};

#endif /* DEFAULTENEMY_H_ */
