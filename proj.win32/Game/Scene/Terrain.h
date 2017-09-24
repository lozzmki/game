#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include<cocos2d.h>
#include<map>

//one tile
struct DTileData {
	bool m_bIsCollidable;
	std::string m_sTextureName;
};

class Terrain : public cocos2d::Node{
public:
	static Terrain* createTerrain(std::string sPath);

	const DTileData& getTile(cocos2d::Vec2);

	static std::map<int, DTileData> ms_mapTileData;
private:

	char * m_arrMapData;
	cocos2d::Size m_vSize;
	cocos2d::Size m_vTileSize;
};

#endif