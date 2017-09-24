#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<cocos2d.h>

class Player :public cocos2d::Sprite {
public:
	static Player* create(const std::string& sPath);

	virtual bool init();
	virtual void update(float delta);

	void jump();

	bool m_bMoveLeft;
	bool m_bMoveRight;
private:
	
	bool m_bFloored;
};

#endif