#include "line.h"
#include"node.h"
#include <math.h>
USING_NS_CC;

line::line(void)
{
	positionX = 0;
	positionY = 0;
	color = 0;
}


line::~line(void)
{
}
line* line::create(node *p1,node *p2,int NumberOfLines)
{
	float p1X = p1->getPositionX();
	float p1Y = p1->getPositionY();
	float p2X = p2->getPositionX();
	float p2Y = p2->getPositionY();
	float lineX = (p1X+p2X)/2;
	float lineY = (p1Y+p2Y)/2;
	line *newline = new line(lineX,lineY,p1->tag,p2->tag,NumberOfLines);
	//取两点中间的位置为position，取放大倍数，
	CCSize lineSize ;
	float bigWidth = (p1X-p2X)*(p1X-p2X)+(p1Y-p2Y)*(p1Y-p2Y);
	float newLineWidth = sqrt(bigWidth);
	lineSize = newline->getContentSize();
	float newScaleX = newLineWidth/lineSize.width;
	newline->setScaleX(newScaleX); 
	//设置倾斜角度

	float newRotation = -(180/3.14)*acos((p2X-p1X)/newLineWidth);
	newline->setRotation(newRotation);
	return newline;
}

line::line(int positionX, int positionY,int beforeNodeTag,int currentNodeTag,int NumberOfLines)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->beforeNodeTag = beforeNodeTag;
	this->currentNodeTag = currentNodeTag;
	this->setPosition(ccp(positionX,positionY));
	if(NumberOfLines==0) this->initWithFile("line0.png");
	if(NumberOfLines==1) this->initWithFile("line1.png");
	if(NumberOfLines==2) this->initWithFile("line2.png");
	amount++;
	id = amount;
	tag = beforeNodeTag*100+currentNodeTag;
}
void line::LineChange(int NumberOfLines)
{	
	amount ++;
	CCAnimation* animation = CCAnimation::create();
	if(NumberOfLines==1)
		animation->addSpriteFrameWithFileName("line1.png");
	else if(NumberOfLines==0)
		animation->addSpriteFrameWithFileName("line0.png");
	else if(NumberOfLines == 2)
		animation->addSpriteFrameWithFileName("line2.png");
	animation->setDelayPerUnit(2.8f / 14.0f);//必须设置否则不会动态播放
	animation->setRestoreOriginalFrame(false);//是否回到第一帧
	animation->setLoops(1);//重复次数 （-1:无限循环）
	CCFiniteTimeAction * animate = CCAnimate::create(animation);
	this->runAction(animate);
}


