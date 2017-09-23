#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include<cocos2d.h>
#include<map>

//one tile
struct DTileData {
	bool m_bIsCollidable;
	std::string m_s
};

class Terrain :public cocos2d::Object {
public:
	CREATE_FUNC(Terrain);

	virtual bool init();

	static std::map<int, DTileData> ms_mapTileData;
private:
};

#endif