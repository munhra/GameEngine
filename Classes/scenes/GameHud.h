/*
 * GameHud.h
 *
 *  Created on: 21/06/2014
 *      Author: munhra
 */

#ifndef GAMEHUD_H_
#define GAMEHUD_H_

#include "cocos2d.h"
using namespace cocos2d;

class GameHud:public cocos2d::Layer{
public:
	GameHud();
	virtual ~GameHud();

	CCSprite* hud1;
	CCSprite* hud2;
	CCSprite* coin;

	CCSprite* inAppArmor;
	CCSprite* inAppAmmo;
	CCSprite* inAppGenereal;

	CCLabelTTF *labelCoinValue;
	CCLabelTTF *labelWave;
	CCLabelTTF *labelLevel;
	CCLabelTTF *labelWaveValue;
	CCLabelTTF *labelWaveTotal;
	CCLabelTTF *labelArmor;
	CCLabelTTF *labelArmorPercent;
	CCLabelTTF *labelWaveCleared;
	CCMenuItemImage * menuItem1;
	CCMenu * myMenu;
	CCMenuItemImage * menuItem2;
	CCMenu * myMenu2;
	CCLabelTTF *labelScore;

	CCScene *delegate;

	virtual void doWaveClearedAnimation();
	virtual void doLevelPresentation(int levelNumber);
	virtual void triggerRadioExplosion();
	virtual void pauseGame();


};

#endif /* GAMEHUD_H_ */
