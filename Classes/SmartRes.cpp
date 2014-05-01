#include "SmartRes.h"

SmartRes* SmartRes::s_sharedRes = NULL;

SmartRes* SmartRes::sharedRes(void)
{
    if (!s_sharedRes)
    {
        s_sharedRes = new SmartRes();
        s_sharedRes->init();
    }
    return s_sharedRes;
}

bool SmartRes::init(void)
{
    //const CCSize& winSizeInPixels = CCDirector::sharedDirector()->getWinSizeInPixels();
    //setVirtualScreenWidth(winSizeInPixels.width);
    return true;
}

void SmartRes::setVirtualScreen(float width,float height)
{
    // ľ���ҵ� 2.0 ������ô��ȡ�豸���򡣡����Լٶ��Ǻ�����
    const CCSize& winSizeInPixels = CCDirector::sharedDirector()->getWinSizeInPixels();

    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(width,
        height, kResolutionFixedWidth);

    CCLOG("Virtual width: %0.2f, Virtual height: %0.2f, scale: %0.2f",
        m_screenSize.width, m_screenSize.height, m_scale);

    const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();
    m_center.x = winSize.width / 2;
    m_center.y = winSize.height / 2;
    m_left = 0;
    m_right = m_screenSize.width - 1;
    m_top = m_screenSize.height - 1;
    m_bottom = 0;

    CCLOG("center x: %0.2f, center y: %0.2f", m_center.x, m_center.y);
    CCLOG("top: %0.2f, right: %0.2f, bottom: %0.2f, left: %0.2f", m_top, m_right, m_bottom, m_left);
}
