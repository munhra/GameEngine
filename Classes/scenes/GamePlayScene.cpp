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
    this->heroSprite->setPosition(ccp(200, 450));
    this->addChild(this->heroSprite,34);
	return true;
}

void GamePlayScene::update(float dt)
{

}

bool GamePlayScene::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void GamePlayScene::onTouchMoved(Touch *touch, Event *unused_event)
{

}

void GamePlayScene::onTouchEnded(Touch *touch, Event *unused_event)
{

}

void GamePlayScene::onTouchCancelled(Touch *touch, Event *unused_event)
{

}

bool shootCollidedToTarget()
{
	return true;
}

float convertDegreeToRad(float angle)
{
	return 0.0;
}

float convertRadToDegree(float angle)
{
	return 0.0;
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

float getHeroRotationAngle()
{
	return 0.0;
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




