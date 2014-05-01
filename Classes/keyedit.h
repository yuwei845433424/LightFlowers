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

	//为特殊点建立的一系列属性
	bool isSpecialKey;
	static int specialAmount;	
	
	long specialKeyBeginTime;
	int specialKeyDuration;
	//检测是否被点击或者specialKey成功被拖动
	bool isTouchGetSpecialKey;
	bool isClick;
	//记录生存的时间
	long createTime;
	long endTime;
	//坐标位置
	int PositionX;
	int PositionY;
	void keyRunAnimation(CCPoint moveTo = ccp(0,0));
	void Change();
};


