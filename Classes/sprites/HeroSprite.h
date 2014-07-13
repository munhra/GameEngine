/*
 * HeroSprite.h
 *
 *  Created on: 21/06/2014
 *      Author: munhra
 */

#ifndef HEROSPRITE_H_
#define HEROSPRITE_H_

#include "cocos2d.h"
#include "sprites/HeroShoot.h"

using namespace cocos2d;

class HeroSprite: public CCSprite{
public:
	HeroSprite();
	virtual ~HeroSprite();


	//Vector<CCSprite*> activeShoots;
	Vector<HeroShoot*> activeShoots;


	// how many points left from the armor, this will be provided by the drummer type
	float heroArmor;

	// Time of weapon cooldown this can be varied for the band members,
	// lets 3 variables one for the guitar1, guitar2 and bass, this
	// configuration will came from the store.
	bool heroReleaseFire;

	bool isHeroDeath;

	CCParticleSystem *heroParticle;
	CCParticleSystem *heroParticleBlaster;

	float heroShootPower;

	int heroBlast;

	//Hero body and guitar anim/sprite
	CCAction *heroBodyAnim;
	CCSprite *heroBodySprite;
	CCAction *heroArmAnim;
	CCSprite *heroArmSprite;

	//Hero position attributes
	int hero_weaponLeftx;
	int hero_weaponRightx;
	int hero_weaponyRight;
	int hero_weaponyLeft;
	float hero_anchorRightX;
	float hero_anchorRightY;
	float hero_anchorLeftX;
	float hero_anchorLeftY;

	int heroCoins;
	static HeroSprite* create();
	virtual void performBandDeath();
	virtual void hitByEnemy(float damagePoints);
	virtual void hitByEnemy(float damagePoints, CCRect rect);
    virtual void performBandBlast();
    virtual void receiveHealthPowerUp(float value);
    virtual void runShootAnimation();
    virtual float getTotalArmor();

private:
    void createHeroBody();
    void createHeroArm();
    CCPoint calculateAnchorPoint(CCPoint anchorPos, CCPoint size);

};

#endif /* HEROSPRITE_H_ */
