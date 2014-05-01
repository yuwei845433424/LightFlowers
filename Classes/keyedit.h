#pragma once
#include <time.h>
#include"cocos2d.h"

USING_NS_CC;
 class keyedit: public cocos2d::CCSprite
{
public:
	keyedit(void);
	~keyedit(void);
	keyedit(long time,int positionX,int positionY,bool isSpecialKey=false);
	
	static int keyAmount;

	//Ϊ����㽨����һϵ������
	bool isSpecialKey;
	static int specialAmount;	
	
	long specialKeyBeginTime;
	int specialKeyDuration;
	//����Ƿ񱻵������specialKey�ɹ����϶�
	bool isTouchGetSpecialKey;
	bool isClick;
	//��¼�����ʱ��
	long createTime;
	long endTime;
	//����λ��
	int PositionX;
	int PositionY;
	void keyRunAnimation(CCPoint moveTo = ccp(0,0));
	void Change();
};


