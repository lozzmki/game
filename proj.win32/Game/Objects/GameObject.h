#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include<list>
#include<cocos2d.h>
USING_NS_CC;

class ObjectLayer;

enum enumObjectType {
	OBJECT_TYPE_ENTITY,
	OBJECT_TYPE_PROJECTILE
};

class GameObject :public Sprite {
public:
	CREATE_FUNC(GameObject);

	bool checkCollision(GameObject*);
	void addObject(GameObject*);

	inline void setDestroy() { m_bIfDestroy = true; }
	inline void setBoundBox(Rect& rct) { m_rctBoundBox = rct; }
	inline const Rect& getBoundBox() { return m_rctBoundBox; }
	inline const enumObjectType getType() { return (enumObjectType)m_nType; }
	inline const bool isHostile() { return m_bHostile; }
	inline const bool ifDestroy() { return m_bIfDestroy; }

	static ObjectLayer* ms_pcObjectLayer;
protected:
	virtual bool init();
	Rect m_rctBoundBox;
	std::list<GameObject*> m_lsChilds;

	int m_nType;
	bool m_bHostile;
	bool m_bIfDestroy;
};

#endif
