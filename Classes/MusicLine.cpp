#include "MusicLine.h"
#include "keyedit.h"
#include <math.h>
USING_NS_CC;

long getCurrentTime()    
{     
	struct cc_timeval tv;     
	CCTime::gettimeofdayCocos2d(&tv, NULL);  
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;     
}  
MusicLine::MusicLine(void)
{
	PositionX = 0;
	PositionY = 0;
	color = 0;
}


MusicLine::~MusicLine(void)
{
}
MusicLine* MusicLine::create(CCPoint p1,CCPoint moveTo,int color)
{
	float p1X = p1.x;
	float p1Y = p1.y;
	float p2X = moveTo.x;
	float p2Y = moveTo.y;
	if(p1Y<p2Y)
	{
		float c = p1X;
		p1X = p2X;
		p2X = c;
	}
	float lineX = (p1X+p2X)/2;
	float lineY = (p1Y+p2Y)/2;
	MusicLine *newline = new MusicLine(lineX,lineY,color);
	//取两点中间的位置为position，取放大倍数，
	CCSize lineSize ;
	float bigWidth = (p1X-p2X)*(p1X-p2X)+(p1Y-p2Y)*(p1Y-p2Y);
	float newLineWidth = sqrt(bigWidth);
	lineSize = newline->getContentSize();
	float newScaleX = newLineWidth/lineSize.width;
	newline->setScaleX(newScaleX); 
	//设置倾斜角度
	float newRotation = (180/3.14)*acos((p2X-p1X)/newLineWidth);
	newline->setRotation(newRotation);
	return newline;
}

MusicLine::MusicLine(int PositionX, int PositionY,int color)
{
	this->createTime = getCurrentTime();
	this->PositionX = PositionX;
	this->PositionY = PositionY;

	this->setPosition(ccp(PositionX,PositionY));
	if(color==0) this->initWithFile("MusicLine0.png");
	if(color==1) this->initWithFile("line1.png");
	if(color==2) this->initWithFile("line2.png");

}
void MusicLine::LineChange(int color)
{
	CCAnimation* animation = CCAnimation::create();
	if(color==1)
		animation->addSpriteFrameWithFileName("line1.png");
	else if(color==0)
		animation->addSpriteFrameWithFileName("line0.png");
	else if(color == 2)
		animation->addSpriteFrameWithFileName("line2.png");
	animation->setDelayPerUnit(2.8f / 14.0f);//必须设置否则不会动态播放
	animation->setRestoreOriginalFrame(false);//是否回到第一帧
	animation->setLoops(1);//重复次数 （-1:无限循环）
	CCFiniteTimeAction * animate = CCAnimate::create(animation);
	this->runAction(animate);
}

void MusicLine::blink()
{
}
