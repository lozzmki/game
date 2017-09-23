#ifndef __OBJECTLAYER_H__
#define __OBJECTLAYER_H__

#include<cocos2d.h>
#include<list>

class GameObject;
class Entity;
class Projectile;

class ObjectLayer :public cocos2d::Layer {
public:
	CREATE_FUNC(ObjectLayer);

	virtual bool init();
	virtual void update(float delta);

	void addGameObject(GameObject* pObj);

	inline Entity* getPlayer() { return m_pcPlayer; }
private:
	std::list<Entity*> m_lsEntities;
	std::list<Projectile*> m_lsProjectiles;
	Entity* m_pcPlayer;
	std::list<Projectile*> m_lsPlayerAttacks;
	std::list<GameObject*> m_lsTempList;
};

#endif