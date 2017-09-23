#include"GameObject.h"
#include"../ObjectLayer.h"

bool GameObject::checkCollision(GameObject* pObj)
{
	return m_rctBoundBox.intersectsRect(pObj->getBoundBox());
}

void GameObject::addObject(GameObject* pObj)
{
	m_lsChilds.push_back(pObj);
	this->addChild(pObj);
}

ObjectLayer* GameObject::ms_pcObjectLayer = 0;

bool GameObject::init()
{
	m_bHostile = true;
	m_bIfDestroy = false;
	return true;
}
