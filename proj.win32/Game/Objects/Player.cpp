#include "Player.h"
USING_NS_CC;

const double PLAYER_MOVE_SPEED = 100.0;
const double PLAYER_JUMP_SPEED = 200.0;

Player* Player::create(const std::string& sPath)
{
	Player* _pReturn = new(std::nothrow) Player();
	if (_pReturn->initWithFile(sPath) && _pReturn->init()) {
		return _pReturn;
	}
	else {
		delete _pReturn;
		_pReturn = nullptr;
	}
}

bool Player::init()
{
	this->scheduleUpdate();

	return true;
}

void Player::update(float delta)
{
	//check if floored
	if (fabs(this->getPhysicsBody()->getVelocity().y) < 1e-4)
		m_bFloored = true;
	else
		m_bFloored = false;

	//moving
	if (m_bMoveLeft) {
		if (!m_bMoveRight) {
			this->getPhysicsBody()->setVelocity(Vec2(-PLAYER_MOVE_SPEED, this->getPhysicsBody()->getVelocity().y));
		}else
			this->getPhysicsBody()->setVelocity(Vec2(0.0, this->getPhysicsBody()->getVelocity().y));
	}
	else if (m_bMoveRight) {
		this->getPhysicsBody()->setVelocity(Vec2(PLAYER_MOVE_SPEED, this->getPhysicsBody()->getVelocity().y));
	}
	else {
		this->getPhysicsBody()->setVelocity(Vec2(0.0, this->getPhysicsBody()->getVelocity().y));
	}
}

void Player::jump()
{
	if (m_bFloored) {
		this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity() + Vec2(0.0, PLAYER_JUMP_SPEED));
	}
}
