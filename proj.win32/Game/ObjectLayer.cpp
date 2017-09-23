#include "ObjectLayer.h"
#include "Objects/GameObject.h"
#include "Objects/Entity.h"
#include "Objects/Projectile.h"

bool ObjectLayer::init()
{
	GameObject::ms_pcObjectLayer = this;

	return true;
}

void ObjectLayer::update(float delta)
{
	m_pcPlayer->update(delta);

	for (auto it = m_lsEntities.begin(); it != m_lsEntities.end();) {
		auto _p = *it;
		_p->update(delta);
		if (_p->ifDestroy()) {
			_p->release();
			it = m_lsEntities.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto it = m_lsProjectiles.begin(); it != m_lsProjectiles.end();) {
		auto _p = *it;
		_p->update(delta);
		if (_p->ifDestroy()) {
			_p->release();
			it = m_lsProjectiles.erase(it);
		}
		else {
			++it;
		}
	}
	for (auto it = m_lsPlayerAttacks.begin(); it != m_lsPlayerAttacks.end();) {
		auto _p = *it;
		_p->update(delta);
		if (_p->ifDestroy()) {
			_p->release();
			it = m_lsPlayerAttacks.erase(it);
		}
		else {
			++it;
		}
	}

	//collision
	for (auto& _pEntity : m_lsEntities) {
		if (m_pcPlayer->checkCollision(_pEntity)) {
			//player encounters an entity, todo
		}
	}
	for (auto& _pProjectile : m_lsProjectiles) {
		if (m_pcPlayer->checkCollision(_pProjectile)) {
			//player got hit, todo
		}
	}
	for (auto& _pProjectile : m_lsPlayerAttacks) {
		for (auto& _pEntity : m_lsEntities) {
			if (_pEntity->checkCollision(_pProjectile)) {
				//an entity got hit, todo
			}
		}
	}

	//push back temp list
	for (auto& _p : m_lsTempList) {
		if (_p->getType() == OBJECT_TYPE_ENTITY) {
			CCASSERT(dynamic_cast<Entity*>(_p), "a non-entity with type entity.");
			m_lsEntities.push_back(dynamic_cast<Entity*>(_p));
		}
		else {
			CCASSERT(dynamic_cast<Projectile*>(_p), "a non-projectile with type projectile.");
			if (_p->isHostile()) {
				m_lsProjectiles.push_back(dynamic_cast<Projectile*>(_p));
			}
			else {
				m_lsPlayerAttacks.push_back(dynamic_cast<Projectile*>(_p));
			}
		}
	}
	m_lsTempList.clear();
}

void ObjectLayer::addGameObject(GameObject* pObj)
{
	m_lsTempList.push_back(pObj);
	pObj->retain();
}
