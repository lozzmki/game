#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include<cocos2d.h>
class ObjectLayer;

class GameScene : public cocos2d::Scene {
public:
	CREATE_FUNC(GameScene);

private:
	cocos2d::Layer* m_pcBackground;
	cocos2d::Layer* m_pcTerrain;
	ObjectLayer* m_pcObjects;
};

#endif