#include "MenuScene.h"
#include"DrawMovieScene.h"
#include"MusicGameScene.h"
#include<cstring> 
USING_NS_CC;

bool MenuScene::AnimationStart = true;
bool MenuScene::gameOver = false;
bool MenuScene::gameStart = true;
bool MenuScene::red = false;
bool MenuScene::blue = false;
const int MenuScene::BeginAnimationTag = 1;
CCScene* MenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MenuScene *layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(MenuScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
	    
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 1);


    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    

    //beginAnimation
	SceneBeginTime = MusicGame::getCurrentTime();

	if(AnimationStart)
	{
		beginAnimation();
	}
	else
	{
		menu();
	}

	//menuCreate
    return true;
}
bool MenuScene::ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
	return true;
}
void MenuScene::ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
}
void MenuScene::ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event)
{
	long currentTime = MusicGame::getCurrentTime();
	if(currentTime-SceneBeginTime>3000&&AnimationStart)
	{
		AnimationStart = false;
		CCSprite *Animation = (CCSprite *)MenuScene::getChildByTag(BeginAnimationTag);
		Animation->removeFromParentAndCleanup(true);
		menu();
	}
	if(currentTime-SceneBeginTime>1000&&red&&blue&&gameOver)
	{
		endAnimation();
		gameOver = false;
	}
}

void MenuScene::menu()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* pBackGround = CCSprite::create("0Flower.png");
	pBackGround->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pBackGround, 0);

	CCMenuItemImage *pBlueItem = CCMenuItemImage::create(
										"whiteBlue.png",
										"whiteBlue.png",
										this,
										menu_selector(MenuScene::menuChangeBlueScene));
	pBlueItem->setPosition(ccp(336,262));
		
	CCMenuItemImage *pRedItem = CCMenuItemImage::create(
										"whiteRed.png",
										"whiteRed.png",
										this,
										menu_selector(MenuScene::menuChangeRedScene));
	pRedItem->setPosition(ccp(350,182));
	CCMenu *pBlueMenu = CCMenu::create(pBlueItem,NULL);
	pBlueMenu->setPosition(CCPointZero);
	addChild(pBlueMenu,1);
	CCMenu *pRedMenu = CCMenu::create(pRedItem,NULL);
	pRedMenu->setPosition(CCPointZero);
	addChild(pRedMenu,1);

	if(blue&&red)
	{
		gameOver = true;
	}

	if(blue)
	{
		CCSprite* pBlue = CCSprite::create("blueFlower.png");
		pBlue->setPosition(ccp(336,258));
		addChild(pBlue,1);
		pBlueMenu->removeFromParentAndCleanup(true);
	}
	if(red)
	{
		CCSprite* pRed = CCSprite::create("redFlower.png");
		pRed->setPosition(ccp(350,182));
		addChild(pRed,1);
		pRedMenu->removeFromParentAndCleanup(true); 
	}

}

void MenuScene::beginAnimation()
{
	CCSprite* sp = CCSprite::create("0.png");
	sp->setPosition(ccp(240,160));
		
	addChild(sp,0,BeginAnimationTag);
	CCAnimation* animation = CCAnimation::create();
	animation->addSpriteFrameWithFileName("0.png");
	animation->addSpriteFrameWithFileName("01.png");
	animation->addSpriteFrameWithFileName("02.png");
	animation->addSpriteFrameWithFileName("03.png");
	animation->addSpriteFrameWithFileName("04.png");

	animation->addSpriteFrameWithFileName("03.png");
	animation->addSpriteFrameWithFileName("02.png");
	animation->addSpriteFrameWithFileName("01.png");
	animation->addSpriteFrameWithFileName("0.png");
		
	animation->setDelayPerUnit(3.8f / 14.0f);//必须设置否则不会动态播放
	animation->setRestoreOriginalFrame(false);//是否回到第一帧
	animation->setLoops(1);//重复次数 （-1:无限循环）
		
	CCFiniteTimeAction * animate = CCAnimate::create(animation);
	sp->runAction(animate);

}
void MenuScene::endAnimation()
{
	CCSprite *sp = CCSprite::create("end1.png");
	sp->setPosition(ccp(240,160));
	addChild(sp,1);
	CCAnimation* animation = CCAnimation::create();
	animation->addSpriteFrameWithFileName("0.png");
	animation->addSpriteFrameWithFileName("01.png");
	animation->addSpriteFrameWithFileName("02.png");
	animation->addSpriteFrameWithFileName("03.png");
	animation->addSpriteFrameWithFileName("04.png");
	
	animation->addSpriteFrameWithFileName("end1.png");
	animation->addSpriteFrameWithFileName("end1.png");
	animation->addSpriteFrameWithFileName("end2.png");
	animation->addSpriteFrameWithFileName("end2.png");
	animation->addSpriteFrameWithFileName("end2.png");
	animation->addSpriteFrameWithFileName("end3.png");
	animation->addSpriteFrameWithFileName("end3.png");
	animation->addSpriteFrameWithFileName("end3.png");
	animation->addSpriteFrameWithFileName("end4.png");
	animation->addSpriteFrameWithFileName("end4.png");
	animation->addSpriteFrameWithFileName("end5.png");
	animation->setDelayPerUnit(3.8f / 14.0f);//必须设置否则不会动态播放
	animation->setRestoreOriginalFrame(false);//是否回到第一帧
	animation->setLoops(1);//重复次数 （-1:无限循环）
		
	CCFiniteTimeAction * animate = CCAnimate::create(animation);
	sp->runAction(animate);
	
}
void MenuScene::menuChangeBlueScene(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* pLayer =DrawMovie::create();//得到注册界面布景层
	scene->addChild(pLayer);
	/*设置登录场景切换动画*/
	CCTransitionScene* DrawMovieScene = CCTransitionPageTurn::create(2,scene,false);//替换场景
	CCDirector::sharedDirector()->replaceScene(DrawMovieScene);
}
void MenuScene::menuChangeRedScene(CCObject* pSender)
{
	CCScene* scene = CCScene::create();
	CCLayer* pLayer =MusicGame::create();//得到注册界面布景层
	scene->addChild(pLayer);
	/*设置登录场景切换动画*/
	CCTransitionScene* MusicGameScene = CCTransitionPageTurn::create(2,scene,false);//替换场景
	CCDirector::sharedDirector()->replaceScene(MusicGameScene);
}
void MenuScene::setMenuBlue(bool tf)
{
	blue = tf;
}
void MenuScene::setMenuRed(bool tf)
{
	red = tf;
}
void MenuScene::onEnter()
{

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}

void MenuScene::onExit()
{
	
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}
void MenuScene::menuCloseCallback(CCObject* pSender)
{

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
