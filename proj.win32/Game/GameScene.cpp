#include "GameScene.h"
USING_NS_CC;

bool GameScene::init()
{
	m_pcTerrain = TMXTiledMap::create("2DGameMap.tmx");
	this->addChild(m_pcTerrain);

	return true;
}
