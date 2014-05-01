#ifndef __MUSICGAME_SCENE_H__
#define __MUSICGAME_SCENE_H__

#include "cocos2d.h"
#include "keyedit.h"
#include <vector>
#include <time.h>
#include "MusicLine.h"

USING_NS_CC;
using std::vector;
class MusicGame : public cocos2d::CCLayer
{
public:
	long SceneBeginTime;
	int currentScore;
	int overTag;
	CCLabelTTF *LabelScore;


	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);
	static long getCurrentTime();    

	//采集数据
	void GetData();

	// implement the "static node()" method manually
	CREATE_FUNC(MusicGame);

	void createSpecialKey(int positionX,int positionY,CCPoint moveTo);
	void createmykey(int positionX,int positionY);
	//重写生命周期函数

	virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
	virtual void ccTouchesMoved(CCSet *pTouches,CCEvent *pEvent);
	
	void menuChangeScene(CCObject* pSender);
private:
	CCSprite* m_pSprite;
	vector<keyedit*> m_pSpriteList;
	vector<MusicLine*> m_pLineList;

	void getdata();
	int KeyPositionX[2000];
	int KeyPositionY[2000];
	long KeyTime[2000];
	CCPoint specialKeyMoveToCCP[100];
	bool isSpecialKey[2000];
	void newUpdate(float dt);
};

#endif // __MUSICGAME_SCENE_H__
