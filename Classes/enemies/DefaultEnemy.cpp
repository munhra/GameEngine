/*
 * DefaultEnemy.cpp
 *
 *  Created on: 14/07/2014
 *      Author: munhra
 */

#include "/Users/munhra/MunhraGames/MyGame/Classes/enemies/DefaultEnemy.h"
#include "/Users/munhra/MunhraGames/MyGame/Classes/enemies/EnemyParams.h"

DefaultEnemy::DefaultEnemy() {
	// TODO Auto-generated constructor stub

}

DefaultEnemy::~DefaultEnemy() {
	// TODO Auto-generated destructor stub
}


DefaultEnemy* DefaultEnemy::createWithStartPosition(CCPoint position, double actionTime,
		CCNode *scnDelegate, EnemyParams *params, EnemyPositions defPositions, CCPoint shootEnd)
{
	DefaultEnemy *defaultEnemy = new DefaultEnemy();
	if (defaultEnemy && defaultEnemy->init()) {

		this->shootPosition = shootEnd;
		this->initialPosition = position;

		this->armor = params->armor;
		this->weaponDamage = params->weaponDamage;
		this->scorePoints = params->scorePoints;
		this->timeToReach = params->timeToReach;
		this->typeOfPowerUp = params->typeOfPowerUp;
		this->name = params->enemyName;
		this->frames = params->numberOfFrames;
		this->definedPosition = defPositions;
		this->attackType = params->atackType;


		Vector<SpriteFrame*>animFrames;
		Vector<SpriteFrame*>attackFrames;

		this->enemySprite = CCSprite::create();

		if ((defPositions == POS8) || (defPositions == POS7) || (defPositions == POS1)){
			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_back_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}
			if (defPositions == POS7) {
				this->enemySprite->setFlipX(true);
			}

		}else if ((defPositions == POS3) || (defPositions == POS4) || (defPositions == POS5)) {

			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_front_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}

		}else{
			for(int i = 1; i <= this->frames; i++) {
				CCString *frameName = CCString::createWithFormat("%s_left_%d",this->name,i);
				CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
						frameName->getCString());
				divideAnimations(frame,animFrames,attackFrames,i);
			}
			this->enemySprite->setFlipX(true);
			if (defPositions == POS2) {
				this->enemySprite->setFlipX(false);
			}
		}

        enemySprite->setScaleX(0.50);
        enemySprite->setScaleY(0.50);

        CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames,0.09f);
        CCAnimation *attackAnimation = CCAnimation::createWithSpriteFrames(attackFrames,0.2f);

        this->enemySprite->setPosition(position);
        // restore original frame ?
        this->enemyAction = CCRepeatForever::create(CCAnimate::create(animation));


        CCAnimate *attackAnim = CCAnimate::create(attackAnimation);
        CCFiniteTimeAction *endAnimationCallback = CCCallFuncN::create(CC_CALLBACK_1(DefaultEnemy::doEndAttackAnim, this));
        this->enemyAttack = CCSequence::create(attackAnim,endAnimationCallback,NULL);


        this->enemySprite->runAction(this->enemyAction);

        this->delegate = scnDelegate;


         //[[CCScheduler sharedScheduler] scheduleSelector:@selector(startMovement:) forTarget:self interval:time paused:NO];

		return defaultEnemy;
	}
	CC_SAFE_DELETE(defaultEnemy);
	return NULL;


	/*
	 *   self = [super init];
    if(self) {
        self.activeShoots = [[[NSMutableArray alloc] init] autorelease];
        self.shootPosition = shootEnd;
        self.initialPosition = position;
        self.armor = params.armor;
        self.weaponDamage = params.weaponDamage;
        self.scorePoints = params.scorePoints;
        self.timeToReach = params.timeToReach;
        self.typeOfPowerUp = params.typeOfPowerUp;
        self.name = params.enemyName;
        self.frames = params.numberOfFrames;
        self.definedPosition = defPosition;
        self.attackType = params.atackType;

        NSMutableArray *animFrames = [[[NSMutableArray alloc] init] autorelease];
        NSMutableArray *attackFrames =[[[NSMutableArray alloc] init] autorelease];

        self.enemySprite = [[CCSprite alloc] init];

        if (([[self name] isEqualToString:@"divorced_woman"] == YES) || ([[self name] isEqualToString:@"Dog"] == YES) ||
            ([[self name] isEqualToString:@"Fat_Cat"] == YES) || ([[self name] isEqualToString:@"skate_guy"] == YES)
            || ([[self name] isEqualToString:@"The_Gardener"] == YES)) {
            if ((defPosition == POS8) || (defPosition == POS7) || (defPosition == POS1)){
                for(int i = 1; i <= [self frames]; i++) {
                    NSString *frameName = [[self name] stringByAppendingString:@"_back_%d.png"];
                    CCSpriteFrame *frame = [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:[NSString stringWithFormat:frameName,i]];
                    [self divideAnimations:frame animFrames:animFrames attackFrames:attackFrames frameidx:i];
                }
                if (defPosition == POS7) {
                    self.enemySprite.flipX = YES;
                }
            }else if ((defPosition == POS3) || (defPosition == POS4) || (defPosition == POS5)) {
                for(int i = 1; i <= [self frames]; i++) {
                    NSString *frameName = [[self name] stringByAppendingString:@"_front_%d.png"];
                    CCSpriteFrame *frame = [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:[NSString stringWithFormat:frameName,i]];
                    //[animFrames addObject:frame];
                    [self divideAnimations:frame animFrames:animFrames attackFrames:attackFrames frameidx:i];
                }
            }else{
                for(int i = 1; i <= [self frames]; i++) {
                    NSString *frameName = [[self name] stringByAppendingString:@"_left_%d.png"];
                    CCSpriteFrame *frame = [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:[NSString stringWithFormat:frameName,i]];
                    //[animFrames addObject:frame];
                    [self divideAnimations:frame animFrames:animFrames attackFrames:attackFrames frameidx:i];
                }
                self.enemySprite.flipX = YES;
                if (defPosition == POS2) {
                    self.enemySprite.flipX = NO;
                }
            }

            enemySprite.scaleX = 0.50;
            enemySprite.scaleY = 0.50;

        }else {
            for(int i = 1; i <= [self frames]; i++) {
                NSString *frameName = [[self name] stringByAppendingString:@"%d.png"];
                CCSpriteFrame *frame = [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:[NSString stringWithFormat:frameName,i]];
                [animFrames addObject:frame];
            }
            enemySprite.scaleX = 0.75;
            enemySprite.scaleY = 0.75;


        }

        CCAnimation *animation = [CCAnimation animationWithFrames:animFrames delay:0.09f];
        CCAnimation *attackAnimation = [CCAnimation animationWithFrames:attackFrames delay:0.2f];

        self.enemySprite.position = position;
        self.enemyAction = [[CCRepeatForever actionWithAction:
                                [CCAnimate actionWithAnimation:animation restoreOriginalFrame:NO]] retain];

        //self.enemyAttack = [[CCRepeatForever actionWithAction:
        //                     [CCAnimate actionWithAnimation:attackAnimation restoreOriginalFrame:NO]] retain];


        id attackAnim = [CCAnimate actionWithAnimation: attackAnimation];
        id endAnimationCallback = [CCCallFuncN actionWithTarget:self selector: @selector(doEndAttackAnim:)];
        self.enemyAttack = [CCSequence actions: attackAnim, endAnimationCallback, nil];

        // include here the attackAction animation with the previous selected frames

        [[self enemySprite] runAction:[self enemyAction]];

        self.delegate = scnDelegate;
        [[CCScheduler sharedScheduler] scheduleSelector:@selector(startMovement:) forTarget:self interval:time paused:NO];
    }
    return self;
	 *
	 */


}

void DefaultEnemy::divideAnimations(CCSpriteFrame *frame, Vector<SpriteFrame*> animFrames,
		Vector<SpriteFrame*> attackFrames, int frameidx){

	switch(frameidx){
	case 1:
		animFrames.pushBack(frame);
		break;
	case 3:
		animFrames.pushBack(frame);
		attackFrames.pushBack(frame);
		break;
	case 4:
		attackFrames.pushBack(frame);
		break;
	default:
		break;
	}
}

void DefaultEnemy::performDeath()
{

}

void DefaultEnemy::startMovement(CCTimer* dt)
{

}

void DefaultEnemy::doEndGenHitAnim(CCNode *node)
{

}

void DefaultEnemy::doEndAttackAnim(CCNode *node)
{

}

void DefaultEnemy::fireWeapon(CCTimer *dt)
{

}

void DefaultEnemy::doEndRobotFire(CCNode* node)
{

}

void DefaultEnemy::doEndDeathAnimation(CCNode *node)
{

}

int DefaultEnemy::receiveHeroShoot(float damage, bool killNow, CCRect shootRect)
{

}

float DefaultEnemy::autoDestruction()
{

}

