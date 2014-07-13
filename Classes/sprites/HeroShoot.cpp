/*
 * HeroShoot.cpp
 *
 *  Created on: 13/07/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/sprites/HeroShoot.h"

HeroShoot::HeroShoot() {
	// TODO Auto-generated constructor stub

}

HeroShoot::~HeroShoot() {
	// TODO Auto-generated destructor stub
}

HeroShoot* HeroShoot::create(CCString* filename)
{
	HeroShoot *heroshoot = new HeroShoot();
	if (heroshoot && heroshoot->initWithFile(filename->getCString())) {
		heroshoot->removeObject = false;
		heroshoot->autorelease();
		return heroshoot;
	}
	CC_SAFE_DELETE(heroshoot);
	return NULL;
}

