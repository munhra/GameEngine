/*
 * GamePlayScene.h
 *
 *  Created on: 15/06/2014
 *      Author: munhra
 */

#ifndef GAMEPLAYSCENE_H_
#define GAMEPLAYSCENE_H_

#include "cocos2d.h"
#include "scenes/GameHud.h"
#include "sprites/HeroSprite.h"
using namespace cocos2d;

class GamePlayScene:public cocos2d::Layer {
public:
	GamePlayScene();
	virtual ~GamePlayScene();

	static Scene* createScene(int levelNumber, int waveNumber);
	static Scene* createScene();
	virtual bool init();
	virtual Scene* initWithHudAndLevel(GameHud *hud,int level, int wave);

	CREATE_FUNC(GamePlayScene);

	virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event *unused_event);
	virtual void onTouchesCancelled(const std::vector<Touch*>&touches, Event *unused_event);


	typedef enum {
		    GAME_STARTED,
		    WAVE_CLEARED,
		    LEVEL_CLEARED,
		    GAME_OVER,
		    GAME_PAUSED
		} GameState;

	CCPoint endTouch;
	HeroSprite *heroSprite;

    CCPoint beginTouch;
	//CCArray *activeEnemies;
	Vector<HeroShoot*> activeEnemies;


	float rotationAngle;
	bool moved;
	CCParticleSystem *heroParticle;
	int waveEnemiesLeft;
	int levelEnemiesLeft;
	GameState state;
	GameHud *hudLayer;
	static int levelNumber;
	static int waveNumber;
	int scoreCount;


private:
	void update(float dt);
	void initBandPositions();
	float getHeroRotationAngle();
	float convertRadToDegree(float angle);
	float convertDegreeToRad(float angle);
	CCPoint fireCirclePoint();
	void fireLaser(CCPoint touchEndPoint);
	void doEndFire(CCNode *node);
	bool shootCollidedToTarget();




};

#endif /* GAMEPLAYSCENE_H_ */
