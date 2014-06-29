/*
 * HeroSprite.cpp
 *
 *  Created on: 21/06/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/sprites/HeroSprite.h"

const float GRAVITY_Y = -1500.0;
const float MOVE_FORCE = 2500.0;
const float JUMP_FORCE = 850.0; // old 700
const float JUMP_CUT_OFF = 1400.0;
const float VELOCITY_FACTOR = 0.90; // old 0.90

const int weaponleftx = 2;

const int weaponrightx = -4;
const int weaponrighty = 20;
const int weaponlefty = 20;
const int weaponleftxipad = 2;
const int weaponrightxipad = -4;
const int weaponrightyipad = 40;
const int weaponleftyipad = 40;
const int anchorrightx = 136;
const int anchorrighty = 6;
const int anchorleftx = 135;
const int anchorlefty = 117;
const int armwidth = 250;
const int armheight = 124;



HeroSprite::HeroSprite() {
	// TODO Auto-generated constructor stub

}

HeroSprite::~HeroSprite() {
	// TODO Auto-generated destructor stub
}

HeroSprite* HeroSprite::create()
{
	HeroSprite *hero = new HeroSprite();
	if (hero && hero->init()) {
		hero->createHeroArm();
		hero->createHeroBody();
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return NULL;
}

void HeroSprite::createHeroBody()
{
	CCLOG("Create Hero Body");
	this->heroBodySprite = CCSprite::create();

	Vector<SpriteFrame*> animFrames;
	Vector<SpriteFrame*> hitFrames;
	Vector<SpriteFrame*> deathFrames;

	CCString *itemFrame = CCString::create("rash_frm");
	CCLOG("%s",itemFrame->getCString());
	for (int i = 1; i <= 4; i++) {
		CCLOG("Creating framename with name %s\n", itemFrame);
		CCString* framename = CCString::createWithFormat("%s%d.png", itemFrame->getCString(), i);
		CCLOG("Frame name %s", framename->getCString());
		animFrames.pushBack(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
								framename->getCString()));
	}

	CCLOG("Setting animation");
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames,0.1f,1);

	this->heroBodyAnim = CCRepeatForever::create(CCAnimate::create(animation));
	this->heroBodySprite->runAction(heroBodyAnim);

	this->addChild(this->heroBodySprite);

	CCLOG("End createHeroBody");

}

void HeroSprite::createHeroArm()
{
	CCLOG("Create Hero Arm");
}

void HeroSprite::performBandDeath()
{

}

void HeroSprite::hitByEnemy(float damagePoints)
{

}

void HeroSprite::hitByEnemy(float damagePoints, CCRect rect)
{

}

void HeroSprite::performBandBlast()
{

}

void HeroSprite::receiveHealthPowerUp(float value)
{

}

void HeroSprite::runShootAnimation()
{

}

float HeroSprite::getTotalArmor()
{

}

