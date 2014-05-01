#pragma once
#include<time.h>
#include"cocos2d.h"
#include "keyedit.h"
class MusicLine: public cocos2d::CCSprite
{
public:
	//属性
	float createTime;
	int id;
	int color;
	//带参数的构造函数完成了坐标的确定、图片的选取、amount自加、id、tag复制
	MusicLine(int PositionX, int PositionY,int color);
	MusicLine(void);
	~MusicLine(void);
	void blink();
	static MusicLine *create(CCPoint p1,CCPoint moveTo,int color = 0);
	//根据color 的值换图片
	void LineChange(int color);
private:
	int PositionX;
	int PositionY;

	

	
};


