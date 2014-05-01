#ifndef __MENUSCENE_SCENE_H__
#define __MENUSCENE_SCENE_H__

#include "cocos2d.h"
#include "cstring"
USING_NS_CC;
using namespace std;
class MenuScene : public cocos2d::CCLayer
{
private:
	float SceneBeginTime;

	static bool AnimationStart;
	static bool gameOver;
	static bool gameStart;
	static bool red;
	static bool blue;
	static const int BeginAnimationTag;
		// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	
    // there's no 'id' in cpp, so we recommend returning the class instance pointer

	void beginAnimation();
	void endAnimation();
	void menu();
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void menuChangeBlueScene(CCObject* pSender);
	void menuChangeRedScene(CCObject* pSender);

	//touch
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

	//重写生命周期函数
	virtual void onEnter();
	virtual void onExit();
public:
	static cocos2d::CCScene* scene();
	static void setMenuBlue(bool tf);
	static void setMenuRed(bool tf);

    // implement the "static node()" method manually
    CREATE_FUNC(MenuScene);
};

#endif // __MENUSCENE_SCENE_H__
