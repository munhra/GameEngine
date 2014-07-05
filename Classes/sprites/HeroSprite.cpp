/*
 * HeroSprite.cpp
 *
 *  Created on: 21/06/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/sprites/HeroSprite.h"

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
const int heroPositionX = 360;
const int heroPositionY = 640;
const int heroBodyPositionX =0;
const int heroBodyPositionY = 0;

const float SPRITE_SCALE_FACTOR = 0.55;

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
		hero->createHeroBody();
		hero->createHeroArm();
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
		CCLOG("Creating framename with name %s\n", itemFrame->getCString());
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

	this->heroBodySprite->setScale(SPRITE_SCALE_FACTOR);
	this->setPosition(ccp(heroPositionX, heroPositionY));
	this->heroBodySprite->setPosition(ccp(heroBodyPositionX,heroBodyPositionY));

	this->hero_weaponLeftx = heroPositionX + weaponleftxipad;
	this->hero_weaponRightx = heroPositionX + weaponrightxipad;
	this->hero_weaponyLeft = heroPositionY + weaponleftyipad;
	this->hero_weaponyRight = heroPositionY + weaponrightyipad;

	CCLOG("End createHeroBody");
}

void HeroSprite::createHeroArm()
{
	CCLOG("Create Hero Arm");

	this->heroArmSprite = CCSprite::create();

	Vector<SpriteFrame*> animFrames;

	CCString *itemFrame = CCString::create("rash_arm_frm");

	CCLOG("%s",itemFrame->getCString());
	for (int i = 1; i <= 4; i++) {
		CCLOG("Creating arm framename with name %s\n", itemFrame->getCString());
		CCString* framename = CCString::createWithFormat("%s%d.png", itemFrame->getCString(), i);
		CCLOG("Frame name %s", framename->getCString());
		animFrames.pushBack(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
				framename->getCString()));
	}

	CCLOG("Setting arm animation");
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames,0.09f,1);

	this->heroArmAnim = CCRepeatForever::create(CCAnimate::create(animation));
	this->heroArmSprite->runAction(this->heroArmAnim);
	CCLOG("Scalling arm sprite");
	this->heroArmSprite->setScale(SPRITE_SCALE_FACTOR);


	CCPoint anchorLeft = this->calculateAnchorPoint(ccp(anchorleftx, anchorlefty),ccp(armheight,armwidth));
	CCPoint anchorRight = this->calculateAnchorPoint(ccp(anchorrightx, anchorrighty),ccp(armheight,armwidth));
	CCLOG("Set anchor points");

	this->hero_anchorLeftY = anchorLeft.y;
	this->hero_anchorLeftX = anchorLeft.x;
	this->hero_anchorRightY = anchorRight.y;
	this->hero_anchorRightX = anchorRight.x;

	CCLOG("Arm Position X %d",hero_weaponRightx);
	CCLOG("Arm Position Y %d",hero_weaponyRight);

    CCLOG("hero_weaponRightx %d",hero_weaponRightx);
    CCLOG("hero_weaponyRight %d",hero_weaponyRight);

	this->heroArmSprite->setPosition(ccp(hero_weaponRightx,hero_weaponyRight));
	this->heroArmSprite->setAnchorPoint(anchorLeft);

	CCLOG("End createHeroArm");

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

CCPoint HeroSprite::calculateAnchorPoint(CCPoint anchorPos, CCPoint size)
{
	return ccp((1 - anchorPos.x/size.x), (1 - anchorPos.y/size.y));
}

