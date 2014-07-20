/*
 * DefaultEnemy.cpp
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/enemies/DefaultEnemy.h"
#include "/Users/munhra/MunhraGames/MyGame/Classes/enemies/EnemyParams.h"
#include "/Users/munhra/MunhraGames/MyGame/Classes/util/UniversalInfo.h"

DefaultEnemy::DefaultEnemy() {
	// TODO Auto-generated constructor stub

}

DefaultEnemy::~DefaultEnemy() {
	// TODO Auto-generated destructor stub
}


DefaultEnemy* DefaultEnemy::createWithStartPosition(CCPoint position, double actionTime,
		GamePlayScene *scnDelegate, EnemyParams *params, EnemyPositions defPositions, CCPoint shootEnd)
{
	DefaultEnemy *defaultEnemy = new DefaultEnemy();
	if (defaultEnemy && defaultEnemy->init()) {

		this->shootPosition = shootEnd;
		this->initialPosition = position;

		this->armor = params->armor;
		this->weaponDamage = params->weaponDamage;
		this->scorePoints = params->scorePoints;
		this->timeToReach = params->timeToReach;
		this->typeOfPowerUp = params->typeOfPowerUp;
		this->name = params->enemyName;
		this->frames = params->numberOfFrames;
		this->definedPosition = defPositions;
		this->attackType = params->atackType;


		Vector<SpriteFrame*>animFrames;
		Vector<SpriteFrame*>attackFrames;

		this->enemySprite = CCSprite::create();

		if ((defPositions == POS8) || (defPositions == POS7) || (defPositions == POS1)){
			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_back_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}
			if (defPositions == POS7) {
				this->enemySprite->setFlipX(true);
			}

		}else if ((defPositions == POS3) || (defPositions == POS4) || (defPositions == POS5)) {

			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_front_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}

		}else{
			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_left_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}
			this->enemySprite->setFlipX(true);
			if (defPositions == POS2) {
				this->enemySprite->setFlipX(false);
			}
		}

        enemySprite->setScaleX(0.50);
        enemySprite->setScaleY(0.50);

        CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames,0.09f);
        CCAnimation *attackAnimation = CCAnimation::createWithSpriteFrames(attackFrames,0.2f);

        this->enemySprite->setPosition(position);
        // restore original frame ?
        this->enemyAction = CCRepeatForever::create(CCAnimate::create(animation));


        CCAnimate *attackAnim = CCAnimate::create(attackAnimation);
        CCFiniteTimeAction *endAnimationCallback = CCCallFuncN::create(CC_CALLBACK_1(DefaultEnemy::doEndAttackAnim, this));
        this->enemyAttack = CCSequence::create(attackAnim,endAnimationCallback,NULL);

        this->enemySprite->runAction(this->enemyAction);
        this->delegate = scnDelegate;
        this->uninfo = UniversalInfo::create();
        this->schedule(schedule_selector(DefaultEnemy::startMovement),actionTime);

		return defaultEnemy;
	}
	CC_SAFE_DELETE(defaultEnemy);
	return NULL;

}

void DefaultEnemy::divideAnimations(CCSpriteFrame *frame, Vector<SpriteFrame*> animFrames,
		Vector<SpriteFrame*> attackFrames, int frameidx){

	switch(frameidx){
	case 1:
		animFrames.pushBack(frame);
		break;
	case 3:
		animFrames.pushBack(frame);
		attackFrames.pushBack(frame);
		break;
	case 4:
		attackFrames.pushBack(frame);
		break;
	default:
		break;
	}
}

void DefaultEnemy::performDeath()
{

}

void DefaultEnemy::startMovement(float dt)
{

	if (this->delegate->isGameOver() == false){
		this->delegate->addEnemySprite(this);
		this->enemySprite->runAction(CCMoveTo::create(this->timeToReach,this->uninfo->screenCenter()));
	}

	this->unscheduleAllSelectors();

	if (this->delegate->isGameOver() == false){
        if (this->attackType == WALK_SHOOT){
        	this->schedule(schedule_selector(DefaultEnemy::fireWeapon),0.5 + rand() % 11 * 0.1);
        }
	}
}

void DefaultEnemy::doEndGenHitAnim(CCNode *node)
{

}

void DefaultEnemy::doEndAttackAnim(CCNode *node)
{

}

void DefaultEnemy::fireWeapon(float dt)
{

}

void DefaultEnemy::doEndRobotFire(CCNode* node)
{

}

void DefaultEnemy::doEndDeathAnimation(CCNode *node)
{

}

int DefaultEnemy::receiveHeroShoot(float damage, bool killNow, CCRect shootRect)
{

}

float DefaultEnemy::autoDestruction()
{

}

