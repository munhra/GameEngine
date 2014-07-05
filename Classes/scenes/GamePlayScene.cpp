/*
 * GamePlayScene.cpp
 *
 *  Created on: 15/06/2014
 *      Author: munhra
 */

#include "GamePlayScene.h"
#include "scenes/GameHud.h"
#include "sprites/HeroSprite.h"

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
	return true;
}

void GamePlayScene::update(float dt)
{
	//CCLOG("Update !!!");
}

float GamePlayScene::getRotationAngle()
{

	/*
	float normaBegin = sqrtf(powf(self.beginTouch.x,2)+pow(self.beginTouch.y,2));
	    float normaEnd = sqrtf(powf(self.endTouch.x,2)+powf(self.endTouch.y,2));
	    float dotProduct = self.beginTouch.x * self.endTouch.x + self.beginTouch.y * self.endTouch.y;
	    float angleDegrees = [self convertRadToDegree:acosf(dotProduct/(normaEnd*normaBegin))];
	    if (self.endTouch.x < 0) {
	        return 360 - angleDegrees;
	    }else{
	        return angleDegrees;
	    }
	 */
	return 0.0;
}

void GamePlayScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
	CCLOG("onTouchesBegan");

	for (auto touch: touches){

		CCPoint location = this->convertTouchToNodeSpace(touch);

		location.x = location.x - this->heroSprite->getPosition().x;
		location.y = location.y - this->heroSprite->getPosition().y;

		endTouch = location;
		rotationAngle = this->getHeroRotationAngle();
		moved = true;

		//if ([[self bandSprite] guita1ReleaseFire] == YES) {
		//	        [self fireLaser:[self convertTouchToNodeSpace:touch]];
		//}

	}
}

void GamePlayScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event)
{
	CCLOG("onTouchesMoved");

	for (auto touch: touches){

		CCPoint location = this->convertTouchToNodeSpace(touch);
		location.x = location.x - this->heroSprite->getPosition().x;
		location.y = location.y - this->heroSprite->getPosition().y;
		endTouch = location;
		rotationAngle = this->getHeroRotationAngle();
		moved = true;

		//this->heroSprite->heroReleaseFire = false;

		if (this->heroSprite->heroReleaseFire == true) {
			//[self fireLaser:[self convertTouchToNodeSpace:touch]];
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
		//if ([[self bandSprite] guita1ReleaseFire] == YES) {
		//	[self fireLaser:[self convertTouchToNodeSpace:touch]];
		//}
	}
}

void GamePlayScene::onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event)
{
	CCLOG("onTouchesCancelled");
}

bool shootCollidedToTarget()
{
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

CCPoint fireCirclePoint()
{
	return 0;
}


void doEndFire(CCNode *node)
{

}


void fireLaser(CCPoint *touchEndPoint)
{

}

float GamePlayScene::getHeroRotationAngle()
{

	float normaBegin = sqrtf(powf(beginTouch.x,2)+pow(beginTouch.y,2));
	float normaEnd = sqrtf(powf(endTouch.x,2)+powf(endTouch.y,2));
	float dotProduct = beginTouch.x * endTouch.x + beginTouch.y * endTouch.y;
	float angleDegrees = this->convertRadToDegree(acosf(dotProduct/(normaEnd*normaBegin)));

	if (endTouch.x < 0) {
		return 360 - angleDegrees;
	}else{
		return angleDegrees;
	}

}

void removeEnemySprite(CCSprite *enemySprite)
{

}

void addEnemySprite(CCSprite *enemy)
{

}

bool isGameOver()
{
	return false;
}

void pauseGame()
{

}




