#pragma once
#include "keyedit.h"
#include "cocos2d.h"
#include "MusicGameScene.h"

USING_NS_CC;

keyedit::keyedit(void)
{
}


keyedit::~keyedit(void)
{
}

keyedit::keyedit(long time,int positionX,int positionY,bool isSpecialKey)
{
	this->isSpecialKey = isSpecialKey;
	isClick = false;
	CCSize screenSize=CCDirector::sharedDirector()->getVisibleSize();
	createTime = time;
	this->PositionX = positionX;
	this->PositionY = positionY;
	this->setPosition(ccp(PositionX,PositionY));
	if(this->isSpecialKey)
	{
		this->initWithFile("key3.png");
		specialKeyBeginTime = MusicGame::getCurrentTime();
		isTouchGetSpecialKey = false;
	}	
	else
	{
		this->initWithFile("key.png");
	}
	
	keyAmount++;
}

void keyedit::keyRunAnimation(CCPoint moveTo)
{	

	CCActionInterval *rotation1 = CCRotateTo::create(0.6,90);
	CCActionInterval *rotation2 = CCRotateTo::create(1,180);
	CCActionInterval *rotation3 = CCRotateTo::create(0.5,90);
	if(this->isSpecialKey)
	{
		CCActionInterval *movoTo = CCMoveTo::create(0.7,moveTo);
		CCSequence* seq=CCSequence::create(rotation1,movoTo,rotation3,NULL);
		this->runAction(seq);
		this->specialAmount++;
	}
	else
	{
		this->runAction(rotation2);
	}
}
//��ͼƬ
void keyedit::Change()
{	
	CCAnimation* animation = CCAnimation::create();
	animation->addSpriteFrameWithFileName("key2.png");
	animation->setDelayPerUnit(2.8f / 14.0f);//�������÷��򲻻ᶯ̬����
	animation->setRestoreOriginalFrame(false);//�Ƿ�ص���һ֡
	animation->setLoops(1);//�ظ����� ��-1:����ѭ����
	CCFiniteTimeAction * animate = CCAnimate::create(animation);
	this->runAction(animate);
}