#ifndef __DENGLU_SCENE_H__
#define __DENGLU_SCENE_H__
#include "cocos2d.h"
#include "node.h"
#include "line.h"
#include<vector>
using std::vector;
USING_NS_CC;
class DrawMovie : public cocos2d::CCLayer
{
private:
	vector<node*> m_pNodeList; 
	vector<line*> m_pLineList;
	CCMotionStreak* strike;

	void initNodes();
	int DealNodeAndGetTag(node *Node);
	void newUpdate(float f);
	bool gameStart ;
	void lineRespond(node *sprite,int NumberOfLines);
	//响应触屏动作
	//重写触屏回调函数
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	//重写生命周期函数
	virtual void onEnter();
	virtual void onExit();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	
	//menu
	void menuReInit(CCObject* pSender);
	void menuGuess1(CCObject* pSender);
	void menuGuess2(CCObject* pSender);
	void menuChangeScene(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
public:
	
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// implement the "static node()" method manually
	CREATE_FUNC(DrawMovie);
};

#endif // __DrawMovie_SCENE_H__
