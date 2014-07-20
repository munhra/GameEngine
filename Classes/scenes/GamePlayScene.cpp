/*
 * GamePlayScene.cpp
 *
 *  Created on: 15/06/2014
 *      Author: munhra
 */

#include "GamePlayScene.h"
#include "scenes/GameHud.h"
#include "sprites/HeroSprite.h"
#include "sprites/HeroShoot.h"

using namespace cocos2d;

GamePlayScene::GamePlayScene() {
	// TODO Auto-generated constructor stub

}

GamePlayScene::~GamePlayScene() {
	// TODO Auto-generated destructor stub
}
Scene* GamePlayScene::createScene(int levelNumber, int waveNumber)
{
	auto scene = Scene::create();
	auto hud = GameHud::create();
	scene->addChild(hud,1);
	auto layer = GamePlayScene::create();
	scene->addChild(layer);
	levelNumber = levelNumber;
	waveNumber = waveNumber;


	return scene;
}

void GamePlayScene::initBandPositions()
{

}

Scene* GamePlayScene::initWithHudAndLevel(GameHud *hud,int level, int wave)
{
	return NULL;
}

Scene* GamePlayScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GamePlayScene::create();
	scene->addChild(layer);
	return scene;
}

bool GamePlayScene::init()
{
	this->initBandPositions();
	CCSprite* background = CCSprite::create("backgrounds/IpadSt1BG.jpg");
	background->setTag(1);
	background->setAnchorPoint(CCPointMake(0, 0));
	this->addChild(background,0);
	this->schedule(schedule_selector(GamePlayScene::update));
	this->heroSprite = HeroSprite::create();
	this->addChild(this->heroSprite,34);
	this->addChild(this->heroSprite->heroArmSprite,35);
	this->setTouchEnabled(true);
	this->beginTouch = ccp(0,160);
	return true;
}

void GamePlayScene::update(float dt)
{
	//CCLOG("Update !!!");
}

void GamePlayScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	CCLOG("onTouchesBegan");
	CCPoint location;

	for (auto touch: touches){

		location = this->convertTouchToNodeSpace(touch);

		location.x = location.x - this->heroSprite->getPosition().x;
		location.y = location.y - this->heroSprite->getPosition().y;

		endTouch = location;
		rotationAngle = this->getHeroRotationAngle();
		moved = true;

		if (this->heroSprite->heroReleaseFire == true){
			this->fireLaser(location);
		}
	}
}

void GamePlayScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	//CCLOG("onTouchesMoved");

	for (auto touch: touches){

		CCPoint location = this->convertTouchToNodeSpace(touch);
		location.x = location.x - this->heroSprite->getPosition().x;
		location.y = location.y - this->heroSprite->getPosition().y;
		endTouch = location;
		rotationAngle = this->getHeroRotationAngle();
		moved = true;

		//this->heroSprite->heroReleaseFire = false;

		if (this->heroSprite->heroReleaseFire == true) {
			this->fireLaser(location);
		}
	}
}

void GamePlayScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event)
{
	CCLOG("onTouchesEnded");

	for (auto touch: touches){
		CCPoint location = this->convertTouchToNodeSpace(touch);
		location.x = location.x - this->heroSprite->getPosition().x;
		location.y = location.y - this->heroSprite->getPosition().y;
		endTouch = location;
		rotationAngle = this->getHeroRotationAngle();
		moved = true;

		if (this->heroSprite->heroReleaseFire == true) {
			this->fireLaser(location);
		}

	}
}

void GamePlayScene::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	CCLOG("onTouchesCancelled");
}

bool GamePlayScene::shootCollidedToTarget()
{
	CCRect targetRect;
	CCRect shootRect;
	CCRect heroRect = this->heroSprite->getBoundingBox();

	for (auto enemy: this->activeEnemies){
        //targetRect = [[[[self activeEnemies] objectAtIndex:j] enemySprite] boundingBox];
		//()
	}

	for (auto enemy: this->activeEnemies){

	}

	return true;
}

float GamePlayScene::convertDegreeToRad(float angle)
{
	return (angle/180)*M_PI;
}

float GamePlayScene::convertRadToDegree(float angle)
{
	return (180/M_PI)*angle;
}

CCPoint GamePlayScene::fireCirclePoint()
{
	CCPoint circle;
	circle.x = 320 + 1000*sin(this->convertDegreeToRad(rotationAngle));
	circle.x = 640 + 1000*cos(this->convertDegreeToRad(rotationAngle));
	return circle;
}


void GamePlayScene::doEndFire(CCNode *node)
{
	CCLOG("doEndFire !!!");
    ((HeroShoot *)node)->removeObject = true;
    this->removeChild(node,true);
}


void GamePlayScene::fireLaser(CCPoint touchEndPoint)
{
	CCLOG("fireLaser(CCPoint touchEndPoint)");

	//CCDirector::sharedDirector()->getWinSize();

	CCPoint shootPoint;
	CCPoint targetPoint;
	HeroShoot *laserbean;

	targetPoint = this->fireCirclePoint();
	laserbean = HeroShoot::create(CCString::create("misc/laser1.png"));

	heroSprite->activeShoots.pushBack(laserbean);
	CCLOG("Active shoot incerted !");
	laserbean->setRotation(rotationAngle+90);
	CCLOG("Rotation angle %f",rotationAngle);
	heroSprite->heroArmSprite->setRotation(rotationAngle+270);



	if ((rotationAngle <= 360) && (rotationAngle >= 180)) {
		//rotate guitar 1

		if (heroSprite->isHeroDeath == false){
			heroSprite->heroArmSprite->setFlipX(true);
			heroSprite->heroArmSprite->setFlipY(true);
			heroSprite->heroArmSprite->setPosition(ccp(heroSprite->hero_weaponLeftx,heroSprite->hero_weaponyLeft));
			heroSprite->setAnchorPoint(ccp(heroSprite->hero_anchorLeftX,heroSprite->hero_anchorLeftY));

		}
		//shootPoint = ccp([[self bandSprite]guita1_weaponLeftx],[[self bandSprite] guita1_weaponyLeft] - 30);
		shootPoint = ccp(this->heroSprite->hero_weaponLeftx,this->heroSprite->hero_weaponyLeft - 30);

	}else{

		if (heroSprite->isHeroDeath == false){
			heroSprite->heroArmSprite->setFlipX(false);
			heroSprite->heroArmSprite->setFlipY(false);
			heroSprite->heroArmSprite->setPosition(ccp(heroSprite->hero_weaponRightx,heroSprite->hero_weaponyRight));
			heroSprite->setAnchorPoint(ccp(heroSprite->hero_anchorRightX,heroSprite->hero_anchorRightY));
		}
		shootPoint = ccp(this->heroSprite->hero_weaponRightx + 10,this->heroSprite->hero_weaponyRight - 30);
		//shootPoint = ccp([[self bandSprite]guita1_weaponRightx] + 10, [[self bandSprite] guita1_weaponyRight] - 30);
	}

	CCLOG("Arm position x %f",heroSprite->heroArmSprite->getPositionX());
	CCLOG("Arm position y %f",heroSprite->heroArmSprite->getPositionY());


	if (heroSprite->isHeroDeath == false){
		laserbean->setPosition(shootPoint);
		this->addChild(laserbean);
		laserbean->stopAllActions();

		CCFiniteTimeAction *actionFire = CCMoveTo::create(0.5,targetPoint);
		CCFiniteTimeAction *endFireCallBack = CCCallFuncN::create(CC_CALLBACK_1(GamePlayScene::doEndFire, this));
		CCSequence *actionSequence = CCSequence::create(actionFire,endFireCallBack,NULL);

		laserbean->runAction(actionSequence);
		this->heroSprite->runShootAnimation();

	}
}

float GamePlayScene::getHeroRotationAngle()
{

	float normaBegin = sqrtf(powf(beginTouch.x,2)+pow(beginTouch.y,2));
	float normaEnd = sqrtf(powf(endTouch.x,2)+powf(endTouch.y,2));
	float dotProduct = beginTouch.x * endTouch.x + beginTouch.y * endTouch.y;
	float angleDegrees = this->convertRadToDegree(acosf(dotProduct/(normaEnd*normaBegin)));

	if (endTouch.x < 0) {
		CCLOG("Returning rotation angle %f",360 - angleDegrees);
		return 360 - angleDegrees;
	}else{
		CCLOG("Returning rotation angle %f",angleDegrees);
		return angleDegrees;
	}

}

void removeEnemySprite(CCSprite *enemySprite)
{

}

void GamePlayScene::addEnemySprite(CCSprite *enemy)
{

}

bool GamePlayScene::isGameOver()
{
	if (this->state == GAME_OVER){
		return true;
	}else{
		return false;
	}
}

void pauseGame()
{

}
