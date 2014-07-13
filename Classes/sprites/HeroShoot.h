/*
 * HeroShoot.h
 *
 *  Created on: 13/07/2014
 *      Author: munhra
 */

#ifndef HEROSHOOT_H_
#define HEROSHOOT_H_

#include "cocos2d.h"
using namespace cocos2d;

class HeroShoot :  public CCSprite{
public:

	bool removeObject;

	HeroShoot();
	virtual ~HeroShoot();
	static HeroShoot* create(CCString* filename);
};

#endif /* HEROSHOOT_H_ */
