#ifndef __ENTITY_H__
#define __ENTITY_H__

#include"GameObject.h"

class Entity :public GameObject {
public:
	CREATE_FUNC(Entity);

protected:
	virtual bool init();

};

#endif